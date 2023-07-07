/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:10:09 by tayou             #+#    #+#             */
/*   Updated: 2023/07/07 14:27:30 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	detach_every_philo_thread(t_data *all)
{
	unsigned long long	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		if (pthread_detach(all->philo_thread[i]) != 0)
			return (FALSE);
		i++;
	}
	all->flag.detach_philo_thread = TRUE;
	return (TRUE);
}

int	join_every_thread(t_data *all)
{
	if (all->flag.detach_philo_thread == FALSE)
	{
		if (join_every_philo_thread(all) == FALSE)
			return (FALSE);
	}
	if (pthread_join(all->main_thread, (void *) 0) != 0)
		return (FALSE);
	return (TRUE);
}

int	join_every_philo_thread(t_data *all)
{
	unsigned long long	i;

	i = 0;
	while (i < all->argv.philo_number)
	{
		if (pthread_join(all->philo_thread[i], (void *) 0) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
