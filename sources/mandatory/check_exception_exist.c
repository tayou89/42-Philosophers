/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exception_exist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:51:21 by tayou             #+#    #+#             */
/*   Updated: 2023/07/12 14:48:13 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argv_has_exception(int argc, char **argv, t_data *all);
int	check_argv_is_positive_number(int argc, char **argv);
int	check_string_is_positive_number(char *string);
int	get_argv_data(int argc, char **argv, t_data *all);

int	check_exception_exist(int argc, char **argv, t_data *all)
{
	if (argc != 5 && argc != 6)
	{
		printf("Wrong argument count.\n");
		return (TRUE);
	}
	if (check_argv_has_exception(argc, argv, all) == TRUE)
	{
		printf("Wrong argument.\n");
		return (TRUE);
	}
	return (FALSE);
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
	all->flag.simulation_stop = FALSE;
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
		all->flag.mendatory_eating_count_exist = FALSE;
	if (all->flag.overflow_occur == TRUE)
		return (FALSE);
	else
		return (TRUE);
}
