/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:06:53 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/30 16:45:47 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data(int argc, char *argv[])
{
	t_data	*data;
	size_t	index;

	index = 0;
	data = get_data();
	data->philo_dead = FALSE;
	data->philo_count = ft_atost(argv[1]);
	data->time_to_die = ft_atost(argv[2]);
	data->time_to_eat = ft_atost(argv[3]);
	data->time_to_sleep = ft_atost(argv[4]);
	if (argc == 6)
		data->total_eat_count = ft_atost(argv[5]);
	else
		data->total_eat_count = __SIZE_MAX__;
	pthread_mutex_init(&data->print, NULL);
	while (index < VARS_COUNT)
		pthread_mutex_init(&data->m_vars[index++], NULL);
	data->philos_array = malloc(sizeof(t_philo) * data->philo_count);
}

void	init_philos(t_data *data)
{
	struct timeval	time;
	size_t			index;

	index = 0;
	gettimeofday(&time, NULL);
	data->start_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	if (data->philo_count > 1)
		pthread_create(&data->monitor, NULL, &monitoring, (void *)data);
	while (index < data->philo_count)
	{
		data->philos_array[index].philo_id = index + 1;
		data->philos_array[index].eat_count = 0;
		data->philos_array[index].last_eat = 0;
		pthread_mutex_init(&data->philos_array[index].fork, NULL);
		pthread_create(&data->philos_array[index].thread, NULL, \
			&philo_life, (void *)&data->philos_array[index]);
		index++;
	}
}
