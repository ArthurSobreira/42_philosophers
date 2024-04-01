/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:27:39 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/01 15:28:16 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (validate_args(argc, argv))
	{
		data = get_data();
		init_data(argc, argv);
		init_philos(data);
		end_philos(data);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
