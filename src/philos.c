/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:23:35 by rastie            #+#    #+#             */
/*   Updated: 2023/10/04 13:03:38 by rastie           ###   ########.fr       */
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
	print_state("is thinking", philo);
}

void	philo_sleep(t_philo *philo)
{
	print_state("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	print_state("took the first fork", philo);
	if (philo->first_fork == philo->second_fork)
	{
		usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->first_fork);
		return ;
	}
	pthread_mutex_lock(philo->second_fork);
	print_state("took the second fork", philo);
	philo->eating = 1;
	print_state("is eating", philo);
	pthread_mutex_lock(philo->eat_m);
	if (philo->nb_meal > 0)
		philo->nb_meal--;
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->eat_m);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->first_fork);
	if (philo->first_fork != philo->second_fork)
		pthread_mutex_unlock(philo->second_fork);
}

void	*routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	philo->start_time = get_time();
	philo->last_meal = get_time();
	if (philo->id % 2)
	{
		philo_think(philo);
		ft_usleep(philo->time_to_eat);
	}
	while (!dead(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (pointer);
}
