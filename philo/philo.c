/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:45:13 by tayou             #+#    #+#             */
/*   Updated: 2023/07/31 14:32:50 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	all;

	all.exit_status = 0;
	if (check_exception_exist(argc, argv, &all) == TRUE)
		return (0);
	if (create_data(&all) == FALSE)
	{
		destroy_every_mutex(&all);
		free_mallocated_data(&all);
		return (1);
	}
	all.start_time = get_current_time();
	if (create_philo_thread(&all) == FALSE)
	{
		lock_mutex_array(all.flag_mutex, &all);
		all.flag.simulation_stop = TRUE;
		unlock_mutex_array(all.flag_mutex, &all);
		all.exit_status = 1;
	}
	join_every_thread(&all);
	destroy_every_mutex(&all);
	free_mallocated_data(&all);
	return (all.exit_status);
}
