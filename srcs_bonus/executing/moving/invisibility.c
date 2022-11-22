/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invisibility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:49:18 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:49:20 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	invisible_move(t_game *zz, char c)
{
	if (zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy
				+ (zz->ray.diry * 0.5))] == c)
	{
		if (print_pov(zz, 3) == 2 || print_pov(zz, 3) == 3)
		{
			zz->ray.posx += zz->ray.dirx * zz->ray.movespeed;
			zz->ray.posy += zz->ray.diry * zz->ray.movespeed;
		}
	}
	if (zz->map[(int)(zz->ray.posx + (zz->ray.dirx
				* 0.5))][(int)zz->ray.posy] == c)
	{
		if (print_pov(zz, 3) == 2 || print_pov(zz, 3) == 3)
		{
			zz->ray.posx += zz->ray.dirx * zz->ray.movespeed;
			zz->ray.posy += zz->ray.diry * zz->ray.movespeed;
		}
	}
}
