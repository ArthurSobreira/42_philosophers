/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:21:52 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/30 14:21:52 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, char *msg)
{
	t_data	*data;
	size_t	time;

	if (getter_philo_death())
		return ;
	data = get_data();
	time = getter_current_time();
	pthread_mutex_lock(&data->print);
	printf("%-4zu %-2zu %-3s\n", time, getter_philo_id(philo), msg);
	pthread_mutex_unlock(&data->print);
}

void	memento_mori(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	print_status(philo, TAKE_FORK);
	usleep(data->time_to_die * 1000);
	print_status(philo, DIED);
	pthread_mutex_lock(&data->m_vars[M_PHILO_DEAD]);
	data->philo_dead = TRUE;
	pthread_mutex_unlock(&data->m_vars[M_PHILO_DEAD]);
}

t_bool	is_odd_philo(t_philo *philo)
{
	if (philo->philo_id % 2 != 0)
		return (TRUE);
	return (FALSE);
}

t_bool	is_even_philo(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
		return (TRUE);
	return (FALSE);
}
