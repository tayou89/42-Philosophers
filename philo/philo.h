/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:45:24 by tayou             #+#    #+#             */
/*   Updated: 2023/07/07 14:36:44 by tayou            ###   ########.fr       */
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

# define TRUE		1
# define FALSE		0

# define THINKING	0
# define EATING		1
# define SLEEPING	2
# define DEAD		3
# define TAKE_FORK	4

typedef struct s_philo
{
	int					number;
	int					lifespan;
	int					*eating_count;
	unsigned long long	*last_eating_time;
	unsigned long long	*start_time;
	int					status;
	int					*left_fork;
	int					*right_fork;
	int					fork_count;
	pthread_mutex_t		*mutex;
	struct s_philo		*left;
	struct s_philo		*right;
}	t_philo;

typedef struct s_argv
{
	int	philo_number;
	int	lifespan;
	int	eating_time;
	int	sleeping_time;
	int	eating_max;
}	t_argv;

typedef struct s_flag
{
	int	eating_max_exist;
	int	overflow_occur;
	int	detach_philo_thread;
}	t_flag;

typedef struct s_data
{
	t_argv				argv;
	t_flag				flag;
	t_philo				*philo;
	pthread_t			*philo_thread;
	pthread_t			main_thread;
	pthread_mutex_t		*mutex;
	int					*eating_count;
	unsigned long long	*last_eating_time;
	unsigned long long	start_time;
	int					*fork;
	int					index;
	int					dead_philo_number;
}	t_data;

int					check_exception_exist(int argc, char **argv, t_data *all);
int					ft_atoi(char *unsigned_number_string, t_data *all);

int					create_data_managed_in_main(t_data *all);
int					make_philo_list(t_data *all);

int					create_philo_thread(t_data *all);
void				*ft_main_thread(void *all);


void				pass_white_space(char *stirng, int *i);
int					pass_sign(char *string, int *i);
unsigned long long	get_current_time(void);
void				print_philo(unsigned long long start, int n, int status);

int					detach_every_philo_thread(t_data *all);
int					join_every_thread(t_data *all);
int					join_every_philo_thread(t_data *all);

void				print_data(t_data *all);

#endif
