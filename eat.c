#include "philo.c"

void	eat(t_philos *philos)
    {
        pthread_mutex_lock(&philos->threads->forks[philos->lfork]);
	    display("taking lfork", philos);
	    pthread_mutex_lock(&philos->threads->forks[philos->rfork]);
	    display("taking rfork", philos);
	    pthread_mutex_lock(&philos->eat);
	    display("is eating", philos);
        philos->last_time_2_eat = get_time();
        usleep(philos->threads->time_2_sleep * 1000);
        pthread_mutex_unlock(&philos->threads->forks[philos->lfork]);
        pthread_mutex_unlock(&philos->threads->forks[philos->rfork]);
        pthread_mutex_unlock(&philos->eat);

    }