/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrissen <mgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:56:30 by mgrissen          #+#    #+#             */
/*   Updated: 2022/03/02 17:36:25 by mgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_philos *philos)
{
	unsigned long long	time;

	display("is sleeping", philos);
	time = get_time();
	usleep(philos->threads->time_2_sleep * 1000 - 10000);
	while (get_time() - time
		< (unsigned long long) philos->threads->time_2_sleep)
		continue ;
}
