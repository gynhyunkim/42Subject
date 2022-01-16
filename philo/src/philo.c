/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:31:19 by gkim              #+#    #+#             */
/*   Updated: 2022/01/16 16:38:29 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	sleeping(t_philo *philo)
{
	long long	sleep_start_time;

	print_state(philo->info, philo->p_id, "is sleeping");
	sleep_start_time = get_time();
	while (!philo->info->dead_flag)
	{
		if (get_time() - sleep_start_time >= philo->info->time_sleep)
			break ;
		usleep(10);
	}
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->eat);
	philo->eat_count++;
	philo->check_time = get_time();
	pthread_mutex_unlock(&philo->info->eat);
	while (!philo->info->dead_flag)
	{
		if (get_time() - philo->check_time >= philo->info->time_eat)
			break ;
		usleep(10);
	}
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	print_state(philo->info, philo->p_id, "has taken a fork");
	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	print_state(philo->info, philo->p_id, "has taken a fork");
	print_state(philo->info, philo->p_id, "is eating");
	eating(philo);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
}

void	*func_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->p_id % 2)
		usleep(10000);
	while (!philo->info->dead_flag)
	{
		philo_eat(philo);
		if (philo->info->eat_flag)
			break ;
		sleeping(philo);
		print_state(philo->info, philo->p_id, "is thinking");
	}
	return (0);
}

int	start_philo(t_info *info)
{
	int	i;

	info->start_time = get_time();
	i = 0;
	while (i < info->num_philo)
	{
		info->philo[i].check_time = get_time();
		if (pthread_create(&info->philo[i].t_id, NULL,
				func_philo, &info->philo[i]))
			return (-1);
		i++;
	}
	i = 0;
	check_dead(info);
	while (i < info->num_philo)
		pthread_join(info->philo[i++].t_id, NULL);
	return (0);
}
