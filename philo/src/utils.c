/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:28:29 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/26 12:05:40 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_bool	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (TRUE);
	return (FALSE);
}

t_bool	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

long	ft_atol(const char *nptr)
{
	size_t	i;
	long	result;
	int		is_negative;

	i = 0;
	result = 0;
	is_negative = 1;
	while (((nptr[i] >= 9) && (nptr[i] <= 13)) || ((nptr[i]) == 32))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if ((nptr[i] == '-'))
			is_negative *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (result * is_negative);
}

size_t	ft_atost(const char *nptr)
{
	size_t	i;
	size_t	result;
	int		is_negative;

	i = 0;
	result = 0;
	is_negative = 1;
	while (((nptr[i] >= 9) && (nptr[i] <= 13)) || ((nptr[i]) == 32))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if ((nptr[i] == '-'))
			is_negative *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (result * is_negative);
}
