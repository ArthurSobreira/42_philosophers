/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:15:38 by arsobrei          #+#    #+#             */
/*   Updated: 2024/03/30 14:12:55 by arsobrei         ###   ########.fr       */
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
	M_TOTAL_EAT_COUNT,
	M_PHILO_ID,
	M_EAT_COUNT,
	M_LAST_EAT
};

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
	size_t			total_eat_count;
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

/* Init */
t_data	*get_data(void);
void	init_data(int argc, char *argv[]);
void	init_philos(t_data *data);

/* Mutex Getter */
t_bool	getter_philo_death(void);
size_t	getter_current_time(void);
size_t	getter_philo_count(void);
size_t	getter_time_to_die(void);
size_t	getter_time_to_eat(void);
size_t	getter_time_to_sleep(void);
size_t	getter_total_eat_count(void);
size_t	getter_philo_id(t_philo *philo);
size_t 	getter_eat_count(t_philo *philo);
size_t	getter_last_eat(t_philo *philo);

#endif