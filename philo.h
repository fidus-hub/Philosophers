#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_threads
{
	unsigned long long	time;
	int					philo_numbr;
	int					time_2_die;
	int					time_2_sleep;
	int					time_2_eat;
	int					eat_counter;
	int					number_of_time_2_eat;
	int					is_dead;
}						t_threads;

int						ft_parser(int argc, char **argv, t_threads *threads);
int						ft_atoi(const char *str);
void					create_threads(t_threads *threads, pthread_t *philos);


#endif