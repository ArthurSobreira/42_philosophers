/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:44:06 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/04 15:46:37 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_life(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	if (data->philo_count == 1)
	{
		memento_mori(philo);
		exit(EXIT_SUCCESS);
	}
	// while (TRUE)
	// {
	// 	philo_eat(philo);
	// 	philo_sleep(philo);
	// 	philo_think(philo);
	// }
}

void	end_philos(t_data *data)
{
	size_t	index;

	index = 0;
	free(data->philos_array);
	sem_close(data->print);
	sem_close(data->forks);
	unlink_semaphores();
}
