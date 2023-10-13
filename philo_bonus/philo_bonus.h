/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:22:26 by tayou             #+#    #+#             */
/*   Updated: 2023/07/17 00:20:28 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

# define TRUE				1
# define FALSE				0

# define NORMAL_EXIT		0
# define MALLOC_ERROR		1
# define SEMAPHORE_ERROR	2
# define TIME_ERROR			3
# define FORK_ERROR			4
# define THREAD_ERROR		5

# define THINKING			0
# define EATING				1
# define SLEEPING			2
# define DEAD				3
# define TAKE_FORK			4

typedef struct s_semaphore
{
	sem_t	*fork;
	sem_t	*print;
	sem_t	*full;
	sem_t	*death;
}	t_semaphore;

typedef struct s_philo
{
	int					number;
	int					lifespan;
	int					eating_time;
	int					sleeping_time;
	int					eating_count;
	int					mendatory_eating_count;
	unsigned long long	last_eating_time;
	unsigned long long	start_time;
	t_semaphore			semaphore;
}	t_philo;

typedef struct s_argv
{
	int	philo_number;
	int	lifespan;
	int	eating_time;
	int	sleeping_time;
	int	mendatory_eating_count;
}	t_argv;

typedef struct s_flag
{
	int	mendatory_eating_count_exist;
	int	overflow_occur;
}	t_flag;

typedef struct s_data
{
	t_argv				argv;
	t_flag				flag;
	pid_t				*pid;
	t_philo				philo;	
	t_semaphore			semaphore;
	int					fork_count;
	unsigned long long	start_time;
}	t_data;

void				check_exception(int argc, char **argv, t_data *all);
int					ft_atoi(char *unsigned_number_string, t_data *all);

void				create_data(t_data *all);
void				create_philo_process(t_data *all);

void				execute_parent_process(int i, t_data *all);
void				execute_philo_process(t_philo *philo);
void				create_monitoring_thread(t_philo *philo);
void				take_philo_routine(t_philo *philo);

sem_t				*create_semaphore(char *name, int count);
void				lock_semaphore(sem_t *semaphore, int count);
void				free_semaphore(char *name, sem_t *semaphore);
void				free_every_semaphore(t_data *all);

void				create_thread(void *(*function)(void *), void *arg);
void				*ft_monitoring_philo(void *argv);
void				*ft_monitoring_death(void *data);
void				*ft_monitoring_full(void *data);

void				pass_white_space(char *stirng, int *i);
int					pass_sign(char *string, int *i);
unsigned long long	get_current_time(void);
long long			get_elapsed_time(unsigned long long start_time);
void				print_philo(int state, t_philo *philo);

#endif
