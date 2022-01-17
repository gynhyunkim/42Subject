/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:06:43 by gkim              #+#    #+#             */
/*   Updated: 2022/01/17 02:28:09 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_state(t_info *info, int p_id, char *str)
{
	pthread_mutex_lock(&info->print);
	if (!info->dead_flag)
		printf("%lld %d %s\n", get_time() - info->start_time, p_id, str);
	pthread_mutex_unlock(&info->print);
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num);
}
