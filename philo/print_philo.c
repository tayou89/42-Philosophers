/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:10:34 by tayou             #+#    #+#             */
/*   Updated: 2023/07/16 23:55:36 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*get_state_string(int philo_state);

void	print_philo(int state, t_philo *philo)
{
	char		*state_string;
	long long	elapsed_time;

	state_string = get_state_string(state);
	pthread_mutex_lock(philo->flag_mutex);
	pthread_mutex_lock(philo->print_mutex);
	elapsed_time = get_elapsed_time(philo->start_time);
	if (*(philo->simulation_stop) == FALSE
		|| (*(philo->simulation_stop) == TRUE && state == DEAD))
	{
		pthread_mutex_unlock(philo->flag_mutex);
		printf("%llu %d %s\n", elapsed_time, philo->number, state_string);
		pthread_mutex_unlock(philo->print_mutex);
	}
	else
	{
		pthread_mutex_unlock(philo->print_mutex);
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
