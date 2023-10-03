/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 03:20:20 by rastie            #+#    #+#             */
/*   Updated: 2023/10/03 18:52:22 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	monitor(t_philo *philos, t_data *data)
{
	while (1)
		if (check_if_dead(philos, data) == 1 
			|| check_if_all_finished(philos, data) == 1)
			break ;
}

int	parse(char **av)
{
	long	arg;
	int		i;

	i = 0;
	if (ft_atol(av[i]) > 200)
		return (1);
	while (av[i])
	{
		if (!isnum(av[i]))
			return (2);
		arg = ft_atol(av[i]);
		if (arg > INT_MAX || (av[i + 1] && arg <= 0) || (!av[i + 1] && arg < 0))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_philo		*philos;

	if (ac != 5 && ac != 6)
		return (printf("Wrong number of argument"), 1);
	if (parse(++av))
		return (printf("Wrong value for argument"), 2);
	if (ac == 6)
		if (!ft_atol(av[4]))
			return (0);
	init_data(av, &data);
	init_fork(&data);
	philos = init_philos(&data, av);
	if (!philos)
		return (3);
	create_threads(data, philos);
	monitor(philos, &data);
	join_threads(data, philos);
	clear_all(&data, philos);
	return (0);
}
