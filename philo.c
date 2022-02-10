#include "philo.h"

void *routine(void *threadStruct)
{
	t_threads *threads = (t_threads *)threadStruct;
	while (threads->is_dead == 0)
	{
		
	}
}

void create_threads(t_threads *threads, pthread_t *philos)
{
	int i;
	i = 0;

	while (i < threads->philo_numbr)
	{
		pthread_create(philos[i], NULL, &routine, threads);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_threads	threads;
	pthread_t	*philos;

	ft_parser(argc, argv, &threads);
	if (threads.philo_numbr == 0)
		return (0);
	philos = malloc(sizeof(pthread_t) *(threads->philo_numbr));
	create_threads(&threads, philos);
	while(1);
}