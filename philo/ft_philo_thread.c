/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:18:38 by tayou             #+#    #+#             */
/*   Updated: 2023/07/07 14:36:39 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_thread(void *philo)
{
	if (philo->number % 2 == 0)
		usleep(1000);
	pthread_mutex_lock(philo->mutex);
	take_left_fork(philo);
	take_right_fork(philo);
	
}

void	take_left_fork(void *philo)
{
	if (philo->left != (void *) 0)
	{
		pthread_mutex_lock(philo->left->mutex);
		print_philo(*(philo->start_time), philo->number, TAKE_FORK);
	}
	else
		print_philo(*(philo->start_time), philo->number, TAKE_FORK);
}
		
void	take_right_fork(void *philo)
{
	if (philo->right == (void *) 0)
		return ;
	pthread_mutex_lock(philo->right->mutex);
	print_philo(*(philo->start_time), philo->number, TAKE_FORK);
	print_philo(*(philo->start_time), philo->number, EATING);
	(*(philo->eating_count))++;
	

