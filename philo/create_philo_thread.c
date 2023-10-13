/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 23:29:41 by tayou             #+#    #+#             */
/*   Updated: 2023/07/22 18:20:26 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_thread(t_data *all)
{
	t_philo	*philo;
	int		i;

	philo = all->philo;
	all->flag.simulation_stop = FALSE;
	i = 0;
	while (i < all->argv.philo_number)
	{
		philo->start_time = all->start_time;
		philo->last_eating_time = all->start_time;
		if (pthread_create(&all->philo_thread[i], (void *) 0, \
			ft_philo_thread, (void *) philo) != 0)
			return (FALSE);
		philo = philo->right;
		i++;
	}
	if (pthread_create(&all->main_thread, 0, ft_main_thread, (void *) all) != 0)
		return (FALSE);
	return (TRUE);
}
