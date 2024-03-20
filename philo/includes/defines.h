/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:36:41 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/20 13:07:11 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/* Colors */
# define RED		"\033[0;31m"
# define RED_UNDER	"\033[4;31m"
# define CYAN		"\033[0;36m"
# define CYAN_UNDER	"\033[4;36m"
# define CYAN_BOLD	"\033[1;36m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define RESET		"\033[0m"

/* Error Messages */
# define ERROR_MSG 	RED_UNDER"Error:"RESET
# define FEW_ARGS 	ERROR_MSG RED" Too few arguments :(\n"RESET
# define MANY_ARGS	ERROR_MSG RED" Too many arguments :(\n"RESET
# define NO_NUM		ERROR_MSG RED" Argument is not a number :(\n"RESET
# define NEG_NUM 	ERROR_MSG RED" Argument is a negative number :(\n"RESET
# define BIG_NUM 	ERROR_MSG RED" Argument is too big :(\n"RESET
# define OPEN_SBRACKET	CYAN_BOLD"["RESET
# define CLOSE_SBRACKET	CYAN_BOLD"]"RESET

#endif