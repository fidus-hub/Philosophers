#include "philo.h"

int	main(int argc, char **argv)
{
	t_threads	threads;

	ft_parser(argc, argv, &threads);
	if (threads.philo_numbr == 0)
		return (0);
}