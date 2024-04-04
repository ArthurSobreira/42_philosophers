/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:00:39 by arsobrei          #+#    #+#             */
/*   Updated: 2024/04/03 21:00:39 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include "utils_bonus.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct s_data
{
	struct s_philo	*philos_array;
	sem_t			*print;
	sem_t			*forks;
	size_t			start_time;
	size_t			philo_count;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			total_eat_count;
}				t_data;

typedef	struct s_philo
{
	pid_t			pid;
	size_t			philo_id;
	size_t			eat_count;
	size_t			last_eat;
}				t_philo;

/* Utils */
t_bool	ft_isdigit(int c);
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
void	unlink_semaphores(void);

/* Philo Routine*/
void	philo_life(t_philo *philo);
void	end_philos(t_data *data);

/* Philo Utils */
void	print_status(t_philo *philo, char *msg);
size_t	get_current_time(void);
void	wait_philos(t_data *data);
void	memento_mori(t_philo *philo);

#endif