/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:30:47 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 15:38:01 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	new_string = (char *) malloc(sizeof(char) * total_len + 1);
	if (new_string == 0)
		return (0);
	while (*s1 != '\0')
	{
		*new_string = *s1;
		s1++;
		new_string++;
	}
	while (*s2 != '\0')
	{
		*new_string = *s2;
		s2++;
		new_string++;
	}
	*new_string = '\0';
	return (new_string - s1_len - s2_len);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
