/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:02:32 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/20 13:17:45 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	validate_args(int argc, char *argv[])
{
	if (argc < 5)
		return (print_error(FEW_ARGS));
	else if (argc > 6)
		return (print_error(MANY_ARGS));
	else if (!validate_digits(argc, argv))
		return (FALSE);
	return (TRUE);
}

t_bool	validate_digits(int argc, char *argv[])
{
	size_t	index;
	long	num;

	index = 1;
	while (index < (size_t)argc)
	{
		if (!ft_isnumber(argv[index]))
			return (print_error(NO_NUM));
		num = ft_atol(argv[index]);
		if (num < 0)
			return (print_error(NEG_NUM));
		else if (num > __INT_MAX__)
			return (print_error(BIG_NUM));
		index++;
	}
	return (TRUE);

}

t_bool print_error(char *msg)
{
    const char *guide = 
        "\n "  CYAN_UNDER "Usage:" RESET " ./philo"
        " "    OPEN_SBRACKET "number_of_philosophers" CLOSE_SBRACKET
        " "    OPEN_SBRACKET "time_to_die" CLOSE_SBRACKET "\n"
        "\t\t" OPEN_SBRACKET "time_to_eat" CLOSE_SBRACKET
        " "    OPEN_SBRACKET "time_to_sleep" CLOSE_SBRACKET "\n"
        "\t\t" OPEN_SBRACKET "times_each_philosopher_must_eat" CLOSE_SBRACKET
		" (optional)\n\n";

    write(STDERR_FILENO, msg, strlen(msg));
    write(STDERR_FILENO, guide, strlen(guide));
    return (FALSE);
}
