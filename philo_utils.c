#include "philo.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				sign;
	size_t			r;

	i = 0;
	sign = 1;
	r = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = ((r * 10) + str[i] - '0');
		i++;
		if (r > 4294967295 && sign == 1)
			return (-1);
		if (sign == -1 && r > 4294967295)
			return (0);
	}
	return (r * sign);
}
