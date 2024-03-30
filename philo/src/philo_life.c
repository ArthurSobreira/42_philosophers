/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:20:34 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/30 14:33:56 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_life(void *philo)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philo;
	data = get_data();
	philo->last_eat = data->start_time;
	if (data->philo_count == 1)
	{
		handle_single_philo(philo);
		return (NULL);
	}
	while (!data->philo_dead)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	end_philos(t_data *data)
{
	size_t	index;

	index = 0;
	while (index < data->philo_count)
		pthread_join(data->philos_array[index++].thread, NULL);
	index = 0;
	while (index < data->philo_count)
		pthread_mutex_destroy(&data->philos_array[index++].fork);
	index = 0;
	while (index < VARS_COUNT)
		pthread_mutex_destroy(&data->m_vars[index++]);
	pthread_mutex_destroy(&data->print);
	free(data->philos_array);
}
