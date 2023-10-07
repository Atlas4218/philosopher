/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:29:28 by rastie            #+#    #+#             */
/*   Updated: 2023/10/06 19:11:38 by rastie           ###   ########.fr       */
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

int	ft_usleep(size_t milliseconds, t_philo *philo)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds && !dead(philo))
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
