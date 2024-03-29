/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:27:39 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/27 12:01:03 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

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
		data->eat_count = ft_atost(argv[5]);
	else
		data->eat_count = __SIZE_MAX__;
	pthread_mutex_init(&data->print, NULL);
	while (index < VARS_COUNT)
		pthread_mutex_init(&data->m_vars[index++], NULL);
	data->philos_array = malloc(sizeof(t_philo) * data->philo_count);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (validate_args(argc, argv))
	{
		data = get_data();
		init_data(argc, argv);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
