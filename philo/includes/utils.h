/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:36:41 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/03 21:01:43 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* Colors */
# define RED "\033[0;31m"
# define RED_UNDER "\033[4;31m"
# define CYAN "\033[0;36m"
# define CYAN_BOLD "\033[1;36m"
# define WHITE_BOLD "\033[1;37m"
# define RESET "\033[0m"

/* Error Messages */
# define ERROR_MSG "\033[4;31mError:\033[0m "
# define FEW_ARGS "\033[0;31m Too few arguments :(\033[0m\n"
# define MANY_ARGS "\033[0;31m Too many arguments :(\033[0m\n"
# define NO_NUM "\033[0;31m Argument is not a number :(\033[0m\n"
# define ZERO_NUM "\033[0;31m Argument is zero :(\033[0m\n"
# define NEG_NUM "\033[0;31m Argument is a negative number :(\033[0m\n"
# define BIG_NUM "\033[0;31m Argument is too big :(\033[0m\n"
# define OPEN_SBRACKET "\033[1;36m[\033[0m"
# define CLOSE_SBRACKET "\033[1;36m]\033[0m"

/* Utils */
# define VARS_COUNT 10
# define TAKE_FORK "🍽  \033[1;37mhas taken a fork"
# define EATING "🍝 \033[1;33mis eating\033[0m"
# define SLEEPING "💤 \033[1;36mis sleeping\033[0m"
# define THINKING "💡 \033[1;35mis thinking\033[0m"
# define DIED "💀 \033[1;31mdied\033[0m"

#endif