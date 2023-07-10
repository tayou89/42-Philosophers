/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:13:42 by tayou             #+#    #+#             */
/*   Updated: 2023/07/10 15:04:09 by tayou            ###   ########.fr       */
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
	long long	elapsed_time;

	pthread_mutex_lock(philo->left_fork_mutex);
	*(philo->left_fork_state) = NOT_AVAILABLE;
	philo->fork_count++;
	change_philo_state(TAKE_FORK, philo);
	elapsed_time = get_elapsed_time(philo->start_time);
	print_philo(elapsed_time, philo);
}

void	take_right_fork(t_philo *philo)
{
	long long	elapsed_time;

	pthread_mutex_lock(philo->right_fork_mutex);
	*(philo->right_fork_state) = NOT_AVAILABLE;
	philo->fork_count++;
	change_philo_state(TAKE_FORK, philo);
	elapsed_time = get_elapsed_time(philo->start_time);
	print_philo(elapsed_time, philo);
}
