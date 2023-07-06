/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:52:35 by tayou             #+#    #+#             */
/*   Updated: 2023/07/06 12:45:45 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork_array(t_data *all);
void	print_philo_list(t_data *all);

void	print_data(t_data *all)
{
	printf("all->argv.philo_number: %llu\n", all->argv.philo_number);
	printf("all->argv.lifespan: %llu\n", all->argv.lifespan);
	printf("all->argv.eating_time: %llu\n", all->argv.eating_time);
	printf("all->argv.sleeping_time: %llu\n", all->argv.sleeping_time);
	if (all->flag.eating_max_exist == TRUE)
		printf("all->argv.eating_max: %llu\n", all->argv.eating_max);
	print_fork_array(all);
	print_philo_list(all);
}

void	print_fork_array(t_data *all)
{
	unsigned long long	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		printf("all->fork[%llu]: %d\n", i, all->fork[i]);
		i++;
	}
}

void	print_philo_list(t_data *all)
{
	t_philo				*philo_list;
	unsigned long long	i;

	philo_list = all->philo;
	i = 0;
	while (i < all->argv.philo_number)
	{
		printf("======================philo info=================\n");
		printf("number: %llu\n", philo_list->number);
		printf("lifespan: %llu\n", philo_list->lifespan);
		printf("eating_count: %llu\n", philo_list->eating_count);
		printf("last_eating_time: %llu\n", philo_list->last_eating_time);
		if (philo_list->status == THINKING)
			printf("status: THINKING\n");
		else if (philo_list->status == EATING)
			printf("status: EATING\n");
		else if (philo_list->status == SLEEPING)
			printf("status: SLEEPING\n");
		printf("left_number: %llu\n", philo_list->left->number);
		printf("right_number: %llu\n", philo_list->right->number);
		printf("left_fork: %d\n", *(philo_list->left_fork));
		printf("right_fork: %d\n", *(philo_list->right_fork));
		printf("fork_count: %d\n", philo_list->fork_count);
		philo_list = philo_list->right;
		i++;
	}
}
