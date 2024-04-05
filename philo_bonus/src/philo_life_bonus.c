/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:44:06 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/05 10:56:56 by arsobrei         ###   ########.fr       */
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
		exit(EXIT_FAILURE);
	}
	while (TRUE)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

void	monitoring(t_philo *philo)
{
	t_data	*data;
	t_bool	someone_died;
	t_bool	eat_enough;
	int		status;

	data = get_data();
	status = EXIT_SUCCESS;
	someone_died = (get_current_time() - philo->last_eat \
		> data->time_to_die);
	eat_enough = (philo->eat_count >= data->total_eat_count);
	if (someone_died || eat_enough)
	{
		if (someone_died)
		{
			print_status(philo, DIED);
			status = EXIT_FAILURE;
		}
		free(data->philos_array);
		close_semaphores();
		exit(status);
	}
}

void	end_philos(t_data *data)
{
	free(data->philos_array);
	close_semaphores();
	unlink_semaphores();
}
