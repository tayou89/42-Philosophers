/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:10:09 by tayou             #+#    #+#             */
/*   Updated: 2023/07/22 18:39:58 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_every_thread(t_data *all)
{
	int	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		pthread_join(all->philo_thread[i], (void *) 0);
		i++;
	}
	pthread_join(all->main_thread, (void *) 0);
}

void	unlock_mutex_array(pthread_mutex_t *mutex, t_data *all)
{
	int	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		pthread_mutex_unlock(&mutex[i]);
		i++;
	}
}

void	destroy_mutex_array(pthread_mutex_t *mutex, t_data *all)
{
	int	i;

	unlock_mutex_array(mutex, all);
	i = 0;
	while (i < all->argv.philo_number)
	{
		pthread_mutex_destroy(&mutex[i]);
		i++;
	}
}

void	destroy_every_mutex(t_data *all)
{
	destroy_mutex_array(all->fork_mutex, all);
	destroy_mutex_array(all->eating_data_mutex, all);
	destroy_mutex_array(all->flag_mutex, all);
	pthread_mutex_unlock(&all->print_mutex);
	pthread_mutex_destroy(&all->print_mutex);
}
