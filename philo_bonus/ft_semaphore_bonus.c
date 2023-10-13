/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semaphore_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:52:34 by tayou             #+#    #+#             */
/*   Updated: 2023/07/19 14:23:21 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*create_semaphore(char *name, int count)
{
	sem_t	*semaphore;

	sem_unlink(name);
	semaphore = sem_open(name, O_CREAT, 0644, count);
	if (semaphore == (sem_t *) -1)
		exit(SEMAPHORE_ERROR);
	return (semaphore);
}

void	lock_semaphore(sem_t *semaphore, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		sem_wait(semaphore);
		i++;
	}
}

void	free_semaphore(char *name, sem_t *semaphore)
{
	sem_unlink(name);
	sem_close(semaphore);
}

void	free_every_semaphore(t_data *all)
{
	free_semaphore("fork", all->semaphore.fork);
	free_semaphore("print", all->semaphore.print);
	free_semaphore("full", all->semaphore.full);
	free_semaphore("death", all->semaphore.death);
}
