#include "philo.h"

void	sleeping(t_philos *philos)
{
	display("is sleeping", philos);
    usleep(philos->threads->time_2_sleep * 1000);
}