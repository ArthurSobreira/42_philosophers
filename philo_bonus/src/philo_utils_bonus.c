/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:36:01 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/04 14:42:54 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_status(t_philo *philo, char *msg)
{
	t_data	*data;
	size_t	time;

	data = get_data();
	time = getter_current_time();
	sem_wait(data->print);
	printf("%-4zu %-2zu %-3s\n", time, getter_philo_id(philo), msg);
	sem_post(data->print);
}

// void	memento_mori(t_philo *philo)
// {
// 	t_data	*data;
// 	pid_t	pid;

// 	data = get_data();
// 	pid = philo->pid;

// 	print_status(philo, TAKE_FORK);
// 	usleep(data->time_to_die * 1000);
// 	print_status(philo, DIED);
// 	sem_wait(data->print);
// 	data->philo_dead = TRUE;
// 	sem_post(data->print);
// }