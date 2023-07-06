/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fork_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:27:58 by tayou             #+#    #+#             */
/*   Updated: 2023/07/06 12:43:26 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_fork_array(t_data *all);

int	make_fork_array(t_data *all)
{
	all->fork = (int *) malloc(sizeof(int) * all->argv.philo_number);
	if (all->fork == (void *) 0)
		return (FALSE);
	initialize_fork_array(all);
	return (TRUE);
}

void	initialize_fork_array(t_data *all)
{
	unsigned long long	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		all->fork[i] = 1;
		i++;
	}
}
