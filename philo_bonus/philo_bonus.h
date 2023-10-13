/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:22:26 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 15:36:44 by tayou            ###   ########.fr       */
/*   Updated: 2023/07/24 02:48:42 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>

# define TRUE				1
# define FALSE				0

# define NORMAL_EXIT		0
# define MALLOC_ERROR		1
# define SEMAPHORE_ERROR	2
# define FORK_ERROR			3
# define THREAD_ERROR		4

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
	sem_t	*stop_simulation;
	sem_t	*eating_data;
	sem_t	*flag;
}	t_semaphore;

typedef struct s_thread
{
	pthread_t	monitoring_death;
	pthread_t	monitoring_full;
	pthread_t	monitoring_ending;
}	t_thread;

typedef struct s_flag
{
	int	mendatory_eating_count_exist;
	int	overflow_occur;
	int	stop_simulation;
}	t_flag;

typedef struct s_name
{
	char	*eating_data;
	char	*flag;
}	t_name;

typedef struct s_philo
{
	int					number;
	int					lifespan;
	int					eating_time;
	int					sleeping_time;
	int					eating_count;
	int					mendatory_eating_count;
	int					exit_status;
	unsigned long long	last_eating_time;
	unsigned long long	start_time;
	t_name				name;
	t_semaphore			semaphore;
	t_thread			thread;
	t_flag				flag;
}	t_philo;

typedef struct s_argv
{
	int	philo_number;
	int	lifespan;
	int	eating_time;
	int	sleeping_time;
	int	mendatory_eating_count;
}	t_argv;

typedef struct s_data
{
	t_argv				argv;
	t_flag				flag;
	pid_t				*pid;
	t_philo				philo;
	t_semaphore			semaphore;
	t_thread			thread;
	unsigned long long	start_time;
	int					exit_status;
}	t_data;

void				check_exception(int argc, char **argv, t_data *all);
int					ft_atoi(char *unsigned_number_string, t_data *all);

void				create_data(t_data *all);
void				create_philo_process(t_data *all);

void				execute_parent_process(int i, t_data *all);
void				execute_philo_process(t_philo *philo);
void				take_philo_routine(t_philo *philo);

sem_t				*create_semaphore(char *name, int count);
void				wait_semaphore(sem_t *semaphore, int count);
void				post_semaphore(sem_t *semaphore, int count);
void				close_semaphore(char *name, sem_t *semaphore);
void				close_every_semaphore(t_data *all);

void				*ft_monitoring_philo_alive(void *data);
void				*ft_monitoring_ending(void *data);
void				*ft_monitoring_death_occur(void *data);
void				*ft_monitoring_everyone_full(void *data);

void				pass_white_space(char *stirng, int *i);
int					pass_sign(char *string, int *i);
unsigned long long	get_current_time(void);
long long			get_elapsed_time(unsigned long long start_time);

void				print_philo(int state, t_philo *philo);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);

#endif
