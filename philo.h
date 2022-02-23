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
	pthread_mutex_t		write;
	pthread_mutex_t		*forks;
	struct s_philos		*philosopher;
}						t_threads;

typedef struct s_philos
{
	int					id;
	int					last_time_2_eat;
	int					number_of_eat;
	int					rfork;
	int					lfork;
	pthread_mutex_t		eat;
	struct s_threads	*threads;
}						t_philos;


int						ft_parser(int argc, char **argv, t_threads *threads);
int						ft_atoi(const char *str);
//void					create_threads(t_threads *threads, t_philos *philos);
void					think(t_philos *philos);
void					eat(t_philos *philos);
void					sleeping(t_philos *philos);
unsigned long long		get_time(void);
void					display(char *msg, t_philos *philo);
int						ft_strncmp(const char *s1, const char *s2, size_t n);


#endif