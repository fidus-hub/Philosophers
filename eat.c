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
        philos->is_eating = 1;
        philos->number_of_eat++;
        if (philos->number_of_eat == philos->threads->number_of_time_2_eat)
            philos->threads->eat_counter++;
        usleep(philos->threads->time_2_sleep * 1000);
        pthread_mutex_unlock(&philos->threads->forks[philos->lfork]);
        pthread_mutex_unlock(&philos->threads->forks[philos->rfork]);
        pthread_mutex_unlock(&philos->eat);
        philos->is_eating = 0;

    }