/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:29:54 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 15:38:12 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	get_digit(long long number)
{
	int	i;

	i = 0;
	if (number < 0)
	{
		number *= (-1);
		i++;
	}
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

char	*fill_string(char *string, long long number, int digit)
{
	int	i;

	if (number < 0)
	{
		number *= (-1);
		string[0] = '-';
	}
	if (number == 0)
		string[0] = '0';
	i = digit;
	while (number != 0)
	{
		string[i - 1] = number % 10 + '0';
		number /= 10;
		i--;
	}
	string[digit] = '\0';
	return (string);
}

char	*ft_itoa(int n)
{
	char		*string;
	long long	number;
	int			digit;

	number = (long long) n;
	digit = get_digit(number);
	string = (char *) malloc(sizeof(char) * digit + 1);
	if (string == 0)
		return (0);
	string = fill_string(string, number, digit);
	return (string);
}
