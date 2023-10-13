/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent_process_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:52:19 by tayou             #+#    #+#             */
/*   Updated: 2023/07/21 12:51:02 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_child_process(int i, t_data *all);
void	create_monitoring_thread(t_data *all);
void	wait_philo_process(t_data *all);

void	execute_parent_process(int i, t_data *all)
{
	if (i < all->argv.philo_number - 1)
		create_child_process(i, all);
	else
	{
		create_monitoring_thread(all);
		wait_philo_process(all);
	}
}

void	create_child_process(int i, t_data *all)
{
	all->pid[i + 1] = fork();
	if (all->pid[i + 1] == -1)
		kill(0, SIGINT);
}

void	create_monitoring_thread(t_data *all)
{
	if (pthread_create(&all->thread.monitoring_death, (void *) 0, \
		ft_monitoring_death_occur, (void *) all) != 0)
		kill(0, SIGINT);
	if (pthread_create(&all->thread.monitoring_full, (void *) 0, \
		ft_monitoring_everyone_full, (void *) all) != 0)
		kill(0, SIGINT);
	if (pthread_detach(all->thread.monitoring_death) != 0)
		kill(0, SIGINT);
	if (pthread_detach(all->thread.monitoring_full) != 0)
		kill(0, SIGINT);
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
			kill(0, SIGINT);
		i++;
	}
}
