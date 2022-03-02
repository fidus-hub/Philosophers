/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:56:20 by mgrissen          #+#    #+#             */
/*   Updated: 2022/03/02 17:24:59 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				sign;
	size_t			r;

	i = 0;
	sign = 1;
	r = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = ((r * 10) + str[i] - '0');
		i++;
		if (r > 4294967295 && sign == 1)
			return (-1);
		if (sign == -1 && r > 4294967295)
			return (0);
	}
	return (r * sign);
}

unsigned long long	get_time(void)
{
	unsigned long long	mili_sec;
	struct timeval		current_time;

	gettimeofday(&current_time, NULL);
	mili_sec = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (mili_sec);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n - 1 && (s1[i] || s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	display(char *msg, t_philos *philo)
{
	unsigned long long	time;

	pthread_mutex_lock(&(philo->threads->write));
	time = get_time() - philo->threads->time;
	printf("%llu philosopher %d ", time, philo->id);
	printf("%s\n", msg);
	if (ft_strncmp(msg, "died", 5))
		pthread_mutex_unlock(&philo->threads->write);
}

void	supervisor(t_threads *threads)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < threads->philo_numbr)
		{
			if ((get_time() >= ((unsigned long long)threads->time_2_die
						+ threads->philosopher[i].last_time_2_eat))
				&& threads->philosopher[i].is_eating == 0)
			{
				display("died", &threads->philosopher[i]);
				threads->is_dead = 1;
				return ;
			}
			if (threads->eat_counter == threads->philo_numbr)
				return ;
		}
		usleep(100);
	}
}
