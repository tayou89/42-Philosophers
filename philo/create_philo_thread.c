/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 23:29:41 by tayou             #+#    #+#             */
/*   Updated: 2023/07/07 00:46:20 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_thread(t_data *all)
{
	unsigned long long	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		
		i++;
	}
	if (pthread_create(&all->main_thread, 0, main_thread, (void *) all) != 0)
		return (FALSE);
	return (TRUE);
}

void	*main_thread(void *all)
{
	int	end_condition;

	end_condition = FALSE;
	while (end_condition == FALSE)
	{
		if (monitor_every_philo_alive(all) == FALSE)
			end_condition = TRUE;
		if (all->flag.eating_max_exist == TRUE)
		{
			if (check_every_eating_count_is_eating_max(all) == TRUE)
				end_condition = TRUE;
		}
	}
	
}

int	monitor_every_philo_alive(void *all)
{
	unsigned long long	current_time;
	unsigned long long	last_eating_time;
	unsigned long long	i;
	t_philo				*philo_list;

	philo_list = all->philo;
	i = 0;
	while (i < all->argv.philo_number)
	{
		current_time = get_current_time();
		last_eating_time = *(philo_list->last_eating_time);
		if (current_time - last_eating_time > all->argv.lifespan)
		{
			printf("%llu died.\n", philo_list->number);
			return (FALSE);
		}
		philo_list = philo_list->right;
		i++;
	}
	return (TRUE);
}

int	check_every_eating_count_is_eating_max(void *all)
{
	unsigned long long 	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		if (eating_count[i] < all->argv.eating_max)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
