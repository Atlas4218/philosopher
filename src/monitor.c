/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:28:55 by rastie            #+#    #+#             */
/*   Updated: 2023/10/03 18:14:09 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->eat_m);
	if (get_time() - philo->last_meal >= (size_t)philo->time_to_die
		&& !philo->eating)
	{
		pthread_mutex_unlock(philo->eat_m);
		return (1);
	}
	pthread_mutex_unlock(philo->eat_m);
	return (0);
}

int	check_if_dead(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (philo_dead(&philos[i]))
		{
			print_state("died", &philos[i]);
			pthread_mutex_lock(&data->dead_m);
			data->philo_died = 1;
			pthread_mutex_unlock(&data->dead_m);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_finished(t_philo *philos, t_data *data)
{
	int	i;
	int	finished;

	i = 0;
	finished = 0;
	if ((int)philos[0].nb_meal == -1)
		return (0);
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->eat_m);
		if (philos[i].nb_meal <= 0)
			finished++;
		pthread_mutex_unlock(&data->eat_m);
		i++;
	}
	if (finished == data->nb_philo)
	{
		pthread_mutex_lock(&data->dead_m);
		data->philo_died = 1;
		pthread_mutex_unlock(&data->dead_m);
		return (1);
	}
	return (0);
}
