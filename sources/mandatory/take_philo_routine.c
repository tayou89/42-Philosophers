/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_philo_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:10:57 by tayou             #+#    #+#             */
/*   Updated: 2023/07/22 18:22:37 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	pass_time(int time_to_pass);

void	take_philo_routine(t_philo *philo)
{
	if (philo->fork_count < 2)
		return ;
	philo_eat(philo);
	philo_sleep(philo);
	philo_think(philo);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->eating_data_mutex);
	philo->last_eating_time = get_current_time();
	pthread_mutex_unlock(philo->eating_data_mutex);
	print_philo(EATING, philo);
	pass_time(philo->eating_time);
}

void	philo_sleep(t_philo *philo)
{
	print_philo(SLEEPING, philo);
	put_down_right_fork(philo);
	put_down_left_fork(philo);
	pthread_mutex_lock(philo->eating_data_mutex);
	philo->eating_count++;
	pthread_mutex_unlock(philo->eating_data_mutex);
	pass_time(philo->sleeping_time);
}

void	philo_think(t_philo *philo)
{
	print_philo(THINKING, philo);
}

void	pass_time(int time_to_pass)
{
	unsigned long long	start_time;
	long long			elapsed_time;

	start_time = get_current_time();
	elapsed_time = get_elapsed_time(start_time);
	while (elapsed_time < (long long) time_to_pass)
	{
		usleep(250);
		elapsed_time = get_elapsed_time(start_time);
	}
}
