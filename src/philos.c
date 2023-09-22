/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:23:35 by rastie            #+#    #+#             */
/*   Updated: 2023/09/22 18:59:26 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	think()
{
	printf("isthinking");
}

void	sleep()
{
	printf(philo is eating);
	usleep(time_to_sleep);
}

void	eat()
{
	pthread_mutex_lock(first_fork);
	if (rfork == lfork)
	{
		usleep(time_to_die)
		return ;
	}
	pthread_mutex_lock(second_fork);
	printf("philo eat");
	pthread_mutex_lock(meal);
	philo->nb_meal--;
	pthread_mutex_unlock(meal);
	philo->last_meal = get_time();
	usleep(philo->time_to_eat);
	pthread_mutex_unlock(rfork);
	if (rlock != lfork)
		pthread_mutex_unlock(rfork);
}

void	routine(t_philos *philo)
{
	if (philo->id % 2)
		usleep(philo->time_to_eat);
	while(!finished(philo))
	{
		eat();
		sleep();
		think();
	}

}
