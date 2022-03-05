/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:56:22 by mgrissen          #+#    #+#             */
/*   Updated: 2022/03/05 12:56:40 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *threadStruct)
{
	t_philos	*philos;

	philos = (t_philos *)threadStruct;
	while (philos->threads->is_dead == 0)
	{
		think(philos);
		eat(philos);
		sleeping(philos);
		usleep(100);
	}
	return (NULL);
}

void	create_threads(t_threads *threads, t_philos *philos)
{
	pthread_t	t_id;
	int			i;

	i = 0;
	threads->time = get_time();
	while (i < threads->philo_numbr)
	{
		threads->philosopher[i].last_time_2_eat = get_time();
		pthread_create(&t_id, NULL, &routine, &philos[i]);
		usleep(100);
		i++;
	}
}

t_philos	*init_philos(t_threads *threads)
{
	int			i;
	t_philos	*philosopher;

	i = 0;
	philosopher = malloc(sizeof(t_philos) * threads->philo_numbr);
	while (i < threads->philo_numbr)
	{
		philosopher[i].id = i + 1;
		philosopher[i].last_time_2_eat = 0;
		philosopher[i].number_of_eat = 0;
		philosopher[i].rfork = (i + 1) % threads->philo_numbr;
		philosopher[i].lfork = i;
		philosopher[i].is_eating = 0;
		pthread_mutex_init(&philosopher[i].eat, NULL);
		philosopher[i].threads = threads;
		i++;
	}
	return (philosopher);
}

void	init_mutex(t_threads *threads)
{
	int	i;

	i = 0;
	pthread_mutex_init(&threads->write, NULL);
	threads->forks = malloc(sizeof(pthread_mutex_t) * threads->philo_numbr);
	while (i < threads->philo_numbr)
	{
		pthread_mutex_init(&threads->forks[i], NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_threads	threads;
	t_philos	*philos;

	ft_parser(argc, argv, &threads);
	if (threads.philo_numbr == 0)
		return (0);
	philos = init_philos(&threads);
	threads.philosopher = philos;
	init_mutex(&threads);
	create_threads(&threads, philos);
	supervisor(&threads);
}
