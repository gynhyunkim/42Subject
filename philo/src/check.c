/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:44:27 by gkim              #+#    #+#             */
/*   Updated: 2022/01/16 15:58:11 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_args(t_info *info)
{
	if (info->num_philo < 1 || info->time_die < 1
		|| info->time_eat < 1 || info->time_sleep < 1)
		return (1);
	return (0);
}
