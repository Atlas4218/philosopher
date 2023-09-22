/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:29:28 by rastie            #+#    #+#             */
/*   Updated: 2023/09/22 16:13:31 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	get_time(void)
{
	timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

