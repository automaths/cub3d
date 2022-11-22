/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:48:56 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:48:59 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	initial_state(t_game *zz)
{
	zz->ray.hit = 0;
	zz->ray.perpwalldist = 0;
	zz->ray.camerax = 2 * zz->ray.x / (double)zz->rx - 1;
	zz->ray.raydirx = zz->ray.dirx + zz->ray.planx * zz->ray.camerax;
	zz->ray.raydiry = zz->ray.diry + zz->ray.plany * zz->ray.camerax;
	zz->ray.mapx = (int)zz->ray.posx;
	zz->ray.mapy = (int)zz->ray.posy;
}

static void	deltadist(t_game *zz)
{
	if (zz->ray.raydiry == 0)
		zz->ray.deltadistx = 0;
	else if (zz->ray.raydirx == 0)
		zz->ray.deltadistx = 1;
	else
		zz->ray.deltadistx = sqrt(1 + (zz->ray.raydiry
					* zz->ray.raydiry) / (zz->ray.raydirx
					* zz->ray.raydirx));
	if (zz->ray.raydirx == 0)
		zz->ray.deltadisty = 0;
	else if (zz->ray.raydiry == 0)
		zz->ray.deltadisty = 1;
	else
		zz->ray.deltadisty = sqrt(1 + (zz->ray.raydirx
					* zz->ray.raydirx) / (zz->ray.raydiry
					* zz->ray.raydiry));
}

static void	sidedist(t_game *zz)
{
	if (zz->ray.raydirx < 0)
	{
		zz->ray.stepx = -1;
		zz->ray.sidedistx = (zz->ray.posx - zz->ray.mapx) * zz->ray.deltadistx;
	}
	else
	{
		zz->ray.stepx = 1;
		zz->ray.sidedistx
			= (zz->ray.mapx + 1.0 - zz->ray.posx) * zz->ray.deltadistx;
	}
	if (zz->ray.raydiry < 0)
	{
		zz->ray.stepy = -1;
		zz->ray.sidedisty = (zz->ray.posy - zz->ray.mapy) * zz->ray.deltadisty;
	}
	else
	{
		zz->ray.stepy = 1;
		zz->ray.sidedisty
			= (zz->ray.mapy + 1.0 - zz->ray.posy) * zz->ray.deltadisty;
	}
}

void	reset_ray(t_game *zz)
{
	initial_state(zz);
	deltadist(zz);
	sidedist(zz);
}
