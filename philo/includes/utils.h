/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:36:41 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/27 12:32:24 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/* Colors */
# define RED		"\033[0;31m"
# define RED_UNDER	"\033[4;31m"
# define CYAN		"\033[0;36m"
# define CYAN_BOLD	"\033[1;36m"
# define WHITE_BOLD	"\033[1;37m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define RESET		"\033[0m"

/* Error Messages */
# define ERROR_MSG "\033[4;31mError:\033[0m "
# define FEW_ARGS  "\033[0;31m Too few arguments :(\033[0m\n"
# define MANY_ARGS "\033[0;31m Too many arguments :(\033[0m\n"
# define NO_NUM    "\033[0;31m Argument is not a number :(\033[0m\n"
# define ZERO_NUM  "\033[0;31m Argument is zero :(\033[0m\n"
# define NEG_NUM   "\033[0;31m Argument is a negative number :(\033[0m\n"
# define BIG_NUM   "\033[0;31m Argument is too big :(\033[0m\n"
# define OPEN_SBRACKET "\033[1;36m[\033[0m"
# define CLOSE_SBRACKET "\033[1;36m]\033[0m"

/* Utils */
# define VARS_COUNT	6

typedef enum e_bool
{
	FALSE,
	TRUE
}				t_bool;

enum e_vars
{
	M_PHILO_DEAD,
	M_START_TIME,
	M_PHILO_COUNT,
	M_TIME_TO_DIE,
	M_TIME_TO_EAT,
	M_TIME_TO_SLEEP,
	M_EAT_COUNT
};

#endif