/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_philo_process_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:22:51 by tayou             #+#    #+#             */
/*   Updated: 2023/07/19 15:10:51 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	execute_philo_process(t_philo *philo)
{
	pthread_t	monitoring_thread;

	if (pthread_create(&monitoring_thread, (void *) 0, \
		ft_monitoring_philo_alive, (void *) philo) != 0)
		exit(THREAD_ERROR);
	if (philo->number % 2 == 0)
		usleep(500);
	while (TRUE)
		take_philo_routine(philo);
	if (pthread_join(monitoring_thread, (void *) 0) != 0)
		exit(THREAD_ERROR);
}
