/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:01:29 by tayou             #+#    #+#             */
/*   Updated: 2023/07/10 15:09:53 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*get_state_string(int philo_state);

void	pass_white_space(char *string, int *i)
{
	while ((string[*i] >= 9 && string[*i] <= 13) || string[*i] == 32)
		(*i)++;
}

int	pass_sign(char *string, int *i)
{
	if (string[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	else if (string[*i] == '+')
	{
		(*i)++;
		return (1);
	}
	else
		return (1);
}

unsigned long long	get_current_time(void)
{
	unsigned long long	current_time;
	struct timeval		time;

	if (gettimeofday(&time, (void *) 0) == -1)
	{
		printf("Error. gettimeofday failed.\n");
		return (FALSE);
	}
	current_time = \
		(unsigned long long) (time.tv_sec * 1000) + \
		(unsigned long long) (time.tv_usec / 1000);
	return (current_time);
}

long long get_elapsed_time(unsigned long long start_time)
{
	unsigned long long	current_time;
	long long			elapsed_time;

	current_time = get_current_time();
	elapsed_time = (long long) (current_time - start_time);
	return (elapsed_time);
}

void	print_philo(long long elapsed_time, t_philo *philo)
{
	char		*state_string;

	pthread_mutex_lock(philo->state_mutex);
	pthread_mutex_lock(philo->flag_mutex);
	state_string = get_state_string(philo->state);
	pthread_mutex_lock(philo->print_mutex);	
	if (*(philo->simulation_stop) == FALSE
		|| (*(philo->simulation_stop) == TRUE && philo->state == DEAD))
	{
		pthread_mutex_unlock(philo->state_mutex);
		pthread_mutex_unlock(philo->flag_mutex);
		printf("%llu %d %s\n", elapsed_time, philo->number, state_string);
		pthread_mutex_unlock(philo->print_mutex);
	}
	else
	{
		pthread_mutex_unlock(philo->print_mutex);
		pthread_mutex_unlock(philo->state_mutex);
		pthread_mutex_unlock(philo->flag_mutex);
	}
}

char	*get_state_string(int philo_state)
{
	if (philo_state == THINKING)
		return ("is thinking");
	else if (philo_state == EATING)
		return ("is eating");
	else if (philo_state == SLEEPING)
		return ("is sleeping");
	else if (philo_state == DEAD)
		return ("died");
	else
		return ("has taken a fork");
}

void	change_philo_state(int state, t_philo *philo)
{
	pthread_mutex_lock(philo->state_mutex);
	philo->state = state;
	pthread_mutex_unlock(philo->state_mutex);
}
