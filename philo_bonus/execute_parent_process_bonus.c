/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent_process_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:52:19 by tayou             #+#    #+#             */
/*   Updated: 2023/07/17 00:25:34 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_philo_process(t_data *all);

void	execute_parent_process(int i, t_data *all)
{
	if (i < all->argv.philo_number - 1)
	{
		all->pid[i + 1] = fork();
		if (all->pid[i + 1] == -1)
			exit(FORK_ERROR);
	}
	else
	{
		create_thread(ft_monitoring_death, all);
		create_thread(ft_monitoring_full, all);
		wait_philo_process(all);
		free_every_semaphore(all);
		exit(0);
	}
}

void	wait_philo_process(t_data *all)
{
	int	exit_status;
	int	i;

	exit_status = 0;
	i = 0;
	while (i < all->argv.philo_number)
	{
		waitpid(-1, &exit_status, 0);
		if (exit_status != 0)
		{
			free_every_semaphore(all);
			kill(0, SIGINT);
			exit(WEXITSTATUS(exit_status));
		}
		i++;
	}
}
