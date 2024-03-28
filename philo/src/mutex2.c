/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:58:20 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/27 17:25:37 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	getter_time_to_sleep(void)
{
	t_data	*data;
	size_t	time_to_sleep;

	data = get_data();
	pthread_mutex_lock(&data->m_vars[M_TIME_TO_SLEEP]);
	time_to_sleep = data->time_to_sleep;
	pthread_mutex_unlock(&data->m_vars[M_TIME_TO_SLEEP]);
	return (time_to_sleep);
}

size_t	getter_total_eat_count(void)
{
	t_data	*data;
	size_t	eat_count;

	data = get_data();
	pthread_mutex_lock(&data->m_vars[M_TOTAL_EAT_COUNT]);
	eat_count = data->total_eat_count;
	pthread_mutex_unlock(&data->m_vars[M_TOTAL_EAT_COUNT]);
	return (eat_count);
}

size_t	getter_philo_id(t_philo *philo)
{
	t_data	*data;
	size_t	philo_id;

	data = get_data();
	pthread_mutex_lock(&data->m_vars[M_PHILO_ID]);
	philo_id = philo->philo_id;
	pthread_mutex_unlock(&data->m_vars[M_PHILO_ID]);
	return (philo_id);
}

size_t getter_eat_count(t_philo *philo)
{
	t_data	*data;
	size_t	eat_count;

	data = get_data();
	pthread_mutex_lock(&data->m_vars[M_EAT_COUNT]);
	eat_count = philo->eat_count;
	pthread_mutex_unlock(&data->m_vars[M_EAT_COUNT]);
	return (eat_count);
}

size_t getter_last_eat(t_philo *philo)
{
	t_data	*data;
	size_t	last_eat;

	data = get_data();
	pthread_mutex_lock(&data->m_vars[M_LAST_EAT]);
	last_eat = philo->last_eat;
	pthread_mutex_unlock(&data->m_vars[M_LAST_EAT]);
	return (last_eat);
}
