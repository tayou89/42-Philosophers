/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mallocated_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:57:33 by tayou             #+#    #+#             */
/*   Updated: 2023/07/22 14:34:31 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_linked_list(t_philo *philo);
void	free_every_array(t_data *all);

void	free_mallocated_data(t_data *all)
{
	free_linked_list(all->philo);
	free_every_array(all);
}

void	free_linked_list(t_philo *philo)
{
	t_philo	*head;

	while (philo->right != (void *) 0)
	{
		philo->right->left = (void *) 0;
		if (philo->left != (void *) 0)
			philo->left->right = (void *) 0;
		head = philo;
		philo = philo->right;
		free(head);
		head = (void *) 0;
	}
	free(philo);
	philo = (void *) 0;
}

void	free_every_array(t_data *all)
{
	if (all->fork != (void *) 0)
		free(all->fork);
	if (all->philo_thread != (void *) 0)
		free(all->philo_thread);
	if (all->fork_mutex != (void *) 0)
		free(all->fork_mutex);
	if (all->eating_data_mutex != (void *) 0)
		free(all->eating_data_mutex);
	if (all->flag_mutex != (void *) 0)
		free(all->flag_mutex);
	all->fork = (void *) 0;
	all->philo_thread = (void *) 0;
	all->fork_mutex = (void *) 0;
	all->eating_data_mutex = (void *) 0;
	all->flag_mutex = (void *) 0;
}
