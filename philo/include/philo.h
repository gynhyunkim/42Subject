/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:35:27 by gkim              #+#    #+#             */
/*   Updated: 2022/01/16 16:09:55 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_info
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	int				num_philo;
	int				time_eat;
	int				time_die;
	int				time_sleep;
	int				must_eat;
	int				dead_flag;
	int				eat_flag;
	long long		start_time;
	struct s_philo	*philo;
}	t_info;

typedef struct s_philo
{
	int			p_id;
	int			left_fork;
	int			right_fork;
	int			eat_count;
	long long	check_time;
	pthread_t	t_id;
	t_info		*info;
}	t_philo;

int			ft_atoi(const char *nptr);
int			check_args(t_info *info);
int			init_info(t_info *info, int argc, char **argv);
int			print_error(char *str);
long long	get_time(void);
int			start_philo(t_info *info);
void		print_state(t_info *info, int p_id, char *str);
void		philo_eat(t_philo *philo);
void		check_eat_count(t_info *info);
void		check_dead(t_info *info);

#endif