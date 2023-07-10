/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:52:35 by tayou             #+#    #+#             */
/*   Updated: 2023/07/10 14:52:02 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork_array(t_data *all);
void	print_philo_list(t_data *all);

void	print_data(t_data *all)
{
	printf("all->argv.philo_number: %d\n", all->argv.philo_number);
	printf("all->argv.lifespan: %d\n", all->argv.lifespan);
	printf("all->argv.eating_time: %d\n", all->argv.eating_time);
	printf("all->argv.sleeping_time: %d\n", all->argv.sleeping_time);
	if (all->flag.mendatory_eating_count_exist == TRUE)
		printf("all->argv.mendatory_eating_count: %d\n", all->argv.mendatory_eating_count);
	print_philo_list(all);
}

void	print_philo_list(t_data *all)
{
	t_philo	*philo_list;
	int		i;

	philo_list = all->philo;
	i = 0;
	while (i < all->argv.philo_number)
	{
		printf("======================philo info=================\n");
		printf("number: %d\n", philo_list->number);
		printf("eating_count: %d\n", philo_list->eating_count);
		printf("last_eating_time: %llu\n", philo_list->last_eating_time);
		printf("left_number: %d\n", philo_list->left->number);
		printf("right_number: %d\n", philo_list->right->number);
		philo_list = philo_list->right;
		i++;
	}
}

void	check_mutex_connection(t_data *all)
{
	t_philo	*philo;
	int		i;

	philo = all->philo;
	i = 0;
	while (i < all->argv.philo_number)
	{
		printf("philo->number: %d\n", philo->number);
		if (philo->left_fork_mutex == philo->left->right_fork_mutex)
			printf("left_fork_mutex is okay.\n");
		else
			printf("left_fork_mutex not okay.\n");
		if (philo->right_fork_mutex == philo->right->left_fork_mutex)
			printf("right_fork_mutex is okay.\n");
		else
			printf("right_fork_mutex not okay.\n");
		philo = philo->right;
		i++;
	}
}
