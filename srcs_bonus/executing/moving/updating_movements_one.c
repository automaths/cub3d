/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating_movements_one.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:49:13 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:49:15 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	move_front(t_game *zz)
{
	if (zz->map[(int)(zz->ray.posx + (zz->ray.dirx
				* 0.3))][(int)zz->ray.posy] == '0' ||
				zz->map[(int)(zz->ray.posx + (zz->ray.dirx
				* 0.3))][(int)zz->ray.posy] == '6')
		zz->ray.posx += zz->ray.dirx * zz->ray.movespeed;
	if (zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy
				+ (zz->ray.diry * 0.3))] == '0' ||
				zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy
				+ (zz->ray.diry * 0.3))] == '6')
		zz->ray.posy += zz->ray.diry * zz->ray.movespeed;
	invisible_move(zz, '3');
	invisible_move(zz, '5');
}

static void	move_back(t_game *zz)
{
	if (zz->map[(int)(zz->ray.posx - (zz->ray.dirx
				* 0.3))][(int)(zz->ray.posy)] == '0' ||
				zz->map[(int)(zz->ray.posx - (zz->ray.dirx
				* 0.3))][(int)(zz->ray.posy)] == '6')
		zz->ray.posx -= zz->ray.dirx * zz->ray.movespeed;
	if (zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy
				- (zz->ray.diry * 0.3))] == '0' ||
				zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy
				- (zz->ray.diry * 0.3))] == '6')
		zz->ray.posy -= zz->ray.diry * zz->ray.movespeed;
}

static void	move_left(t_game *zz)
{
	if (zz->map[(int)(zz->ray.posx - zz->ray.diry
			* (0.3))][(int)zz->ray.posy] == '0' ||
			zz->map[(int)(zz->ray.posx - zz->ray.diry
			* (0.3))][(int)zz->ray.posy] == '6')
		zz->ray.posx -= zz->ray.diry * zz->ray.movespeed;
	if (zz->map[(int)zz->ray.posx][(int)(zz->ray.posy
		+ zz->ray.dirx * (0.3))] == '0' ||
			zz->map[(int)zz->ray.posx][(int)(zz->ray.posy
				+ zz->ray.dirx * (0.3))] == '6')
		zz->ray.posy += zz->ray.dirx * zz->ray.movespeed;
}

static void	move_right(t_game *zz)
{
	if (zz->map[(int)(zz->ray.posx + zz->ray.diry
			* (0.3))][(int)zz->ray.posy] == '0' ||
			zz->map[(int)(zz->ray.posx + zz->ray.diry
			* (0.3))][(int)zz->ray.posy] == '0')
		zz->ray.posx += zz->ray.diry * zz->ray.movespeed;
	if (zz->map[(int)zz->ray.posx][(int)(zz->ray.posy
		- zz->ray.dirx * (0.3))] == '0' ||
			zz->map[(int)zz->ray.posx][(int)(zz->ray.posy
				- zz->ray.dirx * (0.3))] == '6')
		zz->ray.posy -= zz->ray.dirx * zz->ray.movespeed;
}

void	updating_movements(t_game *zz)
{
	if (zz->data.forward == 1)
		move_front(zz);
	if (zz->data.back == 1)
		move_back(zz);
	if (zz->data.left == 1)
		move_left(zz);
	if (zz->data.right == 1)
		move_right(zz);
	if (zz->data.rotate_left == 1)
		rotate_left(zz);
	if (zz->data.rotate_right == 1)
		rotate_right(zz);
}
