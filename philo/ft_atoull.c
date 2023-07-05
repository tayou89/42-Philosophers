/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:26:56 by tayou             #+#    #+#             */
/*   Updated: 2023/07/05 15:10:20 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	get_number(char *string, int i, t_data *all);

unsigned long long	ft_atoull(char *unsigned_number_string, t_data *all)
{
	unsigned long long	number;
	char				*string;
	int					i;

	string = unsigned_number_string;
	i = 0;
	pass_white_space(string, &i);
	pass_sign(string, &i);
	number = get_number(string, i, all);
	return (number);
}

unsigned long long	get_number(char *string, int i, t_data *all)
{
	unsigned long long	before_number;
	unsigned long long	after_number;

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
