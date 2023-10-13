/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:01:04 by tayou             #+#    #+#             */
/*   Updated: 2023/07/19 11:38:53 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_mallocible_data(t_data *all);
int		malloc_data(t_data *all);
int		malloc_mutex_and_thread(t_data *all);
int		initialize_mallocated_data(t_data *all);

int	create_data(t_data *all)
{
	initialize_mallocible_data(all);
	if (malloc_data(all) == FALSE)
		return (FALSE);
	if (initialize_mallocated_data(all) == FALSE)
		return (FALSE);
	if (make_philo_list(all) == FALSE)
		return (FALSE);
	return (TRUE);
}

void	initialize_mallocible_data(t_data *all)
{
	all->philo = (void *) 0;
	all->fork = (void *) 0;
	all->philo_thread = (void *) 0;
	all->fork_mutex = (void *) 0;
	all->eating_data_mutex = (void *) 0;
	all->flag_mutex = (void *) 0;
}

int	malloc_data(t_data *all)
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
	all->philo_thread = (pthread_t *) malloc(sizeof(pthread_t) * size);
	all->fork_mutex = \
		(pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * size);
	all->eating_data_mutex = \
		(pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * size);
	all->flag_mutex = \
		(pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * size);
	if (all->philo_thread == (void *) 0 || all->fork_mutex == (void *) 0
		|| all->eating_data_mutex == (void *) 0
		|| all->flag_mutex == (void *) 0)
	{
		free_mallocated_data(all);
		return (FALSE);
	}
	return (TRUE);
}

int	initialize_mallocated_data(t_data *all)
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
		if (pthread_mutex_init(&all->flag_mutex[i], (void *) 0) != 0)
			return (FALSE);
		i++;
	}
	if (pthread_mutex_init(&all->print_mutex, (void *) 0) != 0)
		return (FALSE);
	return (TRUE);
}
