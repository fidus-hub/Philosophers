#include "philo.h"

void	sleeping(t_philos *philos)
{
    unsigned long long time;

	display("is sleeping", philos);
    time = get_time();
    usleep(philos->threads->time_2_sleep * 1000 - 10000);
    while (get_time() - time < (unsigned long long) philos->threads->time_2_sleep)
        continue;
}