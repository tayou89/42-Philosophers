/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_philo_process_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:22:51 by tayou             #+#    #+#             */
/*   Updated: 2023/07/16 22:46:00 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	execute_philo_process(t_philo *philo)
{
	create_thread(ft_monitoring_philo, (void *) philo);
	if (philo->number % 2 == 0)
		usleep(500);
	while (TRUE)
		take_philo_routine(philo);
}
