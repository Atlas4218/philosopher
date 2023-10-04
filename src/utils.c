/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:29:28 by rastie            #+#    #+#             */
/*   Updated: 2023/10/04 15:23:32 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	print_state(char *state, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->write_m);
	time = get_time() - philo->start_time;
	if (!dead(philo))
		printf("%zu %d %s\n", time, philo->id, state);
	pthread_mutex_unlock(philo->write_m);
}

void	clear_all(t_data *data, t_philo *philos)
{
	int	i;

	if (philos)
		free(philos);
	i = 0;
	while (data->forks && i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	if (data->forks)
		free(data->forks);
	pthread_mutex_destroy(&data->write_m);
	pthread_mutex_destroy(&data->eat_m);
	pthread_mutex_destroy(&data->dead_m);
}

long	ft_atol(const char *nptr)
{
	char	*str;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	str = (char *)nptr;
	while ((*str <= '\r' && *str >= '\t') || *str == ' ')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
	}
	return (result * sign);
}

int	ft_isspace(int arg)
{
	return ((arg > 8 && arg < 14) || arg == ' ');
}

int	isnum(char *arg)
{
	int	nbdigit;
	int	nbsign;

	nbsign = 0;
	nbdigit = 0;
	while (*arg)
	{
		if (!(*arg >= '0' && *arg <= '9')
			&& (!(*arg == '-' || *arg == '+' || ft_isspace(*arg))
				|| nbdigit || nbsign))
			return (0);
		if (*arg == '-' || *arg == '+')
			nbsign++;
		if ((*arg >= '0' && *arg <= '9'))
			nbdigit++;
		arg++;
	}
	return (nbdigit);
}
