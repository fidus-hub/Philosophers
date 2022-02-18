#include "philo.h"
int 	g_tabsyy= 100000;
void* routine(void *threadStruct)
{
	t_philos *threads;

	threads = (t_philos *)threadStruct;
	// while (threads->is_dead == 0)
	// {
	// 	think(threads);
	// 	eat(threads);
	// 	sleep(threads);
	// }
	while( g_tabsyy > 0)
	{
		printf("this philo %d , is alive \n", threads->id);
		g_tabsyy -= 100;
	}
	return(NULL);
}

void create_threads(t_threads *threads, t_philos *philos)
{
	pthread_t	t_id;
	int 		i;


	i = 		0;
	threads->time = get_time();

	while (i < threads->philo_numbr)
	{
		threads->philosopher[i].last_time_2_eat = get_time();
		pthread_create(&t_id, NULL, &routine, &philos[i]);
		usleep(100);
		i++;
	}
}

t_philos *init_philos(t_threads *threads)
{
	int	i;
	t_philos *philosopher;

	i = 0;
	philosopher = malloc(sizeof(t_philos) * threads->philo_numbr);
	while (i < threads->philo_numbr)
	{
		philosopher[i].id = i + 1;
		philosopher[i].last_time_2_eat = 0;
		philosopher[i].number_of_eat = 0;
		philosopher[i].rfork = (i + 1) % threads->philo_numbr;
		philosopher[i].lfork = i;
		pthread_mutex_init(&philosopher[i].eat, NULL);
		philosopher[i].threads = threads;
		i++;
	}
	return (philosopher);
}

int	main(int argc, char **argv)
{
	t_threads	threads;
	t_philos	*philos;

	ft_parser(argc, argv, &threads);
	if (threads.philo_numbr == 0)
		return (0);
	philos = malloc(sizeof(t_philos) *(threads.philo_numbr));
	init_philos(&threads);
	create_threads(&threads, philos);
	//while(1);
}