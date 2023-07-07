/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:18:38 by tayou             #+#    #+#             */
/*   Updated: 2023/07/07 13:34:54 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_thread(void *philo)
{
	if (philo->number % 2 == 0)
		usleep(1000);
	pthread_mutex_lock(philo->mutex);
	pthread_mutex_lock(philo->left->mutex);
	printf("%llu has taken a fork.\n", philo->number);
	pthread_mutex_lock(philo
