/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:10:09 by tayou             #+#    #+#             */
/*   Updated: 2023/07/09 19:40:26 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_every_philo_thread(t_data *all);

void	detach_every_thread(t_data *all)
{
	int	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		pthread_detach(all->philo_thread[i]);
		i++;
	}
	pthread_detach(all->main_thread);
}


int	join_every_thread(t_data *all)
{
	if (join_every_philo_thread(all) == FALSE)
		return (FALSE);
	if (pthread_join(all->main_thread, (void *) 0) != 0)
		return (FALSE);
	return (TRUE);
}

int	join_every_philo_thread(t_data *all)
{
	int	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		if (pthread_join(all->philo_thread[i], (void *) 0) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
