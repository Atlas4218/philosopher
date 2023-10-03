/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:50:14 by rastie            #+#    #+#             */
/*   Updated: 2023/10/03 18:17:38 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	create_threads(t_data data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data.nb_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]))
		{
			printf("pthread_create error");
			return (clear_all(&data, philos));
		}
		i++;
	}
}

void	join_threads(t_data data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data.nb_philo)
	{
		if (pthread_join(philos[i].thread, NULL))
		{
			printf("pthread_join error");
			return (clear_all(&data, philos));
		}
		i++;
	}
}
