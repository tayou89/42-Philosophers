/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:50:22 by tayou             #+#    #+#             */
/*   Updated: 2023/07/17 00:22:56 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_thread(void *(*function)(void *), void *arg)
{
	pthread_t	thread;

	if (pthread_create(&thread, (void *) 0, function, (void *) arg) != 0)
		exit(THREAD_ERROR);
	if (pthread_detach(thread) != 0)
		exit(THREAD_ERROR);
}

void	*ft_monitoring_philo(void *argv)
{
	t_philo		*philo;
	long long	elapsed_time_from_last_eating;

	philo = (t_philo *) argv;
	elapsed_time_from_last_eating = get_elapsed_time(philo->last_eating_time);
	while (elapsed_time_from_last_eating <= philo->lifespan)
	{
		usleep(250);
		elapsed_time_from_last_eating = \
				get_elapsed_time(philo->last_eating_time);
	}
	print_philo(DEAD, philo);
	sem_post(philo->semaphore.death);
	return (philo);
}

void	*ft_monitoring_death(void *data)
{
	t_data	*all;

	all = (t_data *) data;
	sem_wait(all->semaphore.death);
	kill(0, SIGINT);
	free_every_semaphore(all);
	return (all);
}

void	*ft_monitoring_full(void *data)
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
	free_every_semaphore(all);
	return (all);
}
