/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:46:52 by rastie            #+#    #+#             */
/*   Updated: 2023/10/04 14:56:28 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	select_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		philo->first_fork = philo->left_fork;
		philo->second_fork = philo->right_fork;
	}
	else
	{
		philo->first_fork = philo->left_fork;
		philo->second_fork = philo->right_fork;
	}
}

void	get_input(t_philo *philo, int id, char **av)
{
	philo->time_to_die = (int)ft_atol(av[1]);
	philo->time_to_eat = (int)ft_atol(av[2]);
	philo->time_to_sleep = (int)ft_atol(av[3]);
	philo->nb_meal = -1;
	if (av[4])
		philo->nb_meal = (int)ft_atol(av[4]);
	philo->id = id;
}

t_philo	*init_philos(t_data *data, char **av)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = malloc(data->nb_philo * sizeof (*philos));
	if (!philos)
		return (printf("error malloc"), NULL);
	while (i < data->nb_philo)
	{
		get_input(&philos[i], i + 1, av);
		philos[i].philo_died = &(data->philo_died);
		philos[i].left_fork = &data->forks[i];
		if (i == 0)
			philos[i].right_fork = &data->forks[data->nb_philo - 1];
		else
			philos[i].right_fork = &data->forks[i - 1];
		select_fork(&philos[i]);
		philos[i].write_m = &data->write_m;
		philos[i].dead_m = &data->dead_m;
		philos[i].eat_m = &data->eat_m;
		philos[i].start_time = get_time();
		philos[i].last_meal = get_time();
		philos[i++].eating = 0;
	}
	return (philos);
}

int	init_fork(t_data *data)
{
	int	i;	

	data->forks = malloc(data->nb_philo * sizeof (pthread_mutex_t));
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

void	init_data(char **arg, t_data *data)
{
	data->nb_philo = (int)ft_atol(arg[0]);
	data->philo_died = 0;
	pthread_mutex_init(&data->dead_m, NULL);
	pthread_mutex_init(&data->write_m, NULL);
	pthread_mutex_init(&data->eat_m, NULL);
}
