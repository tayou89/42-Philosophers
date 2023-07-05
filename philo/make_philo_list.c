/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:27:27 by tayou             #+#    #+#             */
/*   Updated: 2023/07/05 22:12:27 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*make_new_philo(int i, t_data *all);
t_philo	*add_new_philo(t_philo *new_philo, t_data *all);

int	make_philo_list(t_data *all)
{
	t_philo				*new_philo;
	unsigned long long	i;

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
	new_philo->lifespan = all->argv.lifespan;
	new_philo->eating_count = 0;
	new_philo->last_eating_time = 0;
	new_philo->status = THINKING;
	new_philo->left = (void *) 0;
	new_philo->right = (void *) 0;
	return (new_philo);
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
