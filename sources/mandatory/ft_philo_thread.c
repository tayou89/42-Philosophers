/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:18:38 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 14:57:50 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_thread(void *philo_structure)
{
	t_philo	*philo;

	philo = (t_philo *) philo_structure;
	if (philo->number % 2 == 0)
		usleep(200);
	pthread_mutex_lock(philo->flag_mutex);
	while (*(philo->simulation_stop) == FALSE)
	{
		pthread_mutex_unlock(philo->flag_mutex);
		take_left_fork(philo);
		take_right_fork(philo);
		take_philo_routine(philo);
		pthread_mutex_lock(philo->flag_mutex);
	}
	pthread_mutex_unlock(philo->flag_mutex);
	return (philo);
}
