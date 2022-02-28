NAME= philo
CC = gcc
FLAGS = -Wall -Werror -Wextra -g
SRCS = philo.c eat.c parser.c philo_utils.c sleeping.c think.c
all: $(NAME)
$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) 
clean:
	@rm -rf $(NAME)
re: clean
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)