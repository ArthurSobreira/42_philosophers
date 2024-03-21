/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:15:38 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/21 11:57:05 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include "defines.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long			last_eat;
	struct s_data	*data;
	pthread_t		thread;
}				t_philo;

/* Utils */
t_bool	ft_isnumber(char *str);
long	ft_atol(const char *nptr);
size_t	ft_strlen(const char *s);

/* Error */
t_bool	validate_args(int argc, char *argv[]);
t_bool	validate_digits(int argc, char *argv[]);
t_bool	print_error(char *msg);

#endif