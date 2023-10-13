/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:00:30 by tayou             #+#    #+#             */
/*   Updated: 2023/07/18 13:01:35 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*find_dead_philo(t_data *all);
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
		{
			lock_mutex_array(all->flag_mutex, all);
			all->flag.simulation_stop = TRUE;
			unlock_mutex_array(all->flag_mutex, all);
		}
	}
	return (data);
}

t_philo	*find_dead_philo(t_data *all)
{
	long long	elapsed_time_from_last_meal;
	t_philo		*philo;
	int			i;

	philo = all->philo;
	i = 0;
	while (i < all->argv.philo_number)
	{
		pthread_mutex_lock(philo->eating_data_mutex);
		elapsed_time_from_last_meal = get_elapsed_time(philo->last_eating_time);
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
	lock_mutex_array(all->flag_mutex, all);
	all->flag.simulation_stop = TRUE;
	unlock_mutex_array(all->flag_mutex, all);
	print_philo(DEAD, dead_philo);
}

int	check_mendatory_eating_count_achieved(t_data *all)
{
	t_philo	*philo;
	int		i;

	if (all->flag.mendatory_eating_count_exist == FALSE)
		return (FALSE);
	philo = all->philo;
	i = 0;
	while (i < all->argv.philo_number)
	{
		pthread_mutex_lock(philo->eating_data_mutex);
		if (philo->eating_count < all->argv.mendatory_eating_count)
		{
			pthread_mutex_unlock(philo->eating_data_mutex);
			return (FALSE);
		}
		pthread_mutex_unlock(philo->eating_data_mutex);
		philo = philo->right;
		i++;
	}
	return (TRUE);
}

void	lock_mutex_array(pthread_mutex_t *mutex, t_data *all)
{
	int	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		pthread_mutex_lock(&mutex[i]);
		i++;
	}
}
