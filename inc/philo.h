/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:38:50 by rastie            #+#    #+#             */
/*   Updated: 2023/10/03 19:49:58 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_data
{
	int				nb_philo;
	int				philo_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_m;
	pthread_mutex_t	eat_m;
	pthread_mutex_t	write_m;
}	t_data;

typedef struct s_philo
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meal;
	int				eating;
	int				id;
	int				*philo_died;
	size_t			start_time;
	size_t			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	pthread_mutex_t	*dead_m;
	pthread_mutex_t	*write_m;
	pthread_mutex_t	*eat_m;
	pthread_t		thread;

}	t_philo;

int		check_if_dead(t_philo *philos, t_data *data);
int		check_if_all_finished(t_philo *philos, t_data *data);
void	create_threads(t_data data, t_philo *philos);
void	join_threads(t_data data, t_philo *philos);
int		init_fork(t_data *data);
void	init_data(char **arg, t_data *data);
t_philo	*init_philos(t_data *data, char **av);
void	*routine(void *pointer);
int		dead(t_philo *philo);
size_t	get_time(void);
int		ft_usleep(size_t milliseconds);
void	print_state(char *state, t_philo *philo);
void	clear_all(t_data *data, t_philo *philos);
long	ft_atol(const char *nptr);
int		isnum(char *arg);

#endif
