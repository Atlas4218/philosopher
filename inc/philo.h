/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:38:50 by rastie            #+#    #+#             */
/*   Updated: 2023/09/22 18:59:26 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_data
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_meal;
	int	philo_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t dead_m;
	pthread_mutex_t write_m;
}	t_data;

typedef struct s_philo
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_meal;
	int	id;
	int	*philo_died;
	size_t	start_time;
	size_t	last_meal;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*fork_next;
	pthread_mutex_t *dead_m;
	pthread_mutex_t *write_m;


}	t_philo;
