/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 03:20:20 by rastie            #+#    #+#             */
/*   Updated: 2023/09/22 16:13:31 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	*routine(philo)
{
	if (even(philo)
		think(time_to_eat)
	while (1)
		if (check_death((t_philo)philo))
			break ;
		eat(time_to_eat)
		if (check_fed((t_philo)philo))
			break ;
		sleep(time_to_sleep)
		think(time_to_think)
	return (NULL);

}
int	main(int ac, chat **av)
{
	t_data	data;
	t_philo *philos;

	if (ac != 5 || ac != 6)
		return (1);		//wrong number of arg
	if (parse(++av))
		return (2);		//err parsing
	if (ac == 6)
		if (!atol(av[4]))
			return (0);	//edge case
	if (init_data(av, &data))
		return (1);
	init_fork(&data);
	init_philos(&data, &philos);	
	create_threads(philos);
	monitor();
	join_threads();


	return (0);
}




