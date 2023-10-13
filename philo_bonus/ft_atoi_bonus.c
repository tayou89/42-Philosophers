/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:30:18 by tayou             #+#    #+#             */
/*   Updated: 2023/07/16 19:01:11 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	get_number(char *string, int i, t_data *all);

int	ft_atoi(char *unsigned_number_string, t_data *all)
{
	int		number;
	char	*string;
	int		i;

	string = unsigned_number_string;
	i = 0;
	pass_white_space(string, &i);
	pass_sign(string, &i);
	number = get_number(string, i, all);
	return (number);
}

int	get_number(char *string, int i, t_data *all)
{
	int	before_number;
	int	after_number;

	if (all->flag.overflow_occur == TRUE)
		return (0);
	before_number = 0;
	while (string[i] >= '0' && string[i] <= '9')
	{
		after_number = before_number * 10 + (string[i] - '0');
		if (after_number < before_number)
		{
			all->flag.overflow_occur = TRUE;
			return (0);
		}
		before_number = after_number;
		i++;
	}
	return (after_number);
}
