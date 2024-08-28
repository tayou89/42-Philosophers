/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:30:39 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 14:30:06 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	pass_white_space(char *string, int *i)
{
	while ((string[*i] >= 9 && string[*i] <= 13) || string[*i] == 32)
		(*i)++;
}

int	pass_sign(char *string, int *i)
{
	if (string[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	else if (string[*i] == '+')
	{
		(*i)++;
		return (1);
	}
	else
		return (1);
}

unsigned long long	get_current_time(void)
{
	unsigned long long	current_time;
	struct timeval		time;

	gettimeofday(&time, (void *) 0);
	current_time = \
		(unsigned long long)(time.tv_sec * 1000) + \
		(unsigned long long)(time.tv_usec / 1000);
	return (current_time);
}

long long	get_elapsed_time(unsigned long long start_time)
{
	unsigned long long	current_time;
	long long			elapsed_time;

	current_time = get_current_time();
	elapsed_time = (long long)(current_time - start_time);
	return (elapsed_time);
}
