/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:50:14 by rastie            #+#    #+#             */
/*   Updated: 2023/09/22 16:13:31 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	create_threads(t_data data, t_philos *philos)
{
	int	i;
	pthread_t threads[data->philo];
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(thread + i, NULL, &routine, NULL))
			return 5;
		i++;
	}
	
}
