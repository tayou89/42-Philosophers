/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:18:38 by tayou             #+#    #+#             */
/*   Updated: 2023/07/09 20:04:54 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_thread(void *philo_structure)
{
	t_philo	*philo;

	philo = (t_philo *) philo_structure;
	if (philo->number % 2 == 0)
		usleep(1000);
	while (*(philo->simulation_stop) == FALSE)
	{
		if (philo->state == THINKING)
			take_fork(philo);
		if (philo->fork_count == 2)
			take_philo_routine(philo);
	}
	return (philo);
}
