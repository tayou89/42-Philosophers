/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_philo_process_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:22:51 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 15:11:48 by tayou            ###   ########.fr       */
/*   Updated: 2023/07/24 02:48:59 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_philo_semaphore(t_philo *philo);
char	*get_semaphore_name(char *name, int philo_number);
void	create_thread(t_philo *philo);
void	join_thread(t_philo *philo);

void	execute_philo_process(t_philo *philo)
{
	create_philo_semaphore(philo);
	create_thread(philo);
	if (philo->number % 2 == 0)
		usleep(60000);
	sem_wait(philo->semaphore.flag);
	while (philo->flag.stop_simulation == FALSE)
	{
		sem_post(philo->semaphore.flag);
		take_philo_routine(philo);
		sem_wait(philo->semaphore.flag);
	}
	sem_post(philo->semaphore.flag);
	join_thread(philo);
	exit(philo->exit_status);
}

void	create_philo_semaphore(t_philo *philo)
{
	philo->name.eating_data = get_semaphore_name("eating_data_", philo->number);
	philo->name.flag = get_semaphore_name("flag_", philo->number);
	philo->semaphore.eating_data = create_semaphore(philo->name.eating_data, 1);
	if (philo->semaphore.eating_data == (sem_t *) -1)
		exit(SEMAPHORE_ERROR);
	philo->semaphore.flag = create_semaphore(philo->name.flag, 1);
	if (philo->semaphore.flag == (sem_t *) -1)
		exit(SEMAPHORE_ERROR);
}

char	*get_semaphore_name(char *name, int philo_number)
{
	char	*semaphore_name;
	char	*number;

	number = ft_itoa(philo_number);
	if (number == (void *) 0)
		exit(MALLOC_ERROR);
	semaphore_name = ft_strjoin(name, number);
	if (semaphore_name == (void *) 0)
		exit(MALLOC_ERROR);
	free(number);
	return (semaphore_name);
}

void	create_thread(t_philo *philo)
{
	if (pthread_create(&philo->thread.monitoring_death, (void *) 0, \
		ft_monitoring_philo_alive, (void *) philo) != 0)
		exit(THREAD_ERROR);
	if (pthread_create(&philo->thread.monitoring_ending, (void *) 0, \
		ft_monitoring_ending, (void *) philo) != 0)
	{
		sem_wait(philo->semaphore.flag);
		philo->flag.stop_simulation = TRUE;
		sem_post(philo->semaphore.flag);
		philo->exit_status = THREAD_ERROR;
	}
}

void	join_thread(t_philo *philo)
{
	pthread_join(philo->thread.monitoring_death, (void *) 0);
	pthread_join(philo->thread.monitoring_ending, (void *) 0);
}
