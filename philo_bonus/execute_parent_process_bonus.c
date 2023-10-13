/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent_process_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:52:19 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 15:24:08 by tayou            ###   ########.fr       */
/*   Updated: 2023/07/24 02:44:40 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_child_process(int i, t_data *all);
void	create_monitoring_thread(t_data *all);
void	wait_philo_process(t_data *all);
void	join_monitoring_thread(t_data *all);

void	execute_parent_process(int i, t_data *all)
{
	if (i < all->argv.philo_number - 1)
		create_child_process(i, all);
	else
	{
		create_monitoring_thread(all);
		wait_philo_process(all);
		join_monitoring_thread(all);
		close_every_semaphore(all);
		exit(all->exit_status);
	}
}

void	create_child_process(int i, t_data *all)
{
	all->pid[i + 1] = fork();
	if (all->pid[i + 1] == -1)
	{
		post_semaphore(all->semaphore.stop_simulation, all->argv.philo_number);
		all->exit_status = FORK_ERROR;
	}
}

void	create_monitoring_thread(t_data *all)
{
	if (pthread_create(&all->thread.monitoring_death, (void *) 0, \
		ft_monitoring_death_occur, (void *) all) != 0)
	{
		post_semaphore(all->semaphore.stop_simulation, all->argv.philo_number);
		all->exit_status = THREAD_ERROR;
		return ;
	}
	if (all->flag.mendatory_eating_count_exist == FALSE)
		return ;
	if (pthread_create(&all->thread.monitoring_full, (void *) 0, \
		ft_monitoring_everyone_full, (void *) all) != 0)
	{
		sem_post(all->semaphore.death);
		all->exit_status = THREAD_ERROR;
	}
}

void	join_monitoring_thread(t_data *all)
{
	pthread_join(all->thread.monitoring_death, (void *) 0);
	if (all->flag.mendatory_eating_count_exist == TRUE)
		pthread_join(all->thread.monitoring_full, (void *) 0);
}

void	wait_philo_process(t_data *all)
{
	int	philo_number;
	int	exit_status;
	int	i;

	philo_number = all->argv.philo_number;
	i = 0;
	while (i < philo_number)
	{
		waitpid(-1, &exit_status, 0);
		if (exit_status != 0)
		{
			all->exit_status = exit_status;
			sem_post(all->semaphore.death);
		}
		i++;
	}
	free(all->pid);
}
