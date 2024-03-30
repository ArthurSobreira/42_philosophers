/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:08:56 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/30 16:08:56 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitoring(void *data)
{
	t_data	*data;
	t_philo	*philo_array;
	size_t	index;

	data = (t_data *)data;
	philo_array = data->philos_array;
	while (!data->philo_dead)
	{
		index = 0;
		while (index < data->philo_count)
		{
			if (verify_philo_death(data, &philo_array[index]))
				return (NULL);
			else if (verify_philos_meals(data))
			{
				pthread_mutex_lock(data->m_vars[M_PHILO_DEAD]);
				data->philo_dead = TRUE;
				pthread_mutex_unlock(data->m_vars[M_PHILO_DEAD]);
				return (NULL);
			}
			index++;
		}
	}
}

t_bool	verify_philo_death(t_data *data, t_philo *philo)
{
	if (getter_current_time() - getter_last_eat(philo) \
		> getter_time_to_die())
	{
		pthread_mutex_lock(data->m_vars[M_PHILO_DEAD]);
		data->philo_dead = TRUE;
		pthread_mutex_unlock(data->m_vars[M_PHILO_DEAD]);
		print_status(philo, DIED);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	verify_philos_meals(t_data *data)
{
	size_t	index;

	index = 0;
	while (index < data->philo_count)
	{
		if (getter_eat_count(&data->philos_array[index]) \
			< getter_total_eat_count())
			return (FALSE);
		index++;
	}
	return (TRUE);
}
