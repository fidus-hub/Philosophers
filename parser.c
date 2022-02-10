#include "philo.h"

int	ft_parser(int argc, char **argv, t_threads *threads)
{
	if (argc != 5 && argc != 6)
	{
		write(2, "wrong number of argument!\n", 26);
		return (0);
	}
	else if (argv[5])
		threads->number_of_time_2_eat = ft_atoi(argv[5]);
	else
		threads->number_of_time_2_eat = 0;
	threads->philo_numbr = ft_atoi(argv[1]);
	threads->time_2_die = ft_atoi(argv[2]);
	threads->time_2_eat = ft_atoi(argv[3]);
	threads->time_2_sleep = ft_atoi(argv[4]);
	threads->eat_counter = 0;
	threads->is_dead = 0;
}


