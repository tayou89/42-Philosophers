/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:45:24 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 15:07:34 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define TRUE			1
# define FALSE			0

# define AVAILABLE		1
# define NOT_AVAILABLE	0

# define THINKING		0
# define EATING			1
# define SLEEPING		2
# define DEAD			3
# define TAKE_FORK		4

typedef struct s_fork
{
	int	number;
	int	state;
}	t_fork;

typedef struct s_philo
{
	int					number;
	int					fork_count;
	int					eating_time;
	int					sleeping_time;
	int					eating_count;
	int					*simulation_stop;
	int					*left_fork_state;
	int					*right_fork_state;
	unsigned long long	last_eating_time;
	unsigned long long	start_time;
	pthread_mutex_t		*left_fork_mutex;
	pthread_mutex_t		*right_fork_mutex;
	pthread_mutex_t		*eating_data_mutex;
	pthread_mutex_t		*flag_mutex;
	pthread_mutex_t		*print_mutex;
	struct s_philo		*left;
	struct s_philo		*right;
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
	int	simulation_stop;
}	t_flag;

typedef struct s_data
{
	t_argv				argv;
	t_flag				flag;
	t_philo				*philo;
	t_fork				*fork;
	pthread_t			*philo_thread;
	pthread_t			main_thread;
	pthread_mutex_t		*fork_mutex;
	pthread_mutex_t		*eating_data_mutex;
	pthread_mutex_t		*flag_mutex;
	pthread_mutex_t		print_mutex;
	unsigned long long	start_time;
	int					exit_status;
}	t_data;

int					check_exception_exist(int argc, char **argv, t_data *all);
int					ft_atoi(char *unsigned_number_string, t_data *all);

int					create_data(t_data *all);
int					make_philo_list(t_data *all);

int					create_philo_thread(t_data *all);
void				*ft_main_thread(void *all);
void				*ft_philo_thread(void *all);

void				take_left_fork(t_philo *philo);
void				take_right_fork(t_philo *philo);
void				put_down_left_fork(t_philo *philo);
void				put_down_right_fork(t_philo *philo);
void				take_philo_routine(t_philo *philo);

void				pass_white_space(char *stirng, int *i);
int					pass_sign(char *string, int *i);
unsigned long long	get_current_time(void);
long long			get_elapsed_time(unsigned long long start_time);
void				print_philo(int state, t_philo *philo);

void				join_every_thread(t_data *all);
void				lock_mutex_array(pthread_mutex_t *mutex, t_data *all);
void				unlock_mutex_array(pthread_mutex_t *mutex, t_data *all);
void				destroy_mutex_array(pthread_mutex_t *mutex, t_data *all);
void				destroy_every_mutex(t_data *all);

void				free_mallocated_data(t_data *all);
void				free_linked_list(t_philo *philo);

#endif
