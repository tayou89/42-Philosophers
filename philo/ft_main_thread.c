/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:00:30 by tayou             #+#    #+#             */
/*   Updated: 2023/07/08 01:17:38 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitor_every_philo_alive(t_data *all);
int	check_every_eating_count_is_eating_max(t_data *all);

void	*ft_main_thread(void *data)
{
	t_data	*all;

	all = (t_data *) data;
	all->flag.detach_philo_thread = FALSE;
	while (all->flag.end_condition == FALSE)
	{
		if (monitor_every_philo_alive(all) == FALSE)
		{
			all->flag.end_condition = TRUE;
			detach_every_philo_thread(all);
			print_philo(all->start_time, all->dead_philo_number, DEAD);
		}
		if (all->flag.eating_max_exist == TRUE)
		{
			all->flag.end_condition = TRUE;
			if (check_every_eating_count_is_eating_max(all) == TRUE)
				detach_every_philo_thread(all);
		}
	}
	return (data);
}

int	monitor_every_philo_alive(t_data *all)
{
	unsigned long long	current_time;
	unsigned long long	last_eating_time;
	unsigned long long	lifespan;
	t_philo				*philo_list;
	int					i;

	lifespan = (unsigned long long) all->argv.lifespan;
	philo_list = all->philo;
	i = 0;
	while (i < all->argv.philo_number)
	{
		current_time = get_current_time();
		last_eating_time = *(philo_list->last_eating_time);
		if (current_time - last_eating_time > lifespan)
		{
			all->dead_philo_number = philo_list->number;
			return (FALSE);
		}
		philo_list = philo_list->right;
		i++;
	}
	return (TRUE);
}

int	check_every_eating_count_is_eating_max(t_data *all)
{
	int	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		if (all->eating_count[i] < all->argv.eating_max)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
