#include "philo.h"

void* routine(void *threadStruct)
{
	t_philos *threads;

	threads = (t_philos *)threadStruct;
	/*while (threads->is_dead == 0)
	{
		think(threads);
		eat(threads);
		sleep(threads);
	}*/
	printf("this philo %d , is alive \n", threads->philo_id);
	return(NULL);
}

void create_threads(t_threads *threads, t_philos *philos)
{
	int i;
	i = 0;

	while (i < threads->philo_numbr)
	{
		pthread_create(&(philos[i].threads), NULL, &routine, &philos[i]);
		usleep(100);
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
	philos = malloc(sizeof(t_philos) *(threads.philo_numbr));
	int		i = 0;
	while (i < threads.philo_numbr)
	{
		philos[i].philo_id = i;
		i++;
	}
	create_threads(&threads, philos);
	while(1);
}