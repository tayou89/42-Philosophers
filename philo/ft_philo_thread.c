/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:18:38 by tayou             #+#    #+#             */
/*   Updated: 2023/07/08 01:30:36 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pass_time(int time_to_pass);
void	take_left_fork(t_philo *philo);
void	take_right_fork(t_philo *philo);
void	sleep_and_think(t_philo *philo);

void	*ft_philo_thread(void *philo_structure)
{
	t_philo	*philo;

	philo = (t_philo *) philo_structure;
	if (philo->number % 2 == 0)
		usleep(1000);
	while (*(philo->end_condition) == FALSE)
	{
		take_left_fork(philo);
		take_right_fork(philo);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		sleep_and_think(philo);
	}
	return (philo);
}

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_philo(*(philo->start_time), philo->number, TAKE_FORK);
}

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_philo(*(philo->start_time), philo->number, TAKE_FORK);
	print_philo(*(philo->start_time), philo->number, EATING);
	*(philo->last_eating_time) = get_current_time();
	(*(philo->eating_count))++;
	pass_time(*(philo->eating_time));
}

void	sleep_and_think(t_philo *philo)
{
	print_philo(*(philo->start_time), philo->number, SLEEPING);
	pass_time(*(philo->sleeping_time));
	print_philo(*(philo->start_time), philo->number, THINKING);
}

void	pass_time(int time_to_pass)
{
	unsigned long long	start_time;
	unsigned long long	after_time;
	unsigned long long	elapsed_time;

	start_time = get_current_time();
	after_time = get_current_time();
	elapsed_time = after_time - start_time;
	while (elapsed_time < (unsigned long long) time_to_pass)
	{
		usleep(10);
		after_time = get_current_time();
		elapsed_time = after_time - start_time;
	}
}
