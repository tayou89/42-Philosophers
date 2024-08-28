/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:50:22 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 15:25:02 by tayou            ###   ########.fr       */
/*   Updated: 2023/07/24 02:31:17 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_monitoring_philo_alive(void *data)
{
	t_philo		*philo;
	long long	elapsed_time_from_last_eating;

	philo = (t_philo *) data;
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
		sem_wait(philo->semaphore.flag);
		if (philo->flag.stop_simulation == TRUE)
		{
			sem_post(philo->semaphore.flag);
			return (philo);
		}
		sem_post(philo->semaphore.flag);
	}
	print_philo(DEAD, philo);
	sem_post(philo->semaphore.death);
	return (philo);
}

void	*ft_monitoring_ending(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	sem_wait(philo->semaphore.stop_simulation);
	sem_wait(philo->semaphore.flag);
	philo->flag.stop_simulation = TRUE;
	sem_post(philo->semaphore.flag);
	return (philo);
}

void	*ft_monitoring_death_occur(void *data)
{
	t_data	*all;

	all = (t_data *) data;
	sem_wait(all->semaphore.death);
	post_semaphore(all->semaphore.stop_simulation, all->argv.philo_number);
	if (all->flag.mendatory_eating_count_exist == TRUE)
		post_semaphore(all->semaphore.full, all->argv.philo_number);
	usleep(500);
	post_semaphore(all->semaphore.print, all->argv.philo_number);
	if (all->argv.philo_number == 1)
		sem_post(all->semaphore.fork);
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
	post_semaphore(all->semaphore.stop_simulation, all->argv.philo_number);
	sem_post(all->semaphore.death);
	return (all);
}
