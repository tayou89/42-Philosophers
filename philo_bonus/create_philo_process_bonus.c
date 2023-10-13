/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_process_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:14:28 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 14:20:27 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_philo_process(t_data *all)
{
	int	i;

	i = 0;
	all->pid[i] = fork();
	if (all->pid[i] == -1)
		exit(FORK_ERROR);
	while (i < all->argv.philo_number)
	{
		if (all->pid[i] == 0)
		{
			all->philo.number = i + 1;
			execute_philo_process(&all->philo);
			break ;
		}
		else
			execute_parent_process(i, all);
		i++;
	}
}
