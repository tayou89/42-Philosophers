/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:01:29 by tayou             #+#    #+#             */
/*   Updated: 2023/07/07 14:20:12 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

	if (gettimeofday(&time, (void *) 0) == -1)
	{
		printf("Error. gettimeofday failed.\n");
		return (FALSE);
	}
	current_time = \
		(unsigned long long) (time.tv_sec * 1000) + \
		(unsigned long long) (time.tv_usec / 1000);
	return (current_time);
}

void	print_philo(unsigned long long start_time, int number, int status)
{
	unsigned long long	current_time;
	unsigned long long	time;
	char				*status_string;

	current_time = get_current_time();
	if (current_time == FALSE)
		return ;
	time = current_time - start_time;
	if (status == THINKING)
		status_string = "is thinking";
	else if (status == EATING)
		status_string = "is eating";
	else if (status == SLEEPING)
		status_string = "is sleeping";
	else if (status == DEAD)
		status_string = "died";
	else if (status == TAKE_FORK)
		status_string = "has taken a fork";
	printf("%llu %d %s\n", time, number, status_string);
}
