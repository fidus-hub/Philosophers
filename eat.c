/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:56:11 by mgrissen          #+#    #+#             */
/*   Updated: 2022/03/02 17:09:24 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philos *philos)
{
	unsigned long long	time;

	pthread_mutex_lock(&philos->threads->forks[philos->lfork]);
	display("taking lfork", philos);
	pthread_mutex_lock(&philos->threads->forks[philos->rfork]);
	display("taking rfork", philos);
	pthread_mutex_lock(&philos->eat);
	display("is eating", philos);
	philos->last_time_2_eat = get_time();
	philos->is_eating = 1;
	philos->number_of_eat++;
	if (philos->number_of_eat == philos->threads->number_of_time_2_eat)
		philos->threads->eat_counter++;
	time = get_time();
	usleep(philos->threads->time_2_eat * 1000 - 10000);
	while (get_time() - time < (unsigned long long) philos->threads->time_2_eat)
		continue ;
	pthread_mutex_unlock(&philos->threads->forks[philos->lfork]);
	pthread_mutex_unlock(&philos->threads->forks[philos->rfork]);
	pthread_mutex_unlock(&philos->eat);
	philos->is_eating = 0;
}
