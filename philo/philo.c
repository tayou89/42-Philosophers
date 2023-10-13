/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:45:13 by tayou             #+#    #+#             */
/*   Updated: 2023/07/21 12:51:35 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	all;

	if (check_exception_exist(argc, argv, &all) == TRUE)
		return (0);
	if (create_data(&all) == FALSE)
		return (1);
	all.start_time = get_current_time();
	if (all.start_time == FALSE)
		return (1);
	if (create_philo_thread(&all) == FALSE)
		return (1);
	if (join_every_thread(&all) == FALSE)
		return (1);
	destroy_every_mutex(&all);
	free_mallocated_data(&all);
	return (0);
}
