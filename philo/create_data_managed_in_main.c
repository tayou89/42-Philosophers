/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data_managed_in_main.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:34:23 by tayou             #+#    #+#             */
/*   Updated: 2023/07/12 13:45:02 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_data_managed_in_main(t_data *all);
int	malloc_mutex_and_thread(t_data *all);
int	initialize_data_managed_in_main(t_data *all);

int	create_data_managed_in_main(t_data *all)
{
	if (malloc_data_managed_in_main(all) == FALSE)
		return (FALSE);
	if (initialize_data_managed_in_main(all) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	malloc_data_managed_in_main(t_data *all)
{
	int	size;

	size = all->argv.philo_number;
	all->fork = (t_fork *) malloc(sizeof(t_fork) * size);
	if (all->fork == (void *) 0)
		return (FALSE);
	if (malloc_mutex_and_thread(all) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	malloc_mutex_and_thread(t_data *all)
{
	int	size;

	size = all->argv.philo_number;
	all->fork_mutex = \
		(pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * size);
	if (all->fork_mutex == (void *) 0)
		return (FALSE);
	all->eating_data_mutex = \
		(pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * size);
	if (all->eating_data_mutex == (void *) 0)
		return (FALSE);
	all->state_mutex = \
		(pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * size);
	if (all->state_mutex == (void *) 0)
		return (FALSE);
	all->flag_mutex = \
		(pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * size);
	if (all->flag_mutex == (void *) 0)
		return (FALSE);
	all->philo_thread = (pthread_t *) malloc(sizeof(pthread_t) * size);
	if (all->philo_thread == (void *) 0)
		return (FALSE);
	return (TRUE);
}

int	initialize_data_managed_in_main(t_data *all)
{
	int	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		all->fork[i].number = i + 1;
		all->fork[i].state = AVAILABLE;
		if (pthread_mutex_init(&all->fork_mutex[i], (void *) 0) != 0)
			return (FALSE);
		if (pthread_mutex_init(&all->eating_data_mutex[i], (void *) 0) != 0)
			return (FALSE);
		if (pthread_mutex_init(&all->state_mutex[i], (void *) 0) != 0)
			return (FALSE);
		if (pthread_mutex_init(&all->flag_mutex[i], (void *) 0) != 0)
			return (FALSE);
		i++;
	}
	if (pthread_mutex_init(&all->print_mutex, (void *) 0) != 0)
		return (FALSE);
	return (TRUE);
}
