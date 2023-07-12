/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:27:27 by tayou             #+#    #+#             */
/*   Updated: 2023/07/12 13:51:24 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*make_new_philo(int i, t_data *all);
t_philo	*add_new_philo(t_philo *new_philo, t_data *all);
void	connect_fork_state_and_mutex(int i, t_philo *new_philo, t_data *all);

int	make_philo_list(t_data *all)
{
	t_philo	*new_philo;
	int		i;

	all->philo = (void *) 0;
	i = 1;
	while (i <= all->argv.philo_number)
	{
		new_philo = make_new_philo(i, all);
		if (new_philo == (void *) 0)
			return (FALSE);
		if (all->philo == (void *) 0)
			all->philo = new_philo;
		else
			all->philo = add_new_philo(new_philo, all);
		i++;
	}
	return (TRUE);
}

t_philo	*make_new_philo(int i, t_data *all)
{
	t_philo	*new_philo;

	new_philo = (t_philo *) malloc(sizeof(t_philo));
	if (new_philo == (void *) 0)
		return ((void *) 0);
	new_philo->number = i;
	new_philo->state = THINKING;
	new_philo->fork_count = 0;
	new_philo->eating_time = all->argv.eating_time;
	new_philo->sleeping_time = all->argv.sleeping_time;
	new_philo->simulation_stop = &all->flag.simulation_stop;
	new_philo->eating_count = 0;
	new_philo->last_eating_time = 0;
	new_philo->state_mutex = &all->state_mutex[i - 1];
	new_philo->eating_data_mutex = &all->eating_data_mutex[i - 1];
	new_philo->flag_mutex = &all->flag_mutex[i - 1];
	new_philo->print_mutex = &all->print_mutex;
	connect_fork_state_and_mutex(i, new_philo, all);
	new_philo->left = (void *) 0;
	new_philo->right = (void *) 0;
	return (new_philo);
}

void	connect_fork_state_and_mutex(int i, t_philo *new_philo, t_data *all)
{
	new_philo->left_fork_state = &all->fork[i - 1].state;
	if (all->argv.philo_number == 1)
		new_philo->right_fork_state = NOT_AVAILABLE;
	else if (new_philo->number == all->argv.philo_number)
		new_philo->right_fork_state = &all->fork[0].state;
	else
		new_philo->right_fork_state = &all->fork[i].state;
	new_philo->left_fork_mutex = &all->fork_mutex[i - 1];
	if (all->argv.philo_number == 1)
		new_philo->right_fork_mutex = (void *) 0;
	else if (new_philo->number == all->argv.philo_number)
		new_philo->right_fork_mutex = &all->fork_mutex[0];
	else
		new_philo->right_fork_mutex = &all->fork_mutex[i];
}

t_philo	*add_new_philo(t_philo *new_philo, t_data *all)
{
	t_philo	*philo_list;

	philo_list = all->philo;
	while (philo_list->right != (void *) 0)
		philo_list = philo_list->right;
	philo_list->right = new_philo;
	new_philo->left = philo_list;
	if (new_philo->number == all->argv.philo_number)
	{
		all->philo->left = new_philo;
		new_philo->right = all->philo;
	}
	return (all->philo);
}
