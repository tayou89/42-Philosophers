/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_down_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:13:59 by tayou             #+#    #+#             */
/*   Updated: 2023/07/13 14:24:03 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_down_left_fork(t_philo *philo);
void	put_down_right_fork(t_philo *philo);

void	put_down_fork(t_philo *philo)
{
	put_down_right_fork(philo);
	put_down_left_fork(philo);
}

void	put_down_left_fork(t_philo *philo)
{
	*(philo->left_fork_state) = AVAILABLE;
	philo->fork_count--;
}

void	put_down_right_fork(t_philo *philo)
{
	*(philo->right_fork_state) = AVAILABLE;
	philo->fork_count--;
}
