/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:06:53 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/28 16:23:49 by arsobrei         ###   ########.fr       */
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

void	print_status(t_philo *philo, char *status)
{
	t_data	*data;

	data = get_data();
	pthread_mutex_lock(&data->print);
	printf("%zu %zu %s\n", get_time(data), philo->philo_id, status);
	pthread_mutex_unlock(&data->print);
}

void	*philo_life(void *philo)
{
	t_philo	*philo_data;
	t_data	*data;

	philo_data = (t_philo *)philo;
	data = get_data();
	philo_data->last_eat = data->start_time;
	if (data->philo_count == 1)
	{
		usleep(data->time_to_die * 1000);
		pthread_mutex_lock(&data->print);
		printf("%zu %zu died\n", get_time(data), philo_data->philo_id);
		data->philo_dead = TRUE;
		pthread_mutex_unlock(&data->print);
		return (NULL);
	}
	while (data->philo_dead == FALSE)
	{
		philo_eat(philo_data);
		philo_sleep(philo_data);
		philo_think(philo_data);
	}
	return (NULL);
}

void	init_philos(t_data *data)
{
	struct timeval	time;
	size_t	index;

	index = 0;
	gettimeofday(&time, NULL);
	data->start_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	while (index < data->philo_count)
	{
		data->philos_array[index].philo_id = index + 1;
		data->philos_array[index].eat_count = 0;
		data->philos_array[index].last_eat = 0;
		pthread_mutex_init(&data->philos_array[index].fork, NULL);
		pthread_create(&data->philos_array[index].thread, NULL, \
			&philo_life, (void *)&data->philos_array[index]);
	}
}
