/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:35:13 by gkim              #+#    #+#             */
/*   Updated: 2022/01/17 03:49:06 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	end_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
		pthread_mutex_destroy(&info->forks[i++]);
	pthread_mutex_destroy(&info->eat);
	pthread_mutex_destroy(&info->print);
	free(info->forks);
	free(info->philo);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 5 || argc > 6)
		return (print_error("Error\narguments error"));
	if (init_info(&info, argc, argv) == -1)
		return (0);
	start_philo(&info);
	end_philo(&info);
	return (0);
}
