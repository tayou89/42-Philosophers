/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:45:24 by tayou             #+#    #+#             */
/*   Updated: 2023/07/05 15:12:57 by tayou            ###   ########.fr       */
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

# define TRUE	1
# define FALSE	0

typedef struct s_argv
{
	unsigned long long	philo_number;
	unsigned long long	lifespan;
	unsigned long long	eating_time;
	unsigned long long	sleeping_time;
	unsigned long long	eating_max;
}	t_argv;

typedef struct s_flag
{
	int	eating_max_exist;
	int	overflow_occur;
}	t_flag;

typedef struct s_data
{
	t_argv	argv;
	t_flag	flag;
}	t_data;

int					check_exception_exist(int argc, char **argv, t_data *all);
unsigned long long	ft_atoull(char *unsigned_number_string, t_data *all);

void				pass_white_space(char *stirng, int *i);
int					pass_sign(char *string, int *i);

#endif
