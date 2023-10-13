/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exception_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:29:43 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 10:51:26 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_argv_has_exception(int argc, char **argv, t_data *all);
int	check_argv_is_positive_number(int argc, char **argv);
int	check_string_is_positive_number(char *string);
int	get_argv_data(int argc, char **argv, t_data *all);

void	check_exception(int argc, char **argv, t_data *all)
{
	if (argc != 5 && argc != 6)
	{
		printf("Wrong argument count.\n");
		exit(NORMAL_EXIT);
	}
	if (check_argv_has_exception(argc, argv, all) == TRUE)
	{
		printf("Wrong argument.\n");
		exit(NORMAL_EXIT);
	}
}

int	check_argv_has_exception(int argc, char **argv, t_data *all)
{
	if (check_argv_is_positive_number(argc, argv) == FALSE)
		return (TRUE);
	if (get_argv_data(argc, argv, all) == FALSE)
		return (TRUE);
	if (all->argv.philo_number == 0
		|| (all->flag.mendatory_eating_count_exist == TRUE
			&& all->argv.mendatory_eating_count == 0))
		return (TRUE);
	return (FALSE);
}

int	check_argv_is_positive_number(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_string_is_positive_number(argv[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_string_is_positive_number(char *string)
{
	int	i;

	i = 0;
	pass_white_space(string, &i);
	if (pass_sign(string, &i) == -1)
		return (FALSE);
	if (string[i] == '\0')
		return (FALSE);
	while (string[i] != '\0')
	{
		if (string[i] >= '0' && string[i] <= '9')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	get_argv_data(int argc, char **argv, t_data *all)
{
	all->flag.overflow_occur = FALSE;
	all->argv.philo_number = ft_atoi(argv[1], all);
	all->argv.lifespan = ft_atoi(argv[2], all);
	all->argv.eating_time = ft_atoi(argv[3], all);
	all->argv.sleeping_time = ft_atoi(argv[4], all);
	if (argc == 6)
	{
		all->flag.mendatory_eating_count_exist = TRUE;
		all->argv.mendatory_eating_count = ft_atoi(argv[5], all);
	}
	else
	{
		all->flag.mendatory_eating_count_exist = FALSE;
		all->argv.mendatory_eating_count = 0;
	}
	if (all->flag.overflow_occur == TRUE)
		return (FALSE);
	else
		return (TRUE);
}
