/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:27:12 by rastie            #+#    #+#             */
/*   Updated: 2023/10/04 17:28:03 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long	ft_atol(const char *nptr)
{
	char	*str;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	str = (char *)nptr;
	while ((*str <= '\r' && *str >= '\t') || *str == ' ')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
	}
	return (result * sign);
}

int	ft_isspace(int arg)
{
	return ((arg > 8 && arg < 14) || arg == ' ');
}

int	isnum(char *arg)
{
	int	nbdigit;
	int	nbsign;

	nbsign = 0;
	nbdigit = 0;
	while (*arg)
	{
		if (!(*arg >= '0' && *arg <= '9')
			&& (!(*arg == '-' || *arg == '+' || ft_isspace(*arg))
				|| nbdigit || nbsign))
			return (0);
		if (*arg == '-' || *arg == '+')
			nbsign++;
		if ((*arg >= '0' && *arg <= '9'))
			nbdigit++;
		arg++;
	}
	return (nbdigit);
}
