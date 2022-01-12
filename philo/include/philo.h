/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:35:27 by gkim              #+#    #+#             */
/*   Updated: 2022/01/12 17:37:27 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>

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

typedef struct s_main
{
	t_philo	*philos;
	int		*fork;
	t_time	time;	
}	t_main;

#endif