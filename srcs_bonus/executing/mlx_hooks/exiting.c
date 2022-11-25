/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:49:35 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 18:42:37 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

int	exiting(char *str, t_game *zz)
{
	if (zz)
	{
		free_all_one(zz);
		free_all_two(zz);
	}
	ft_putstr_fd(str, 1);
	exit(1);
}

int	cross_exit(int keycode, t_game *zz)
{
	(void)keycode;
	if (zz)
	{
		free_all_one(zz);
		free_all_two(zz);
	}
	exit(1);
}
