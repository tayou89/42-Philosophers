/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:30:28 by tayou             #+#    #+#             */
/*   Updated: 2023/07/19 13:36:40 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*get_state_string(int philo_state);

void	print_philo(int state, t_philo *philo)
{
	char		*state_string;
	long long	elapsed_time;

	state_string = get_state_string(state);
	sem_wait(philo->semaphore.print);
	elapsed_time = get_elapsed_time(philo->start_time);
	printf("%llu %d %s\n", elapsed_time, philo->number, state_string);
	if (state != DEAD)
		sem_post(philo->semaphore.print);
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
