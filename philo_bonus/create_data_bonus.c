/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:55:28 by tayou             #+#    #+#             */
/*   Updated: 2023/07/16 23:32:59 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	make_semaphore_setting(t_data *all);
void	malloc_pid(t_data *all);
void	make_philo(t_data *all);

void	create_data(t_data *all)
{
	make_semaphore_setting(all);
	malloc_pid(all);
	make_philo(all);
	all->start_time = get_current_time();
}

void	make_semaphore_setting(t_data *all)
{
	all->semaphore.fork = create_semaphore("fork", all->argv.philo_number);
	all->semaphore.print = create_semaphore("print", 1);
	all->semaphore.full = create_semaphore("full", all->argv.philo_number);
	all->semaphore.death = create_semaphore("death", 1);
	lock_semaphore(all->semaphore.full, all->argv.philo_number);
	lock_semaphore(all->semaphore.death, 1);
}

void	malloc_pid(t_data *all)
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
	all->philo.eating_count = 0;
	all->philo.mendatory_eating_count = all->argv.mendatory_eating_count;
	all->philo.semaphore.fork = all->semaphore.fork;
	all->philo.semaphore.print = all->semaphore.print;
	all->philo.semaphore.full = all->semaphore.full;
	all->philo.semaphore.death = all->semaphore.death;
}
