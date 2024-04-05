/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:13:41 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/05 10:13:47 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	init_data(int argc, char *argv[])
{
	t_data	*data;

	data = get_data();
	unlink_semaphores();
	data->philo_count = ft_atost(argv[1]);
	data->time_to_die = ft_atost(argv[2]);
	data->time_to_eat = ft_atost(argv[3]);
	data->time_to_sleep = ft_atost(argv[4]);
	if (argc == 6)
		data->total_eat_count = ft_atost(argv[5]);
	else
		data->total_eat_count = __SIZE_MAX__;
	data->philos_array = malloc(sizeof(t_philo) * data->philo_count);
	data->print = sem_open("/print", O_CREAT | O_RDWR, 0644, 1);
	data->forks = sem_open("/forks", O_CREAT | O_RDWR, 0644, data->philo_count);
}

void	init_philos(t_data *data)
{
	struct timeval	time;
	size_t			index;

	index = 0;
	gettimeofday(&time, NULL);
	data->start_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	while (index < data->philo_count)
	{
		data->philos_array[index].pid = fork();
		if (data->philos_array[index].pid < 0)
			exit(EXIT_FAILURE);
		else if (data->philos_array[index].pid == 0)
		{
			data->philos_array[index].philo_id = index + 1;
			data->philos_array[index].eat_count = 0;
			data->philos_array[index].last_eat = 0;
			philo_life(&data->philos_array[index]);
		}
		index++;
	}
}

void	unlink_semaphores(void)
{
	sem_unlink("/print");
	sem_unlink("/forks");
}

void	close_semaphores(void)
{
	t_data	*data;

	data = get_data();
	sem_close(data->print);
	sem_close(data->forks);
}
