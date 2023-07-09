/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 23:29:41 by tayou             #+#    #+#             */
/*   Updated: 2023/07/09 23:40:47 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_thread(t_data *all)
{
	t_philo	*philo_list;
	int		i;

	philo_list = all->philo;
	all->flag.simulation_stop = FALSE;
	i = 0;
	while (i < all->argv.philo_number)
	{
		philo_list->start_time = all->start_time;
		if (pthread_create(&all->philo_thread[i], (void *) 0, \
			ft_philo_thread, (void *) philo_list) != 0)
			return (FALSE);
		philo_list = philo_list->right;
		i++;
	}
	if (pthread_create(&all->main_thread, 0, ft_main_thread, (void *) all) != 0)
		return (FALSE);
	return (TRUE);
}
