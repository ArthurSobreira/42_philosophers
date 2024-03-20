/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:27:39 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/20 12:04:16 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	if (validate_args(argc, argv))
	{
		// start_dinner();
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
