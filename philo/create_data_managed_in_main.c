/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data_managed_in_main.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:34:23 by tayou             #+#    #+#             */
/*   Updated: 2023/07/07 00:31:26 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_data_managed_in_main(t_data *all);
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
	all->fork = (int *) malloc(sizeof(int) * size);
	if (all->fork == (void *) 0)
		return (FALSE);
	all->last_eating_time = \
		(unsigned long long *) malloc(sizeof(unsigned long long) * size);
	if (all->last_eating_time == (void *) 0)
		return (FALSE);
	all->eating_count = \
		(unsigned long long *) malloc(sizeof(unsigned long long) * size);
	if (all->eating_count == (void *) 0)
		return (FALSE);
	all->mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * size);
	if (all->mutex == (void *) 0)
		return (FALSE);
	all->philo_thread = (pthread_t *) malloc(sizeof(pthread_t) * size);
	if (all->philo_thread == (void *) 0)
		return (FALSE);
	return (TRUE);
}

int	initialize_data_managed_in_main(t_data *all)
{
	unsigned long long	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		all->fork[i] = 1;
		all->last_eating_time[i] = 0;
		all->eating_count[i] = 0;
		if (pthread_mutex_init(&all->mutex[i], (void *) 0) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
