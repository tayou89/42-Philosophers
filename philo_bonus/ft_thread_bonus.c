/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:50:22 by tayou             #+#    #+#             */
/*   Updated: 2023/07/21 12:10:00 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_monitoring_philo_alive(void *argv)
{
	t_philo		*philo;
	long long	elapsed_time_from_last_eating;

	philo = (t_philo *) argv;
	sem_wait(philo->semaphore.eating_data);
	elapsed_time_from_last_eating = get_elapsed_time(philo->last_eating_time);
	sem_post(philo->semaphore.eating_data);
	while (elapsed_time_from_last_eating <= philo->lifespan)
	{
		usleep(250);
		sem_wait(philo->semaphore.eating_data);
		elapsed_time_from_last_eating = \
							get_elapsed_time(philo->last_eating_time);
		sem_post(philo->semaphore.eating_data);
	}
	print_philo(DEAD, philo);
	sem_post(philo->semaphore.death);
	return (philo);
}

void	*ft_monitoring_death_occur(void *data)
{
	t_data	*all;

	all = (t_data *) data;
	sem_wait(all->semaphore.death);
	kill(0, SIGINT);
	return (all);
}

void	*ft_monitoring_everyone_full(void *data)
{
	t_data	*all;
	int		i;

	all = (t_data *) data;
	i = 0;
	while (i < all->argv.philo_number)
	{
		sem_wait(all->semaphore.full);
		i++;
	}
	kill(0, SIGINT);
	return (all);
}
