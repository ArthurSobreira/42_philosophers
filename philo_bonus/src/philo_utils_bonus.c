/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:36:01 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/04 18:28:35 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_status(t_philo *philo, char *msg)
{
	t_data	*data;
	size_t	time;

	data = get_data();
	time = get_current_time();
	sem_wait(data->print);
	printf("%-4zu %-2zu %-3s\n", time, philo->philo_id, msg);
	sem_post(data->print);
}

size_t	get_current_time(void)
{
	t_data			*data;
	struct timeval	time;
	size_t			current_time;

	data = get_data();
	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	current_time -= data->start_time;
	return (current_time);
}

void	wait_philos(t_data *data)
{
	size_t	index;
	int		status;

	index = 0;
	while (index < data->philo_count)
	{
		waitpid(ANY_PHILO, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
			break ;
		index++;
	}
	if (status == EXIT_FAILURE)
	{
		index = 0;
		while (index < data->philo_count)
			kill(data->philos_array[index++].pid, SIGKILL);
	}
}

void	memento_mori(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	print_status(philo, TAKE_FORK);
	usleep(data->time_to_die * 1000);
	print_status(philo, DIED);
	end_philos(data);
}
