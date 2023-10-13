/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_philo_routine_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:45:38 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 15:29:37 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_fork(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep_and_think(t_philo *philo);
void	pass_time(int time_to_pass);

void	take_philo_routine(t_philo *philo)
{
	take_fork(philo);
	take_fork(philo);
	philo_eat(philo);
	philo_sleep_and_think(philo);
}

void	take_fork(t_philo *philo)
{
	sem_wait(philo->semaphore.fork);
	print_philo(TAKE_FORK, philo);
}

void	philo_eat(t_philo *philo)
{
	sem_wait(philo->semaphore.eating_data);
	philo->last_eating_time = get_current_time();
	sem_post(philo->semaphore.eating_data);
	print_philo(EATING, philo);
	pass_time(philo->eating_time);
}

void	philo_sleep_and_think(t_philo *philo)
{
	print_philo(SLEEPING, philo);
	philo->eating_count++;
	if (philo->mendatory_eating_count != 0
		&& philo->eating_count == philo->mendatory_eating_count)
		sem_post(philo->semaphore.full);
	sem_post(philo->semaphore.fork);
	sem_post(philo->semaphore.fork);
	pass_time(philo->sleeping_time);
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
