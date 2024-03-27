/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:15:38 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/27 12:57:17 by arsobrei         ###   ########.fr       */
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
# include "utils.h"

typedef struct s_data
{
	struct s_philo	*philos_array;
	pthread_mutex_t	print;
	pthread_mutex_t	m_vars[VARS_COUNT];
	t_bool			philo_dead;
	size_t			start_time;
	size_t			philo_count;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			eat_count;
}				t_data;

typedef struct s_philo
{
	size_t			philo_id;
	size_t			eat_count;
	size_t			last_eat;
	pthread_t		thread;
	pthread_mutex_t	fork;
}				t_philo;

/* Utils */
t_bool	ft_isnumber(char *str);
size_t	ft_strlen(const char *s);
long	ft_atol(const char *nptr);
size_t	ft_atost(const char *nptr);

/* Error */
t_bool	validate_args(int argc, char *argv[]);
t_bool	validate_digits(int argc, char *argv[]);
t_bool	print_error(char *msg);

#endif