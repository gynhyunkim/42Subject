/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:35:27 by gkim              #+#    #+#             */
/*   Updated: 2022/01/13 23:05:49 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_philo
{
	int	eat_count;
	int	fork[2];
}	t_philo;

typedef struct s_time
{
	int	eat;
	int	die;
	int	sleep;
}	t_time;

typedef struct s_info
{
	t_philo	*philos;
	int		*fork;
	t_time	time;
	int		num;
}	t_info;

int	ft_atoi(const char *nptr);
int	check_args(char **argv);
int	init_philo(t_info *info, int num);

#endif