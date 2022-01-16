/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:05:20 by gkim              #+#    #+#             */
/*   Updated: 2022/01/16 16:25:03 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_philo(t_info *info)
{
	int	i;

	info->philo = malloc(sizeof(t_philo) * info->num_philo);
	if (!info->philo)
		return (1);
	i = 0;
	while (i < info->num_philo)
	{
		info->philo[i].p_id = i + 1;
		info->philo[i].left_fork = i + 1;
		info->philo[i].right_fork = (i + 2) % info->num_philo;
		info->philo[i].eat_count = 0;
		info->philo[i].info = info;
		info->philo[i].check_time = 0;
		i++;
	}
	return (0);
}

int	init_mutex(t_info *info)
{
	int	i;

	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->forks)
		return (1);
	if (pthread_mutex_init(&info->print, NULL))
		return (1);
	if (pthread_mutex_init(&info->eat, NULL))
		return (1);
	i = 0;
	while (i < info->num_philo)
		if (pthread_mutex_init(&info->forks[i++], NULL))
			return (1);
	return (0);
}

int	init_info(t_info *info, int argc, char **argv)
{
	info->num_philo = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	printf("%d %d %d %d\n", info->num_philo, info->time_die, info->time_eat, info->time_sleep);
	info->must_eat = 0;
	info->dead_flag = 0;
	info->eat_flag = 0;
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	if (check_args(info))
		return (print_error("Error\ninvalid args"));
	if (init_mutex(info))
		return (print_error("Error\ninit error"));
	if (init_philo(info))
		return (print_error("Error\ninit error"));
	return (0);
}
