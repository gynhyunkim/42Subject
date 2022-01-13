/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:05:20 by gkim              #+#    #+#             */
/*   Updated: 2022/01/13 23:05:41 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_philo(t_info *info, int num)
{
	info->num = num;
	info->philos = malloc(sizeof(t_philo) * num);
	info->fork = malloc(sizeof(char) * num);
	if (!info->philos || !info->fork)
		return (1);
	memset(info->fork, 1, num);
	return (0);
}
