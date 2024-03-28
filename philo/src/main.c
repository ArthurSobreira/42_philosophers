/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:27:39 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/27 16:41:40 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

void	end_dinner(t_data *data)
{
	size_t	index;

	index = 0;
	while (index < data->philo_count)
		pthread_join(data->philos_array[index++].thread, NULL);
	index = 0;
	while (index < data->philo_count)
		pthread_mutex_destroy(&data->philos_array[index++].fork);
	index = 0;
	while (index < VARS_COUNT)
		pthread_mutex_destroy(&data->m_vars[index++]);
	pthread_mutex_destroy(&data->print);
	free(data->philos_array);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (validate_args(argc, argv))
	{
		data = get_data();
		init_data(argc, argv);
		init_philos(data);
		end_dinner(data);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
