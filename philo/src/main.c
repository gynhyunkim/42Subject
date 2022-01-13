/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:35:13 by gkim              #+#    #+#             */
/*   Updated: 2022/01/13 23:08:19 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 5 || argc > 6)
		printf("Error\ninvalid arguments\n");
	printf("%s\n", argv[0]);
	if (check_args(argv) == -1)
		printf("Error\ninvalid arguments\n");
	if (init_philo(&info, argv))
		printf("Error\ninit error\n");
	return (0);
}
