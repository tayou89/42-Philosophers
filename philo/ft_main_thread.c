/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:00:30 by tayou             #+#    #+#             */
/*   Updated: 2023/07/10 00:18:31 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *find_dead_philo(t_data *all);
void	take_dying_routine(t_philo *dead_philo, t_data *all);
int		check_mendatory_eating_count_achieved(t_data *all);

void	*ft_main_thread(void *data)
{
	t_data	*all;
	t_philo	*dead_philo;

	all = (t_data *) data;
	dead_philo = (void *) 0;
	while (all->flag.simulation_stop == FALSE)
	{
		dead_philo = find_dead_philo(all);
		if (dead_philo != (void *) 0)
			take_dying_routine(dead_philo, all);
		if (check_mendatory_eating_count_achieved(all) == TRUE)
			all->flag.simulation_stop = TRUE;
	}
	return (data);
}

t_philo *find_dead_philo(t_data *all)
{
	long long	elapsed_time_from_last_meal;
	long long	elapsed_time_from_start;
	t_philo		*philo;
	int			i;

	philo = all->philo;
	i = 0;
	while (i < all->argv.philo_number)
	{
		elapsed_time_from_start = get_elapsed_time(all->start_time);
		pthread_mutex_lock(philo->eating_data_mutex);
		elapsed_time_from_last_meal = \
			elapsed_time_from_start - *(philo->last_eating_time);
		pthread_mutex_unlock(philo->eating_data_mutex);
		if (elapsed_time_from_last_meal > (long long) all->argv.lifespan)
			return (philo);
		philo = philo->right;
		i++;
	}
	return ((void *) 0);
}

void	take_dying_routine(t_philo *dead_philo, t_data *all)
{
	long long	elapsed_time;

	all->flag.simulation_stop = TRUE;
	change_philo_state(DEAD, dead_philo);
	elapsed_time = get_elapsed_time(all->start_time);
	print_philo(elapsed_time, dead_philo);
}

int	check_mendatory_eating_count_achieved(t_data *all)
{
	int	i;

	if (all->flag.mendatory_eating_count_exist == FALSE)
		return (FALSE);
	i = 0;
	while (i < all->argv.philo_number)
	{
		if (all->eating_count[i] < all->argv.mendatory_eating_count)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
