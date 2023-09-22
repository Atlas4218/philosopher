/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:46:52 by rastie            #+#    #+#             */
/*   Updated: 2023/09/22 04:00:02 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse(int ac, char **av)
{
	long	arg;

	if (atol(*av) > 200)
		return (1);
	while (*av)
	{
		if (!isnum(*av))
			return (2);
		arg = atol(*(av++));
		if (arg < 0 || arg > INT_MAX)
			return (1);
	}
	return (0);
}
int	init_philos(t_data *data, t_philo **philos)
{
	int	i;

	i = 0;
	*philos = malloc(data->nb_philo * sizeof (**philos));
	if (!*philos)
		return (1);		//erreur malloc
	while (i < data->nb_philo)
	{
		(*philos)[i].time_to_die = data->time_to_die;
		(*philos)[i].time_to_eat = data->time_to_eat;
		(*philos)[i].time_to_sleep = data->time_to_sleep;
		(*philos)[i].nb_meal = data->nb_meal;
		(*philos)[i].id = i + 1;
		(*philos)[i].philo_died = &(data->philo_died);
		(*philos)[i].rfork = data->fork[i];
		if (!i)
			(*philos)[i].lfork = data->fork[data->nb_philo - 1];
		else
			(*philo)[i].lfork = data->fork[i - 1];
		i++;
	}
	return (0);
}
int	init_fork(t_data *data)
{
	int	i;	

	data->forks = malloc(data->nb_philo * sizeof (pthread_mutex_t));
	if (!data->forks)
		return (1);		//erreur malloc
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	return (0);
}

int	init_data(char **arg, t_data *data)
{

	data->nb_philo = (int)atol(arg[0]);
	if (!data->nb_philo)
		return (1);
	data->time_to_die = (int)atol(arg[1]);
	if (!data->time_to_die)
		return (1);
	data->time_to_eat = (int)atol(arg[2]);
	if (!data->time_to_eat)
		return (1);
	data->time_to_sleep = (int)atol(arg[3]);
	if (!data->time_to_sleep)
		return (1);
	data->nb_meal = -1;
	if (arg[4])
		data->nb_meal = (int)atol(arg[4]);
	return (0);
}

