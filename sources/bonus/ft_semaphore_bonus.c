/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semaphore_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:52:34 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 15:28:59 by tayou            ###   ########.fr       */
/*   Updated: 2023/07/24 02:42:55 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*create_semaphore(char *name, int count)
{
	sem_t	*semaphore;

	sem_unlink(name);
	semaphore = sem_open(name, O_CREAT, 0644, count);
	return (semaphore);
}

void	wait_semaphore(sem_t *semaphore, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		sem_wait(semaphore);
		i++;
	}
}

void	post_semaphore(sem_t *semaphore, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (sem_post(semaphore) == -1)
			perror("");
		i++;
	}
}

void	close_semaphore(char *name, sem_t *semaphore)
{
	sem_unlink(name);
	sem_close(semaphore);
}

void	close_every_semaphore(t_data *all)
{
	close_semaphore("fork", all->semaphore.fork);
	close_semaphore("print", all->semaphore.print);
	close_semaphore("death", all->semaphore.death);
	close_semaphore("stop_simulation", all->semaphore.stop_simulation);
	if (all->flag.mendatory_eating_count_exist == TRUE)
		close_semaphore("full", all->semaphore.full);
}
