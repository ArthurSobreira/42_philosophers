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
}

// void	take_forks(t_philo *philo)
// {

// }