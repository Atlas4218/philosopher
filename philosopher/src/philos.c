/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:23:35 by rastie            #+#    #+#             */
/*   Updated: 2023/10/07 16:56:43 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_m);
	if (*philo->philo_died == 1)
		return (pthread_mutex_unlock(philo->dead_m), 1);
	pthread_mutex_unlock(philo->dead_m);
	return (0);
}

void	philo_think(t_philo *philo)
{
	if (dead(philo))
		return ;
	print_state("is thinking", philo);
}

void	philo_sleep(t_philo *philo)
{
	print_state("is sleeping", philo);
	ft_usleep(philo->time_to_sleep, philo);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	print_state("took a fork", philo);
	if (philo->first_fork == philo->second_fork)
	{
		ft_usleep(philo->time_to_die, philo);
		pthread_mutex_unlock(philo->first_fork);
		return ;
	}
	pthread_mutex_lock(philo->second_fork);
	print_state("took a fork", philo);
	print_state("is eating", philo);
	pthread_mutex_lock(philo->eat_m);
	if (philo->nb_meal > 0)
		philo->nb_meal--;
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->eat_m);
	ft_usleep(philo->time_to_eat, philo);
	pthread_mutex_unlock(philo->first_fork);
	if (philo->first_fork != philo->second_fork)
		pthread_mutex_unlock(philo->second_fork);
}

void	*routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (!(philo->id % 2))
	{
		philo_think(philo);
		ft_usleep(philo->time_to_eat, philo);
	}
	while (!dead(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (pointer);
}
