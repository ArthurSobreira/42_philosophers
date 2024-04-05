/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:44:03 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/05 10:57:57 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_eat(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	take_forks(philo);
	monitoring(philo);
	philo->last_eat = get_current_time();
	print_status(philo, EATING);
	step_by_step(philo, data->time_to_eat);
	philo->eat_count++;
	drop_forks(philo);
}

void	take_forks(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	sem_wait(data->forks);
	sem_wait(data->forks);
	print_status(philo, TAKE_FORK);
	print_status(philo, TAKE_FORK);
}

void	drop_forks(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	sem_post(data->forks);
	sem_post(data->forks);
	(void)philo;
}

void	philo_sleep(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	print_status(philo, SLEEPING);
	monitoring(philo);
	step_by_step(philo, data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	print_status(philo, THINKING);
	monitoring(philo);
	step_by_step(philo, 1);
	while (*(int *)(data->forks) < 2)
		monitoring(philo);
}
