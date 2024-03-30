/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:30:49 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/30 14:30:49 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philo *philo)
{
	t_data	*data;

	if (getter_philo_death())
		return ;
	data = get_data();
	take_forks(philo);
	print_status(philo, TAKE_FORK);
	print_status(philo, TAKE_FORK);
	pthread_mutex_lock(&data->m_vars[M_LAST_EAT]);
	philo->last_eat = getter_current_time();
	pthread_mutex_unlock(&data->m_vars[M_LAST_EAT]);
	print_status(philo, EATING);
	usleep(getter_time_to_eat() * 1000);
	pthread_mutex_lock(&data->m_vars[M_EAT_COUNT]);
	philo->eat_count++;
	pthread_mutex_unlock(&data->m_vars[M_EAT_COUNT]);
	drop_forks(philo);
}

void	take_forks(t_philo *philo)
{
	(void)philo;
	if (getter_philo_death())
		return ;
}

void	drop_forks(t_philo *philo)
{
	(void)philo;
	if (getter_philo_death())
		return ;
}

void	philo_sleep(t_philo *philo)
{
	if (getter_philo_death())
		return ;
	print_status(philo, SLEEPING);
	usleep(getter_time_to_sleep() * 1000);
}

void	philo_think(t_philo *philo)
{
	if (getter_philo_death())
		return ;
	print_status(philo, THINKING);
	usleep(1000);
}
