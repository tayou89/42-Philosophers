/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:55:28 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 15:22:29 by tayou            ###   ########.fr       */
/*   Updated: 2023/07/24 02:42:21 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	malloc_array_data(t_data *all);
void	make_semaphore_setting(t_data *all);
void	make_philo(t_data *all);

void	create_data(t_data *all)
{
	make_semaphore_setting(all);
	malloc_array_data(all);
	all->start_time = get_current_time();
	make_philo(all);
	all->exit_status = NORMAL_EXIT;
}

void	make_semaphore_setting(t_data *all)
{
	all->semaphore.fork = create_semaphore("fork", all->argv.philo_number);
	if (all->semaphore.fork == (sem_t *) -1)
		exit(SEMAPHORE_ERROR);
	all->semaphore.print = create_semaphore("print", 1);
	if (all->semaphore.print == (sem_t *) -1)
		exit(SEMAPHORE_ERROR);
	all->semaphore.death = create_semaphore("death", 1);
	if (all->semaphore.death == (sem_t *) -1)
		exit(SEMAPHORE_ERROR);
	all->semaphore.stop_simulation = \
			create_semaphore("stop_simulation", all->argv.philo_number);
	if (all->semaphore.stop_simulation == (sem_t *) -1)
		exit(SEMAPHORE_ERROR);
	wait_semaphore(all->semaphore.stop_simulation, all->argv.philo_number);
	wait_semaphore(all->semaphore.death, 1);
	if (all->flag.mendatory_eating_count_exist == FALSE)
		return ;
	all->semaphore.full = create_semaphore("full", all->argv.philo_number);
	if (all->semaphore.full == (sem_t *) -1)
		exit(SEMAPHORE_ERROR);
	wait_semaphore(all->semaphore.full, all->argv.philo_number);
}

void	malloc_array_data(t_data *all)
{
	all->pid = (pid_t *) malloc(sizeof(pid_t) * all->argv.philo_number);
	if (all->pid == (void *) 0)
		exit(MALLOC_ERROR);
}

void	make_philo(t_data *all)
{
	all->philo.number = 0;
	all->philo.lifespan = all->argv.lifespan;
	all->philo.eating_time = all->argv.eating_time;
	all->philo.sleeping_time = all->argv.sleeping_time;
	all->philo.start_time = all->start_time;
	all->philo.last_eating_time = all->start_time;
	all->philo.eating_count = 0;
	all->philo.mendatory_eating_count = all->argv.mendatory_eating_count;
	all->philo.semaphore.fork = all->semaphore.fork;
	all->philo.semaphore.print = all->semaphore.print;
	all->philo.semaphore.full = all->semaphore.full;
	all->philo.semaphore.death = all->semaphore.death;
	all->philo.semaphore.stop_simulation = all->semaphore.stop_simulation;
	all->philo.flag.stop_simulation = FALSE;
	all->philo.exit_status = NORMAL_EXIT;
}
