/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:10:09 by tayou             #+#    #+#             */
/*   Updated: 2023/07/08 01:16:40 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	detach_every_philo_thread(t_data *all)
{
	int	i;

	all->flag.detach_philo_thread = TRUE;
	i = 0;
	while (i < all->argv.philo_number)
	{
		if (pthread_detach(all->philo_thread[i]) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
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
