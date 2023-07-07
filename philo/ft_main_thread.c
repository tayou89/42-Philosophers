/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:00:30 by tayou             #+#    #+#             */
/*   Updated: 2023/07/07 14:03:49 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitor_every_philo_alive(void *all);
int	check_every_eating_count_is_eating_max(void *all);

void	*ft_main_thread(void *all)
{
	int	end_condition;

	all->flag.detach_philo_thread = FALSE;
	end_condition = FALSE;
	while (end_condition == FALSE)
	{
		if (monitor_every_philo_alive(all) == FALSE)
		{
			detach_every_philo_thread(all);
			print_philo_status(all->start_time, all->dead_philo_number, DEAD);
			end_condition = TRUE;
		}
		if (all->flag.eating_max_exist == TRUE)
		{
			if (check_every_eating_count_is_eating_max(all) == TRUE)
			{
				detach_every_philo_thread(all);
				end_condition = TRUE;
			}
		}
	}
}

int	monitor_every_philo_alive(void *all)
{
	unsigned long long	current_time;
	unsigned long long	last_eating_time;
	int					i;
	t_philo				*philo_list;

	philo_list = all->philo;
	i = 0;
	while (i < all->argv.philo_number)
	{
		current_time = get_current_time();
		last_eating_time = *(philo_list->last_eating_time);
		if (current_time - last_eating_time > all->argv.lifespan)
		{
			all->dead_philo_number = philo_list->number;
			return (FALSE);
		}
		philo_list = philo_list->right;
		i++;
	}
	return (TRUE);
}

int	check_every_eating_count_is_eating_max(void *all)
{
	int	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		if (eating_count[i] < all->argv.eating_max)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
