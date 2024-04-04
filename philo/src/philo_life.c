/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:20:34 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/04 15:01:56 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_life(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (getter_philo_count() == 1)
	{
		memento_mori(philo);
		return (NULL);
	}
	while (TRUE)
	{
		if (getter_philo_death())
			break ;
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
	if (getter_philo_count() > 1)
		pthread_join(data->monitor, NULL);
	while (index < getter_philo_count())
		pthread_join(data->philos_array[index++].thread, NULL);
	index = 0;
	while (index < getter_philo_count())
		pthread_mutex_destroy(&data->philos_array[index++].fork);
	index = 0;
	while (index < VARS_COUNT)
		pthread_mutex_destroy(&data->m_vars[index++]);
	pthread_mutex_destroy(&data->print);
	free(data->philos_array);
}
