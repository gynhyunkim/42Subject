/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:50:10 by gkim              #+#    #+#             */
/*   Updated: 2022/01/17 03:18:32 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_eat_count(t_info *info)
{
	int	i;

	i = 0;
	while (info->must_eat != 0 && i < info->num_philo
		&& info->philo[i].eat_count >= info->must_eat)
		i++;
	if (i == info->num_philo)
		info->eat_flag = 1;
}

void	check_dead(t_info *info)
{
	int	i;

	while (!info->eat_flag)
	{
		i = 0;
		while (i < info->num_philo && !info->dead_flag)
		{
			pthread_mutex_lock(&info->eat);
			if (get_time() - info->philo[i].last_eat_time > info->time_die)
			{
				print_state(info, info->philo[i].p_id, "died");
				info->dead_flag = 1;
			}
			pthread_mutex_unlock(&info->eat);
			i++;
		}
		if (info->dead_flag)
			break ;
		check_eat_count(info);
	}
}
