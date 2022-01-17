/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:50:10 by gkim              #+#    #+#             */
/*   Updated: 2022/01/17 15:44:52 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_eat_count(t_info *info)
{
	int	i;

	i = 0;
	while (!info->dead_flag && info->must_eat != 0 && i < info->num_philo
		&& info->philo[i].eat_count >= info->must_eat)
		i++;
	if (i == info->num_philo)
		info->eat_flag = 1;
}

void	check_dead(t_info *info)
{
	int	i;
	long long	d_check_time;
	while (!info->eat_flag && !info->dead_flag)
	{
		i = 0;
		while (!info->dead_flag && i < info->num_philo)
		{
			pthread_mutex_lock(&info->eat);
			if (!info->philo[i].last_eat_time)
				info->philo[i].last_eat_time = info->start_time;
			d_check_time = get_time();
			if (d_check_time - info->philo[i].last_eat_time > info->time_die)
			{
				info->dead_flag = 1;
				printf("%lld %d died\n", d_check_time - info->start_time, i + 1);				
			}
			pthread_mutex_unlock(&info->eat);
			i++;
		}
		check_eat_count(info);
	}
}
