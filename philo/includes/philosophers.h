/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:15:38 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/04 18:43:13 by arsobrei         ###   ########.fr       */
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
	pthread_t		monitor;
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

/* Error */
t_bool	validate_args(int argc, char *argv[]);
t_bool	validate_digits(int argc, char *argv[]);
t_bool	print_error(char *msg);

/* Init */
t_data	*get_data(void);
void	init_data(int argc, char *argv[]);
void	init_philos(t_data *data);

/* Monitor */
void	*monitoring(void *philo_ptr);
t_bool	verify_philo_death(t_data *data, t_philo *philo);
t_bool	verify_philos_meals(t_data *data);

/* Philo Routine*/
void	*philo_life(void *philo_ptr);
void	philo_eat(t_philo *philo);
void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	end_philos(t_data *data);

/* Philo Utils */
void	print_status(t_philo *philo, char *msg);
void	memento_mori(t_philo *philo);
t_bool	is_odd_philo(t_philo *philo);
t_bool	is_even_philo(t_philo *philo);

/* Mutex Getters */
t_bool	getter_philo_death(void);
size_t	getter_current_time(void);
size_t	getter_philo_count(void);
size_t	getter_time_to_die(void);
size_t	getter_time_to_eat(void);
size_t	getter_time_to_sleep(void);
size_t	getter_total_eat_count(void);
size_t	getter_philo_id(t_philo *philo);
size_t	getter_eat_count(t_philo *philo);
size_t	getter_last_eat(t_philo *philo);

/* Utils */
t_bool	ft_isdigit(int c);
t_bool	ft_isnumber(char *str);
size_t	ft_strlen(const char *s);
long	ft_atol(const char *nptr);
size_t	ft_atost(const char *nptr);

#endif