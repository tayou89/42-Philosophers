/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:13:42 by tayou             #+#    #+#             */
/*   Updated: 2023/07/12 13:31:06 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_left_fork(t_philo *philo);
void	take_right_fork(t_philo *philo);

void	take_fork(t_philo *philo)
{
	take_left_fork(philo);
	take_right_fork(philo);
}

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	if (*(philo->left_fork_state) == NOT_AVAILABLE)
		return ;
	else
		*(philo->left_fork_state) = NOT_AVAILABLE;
	philo->fork_count++;
	change_philo_state(TAKE_FORK, philo);
	print_philo(philo);
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
	change_philo_state(TAKE_FORK, philo);
	print_philo(philo);
}
