/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:23:09 by tayou             #+#    #+#             */
/*   Updated: 2023/07/16 23:58:20 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	if (*(philo->left_fork_state) == NOT_AVAILABLE)
		return ;
	else
		*(philo->left_fork_state) = NOT_AVAILABLE;
	philo->fork_count++;
	print_philo(TAKE_FORK, philo);
}

void	take_right_fork(t_philo *philo)
{
	if (philo->right_fork_mutex == (void *) 0)
		return ;
	pthread_mutex_lock(philo->right_fork_mutex);
	if (*(philo->right_fork_state) == NOT_AVAILABLE)
		return ;
	else
		*(philo->right_fork_state) = NOT_AVAILABLE;
	philo->fork_count++;
	print_philo(TAKE_FORK, philo);
}

void	put_down_left_fork(t_philo *philo)
{
	*(philo->left_fork_state) = AVAILABLE;
	philo->fork_count--;
	pthread_mutex_unlock(philo->left_fork_mutex);
}

void	put_down_right_fork(t_philo *philo)
{
	*(philo->right_fork_state) = AVAILABLE;
	philo->fork_count--;
	pthread_mutex_unlock(philo->right_fork_mutex);
}
