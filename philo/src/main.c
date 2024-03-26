/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:27:39 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/26 12:15:15 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

void	start_dinner(int argc, char *argv[])
{
	t_data	*data;
	size_t	index;

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
	data->philos_array = malloc(sizeof(t_philo) * data->philo_count);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (validate_args(argc, argv))
	{
		data = get_data();
		start_dinner(argc, argv);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
