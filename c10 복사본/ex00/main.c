/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:17:24 by gkim              #+#    #+#             */
/*   Updated: 2020/12/03 19:02:12 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"

int		main(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr(NO_ARGC);
	else if (argc > 2)
		ft_putstr(MANY_ARGC);
	else
		ft_display_file(argv[1]);
	return (0);
}
