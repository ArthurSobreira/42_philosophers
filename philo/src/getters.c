/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:43:38 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/30 16:24:31 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	getter_philo_death(void)
{
	t_data	*data;
	t_bool	philo_dead;

	data = get_data();
	pthread_mutex_lock(&data->m_vars[M_PHILO_DEAD]);
	philo_dead = data->philo_dead;
	pthread_mutex_unlock(&data->m_vars[M_PHILO_DEAD]);
	return (philo_dead);
}

size_t	getter_current_time(void)
{
	t_data			*data;
	struct timeval	time;
	size_t			current_time;

	data = get_data();
	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	pthread_mutex_lock(&data->m_vars[M_START_TIME]);
	current_time -= data->start_time;
	pthread_mutex_unlock(&data->m_vars[M_START_TIME]);
	return (current_time);
}

size_t	getter_philo_count(void)
{
	t_data	*data;
	size_t	philo_count;

	data = get_data();
	pthread_mutex_lock(&data->m_vars[M_PHILO_COUNT]);
	philo_count = data->philo_count;
	pthread_mutex_unlock(&data->m_vars[M_PHILO_COUNT]);
	return (philo_count);
}

size_t	getter_time_to_die(void)
{
	t_data	*data;
	size_t	time_to_die;

	data = get_data();
	pthread_mutex_lock(&data->m_vars[M_TIME_TO_DIE]);
	time_to_die = data->time_to_die;
	pthread_mutex_unlock(&data->m_vars[M_TIME_TO_DIE]);
	return (time_to_die);
}

size_t	getter_time_to_eat(void)
{
	t_data	*data;
	size_t	time_to_eat;

	data = get_data();
	pthread_mutex_lock(&data->m_vars[M_TIME_TO_EAT]);
	time_to_eat = data->time_to_eat;
	pthread_mutex_unlock(&data->m_vars[M_TIME_TO_EAT]);
	return (time_to_eat);
}
