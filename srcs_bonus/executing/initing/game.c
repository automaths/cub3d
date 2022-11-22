/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:49:46 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:49:53 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	init_frames(t_game *zz)
{
	zz->data.img = mlx_new_image(zz->data.mlx_ptr, zz->rx, zz->ry);
	if (zz->data.img == NULL)
		oops_crash(zz, ERROR_INIT_IMG);
	zz->data.addr = (int *)mlx_get_data_addr(zz->data.img,
			&zz->data.bits_per_pixel,
			&zz->data.line_length, &zz->data.endian);
	if (zz->data.addr == NULL)
		oops_crash(zz, ERROR_INIT_IMG_ADD);
	zz->data.img2 = mlx_new_image(zz->data.mlx_ptr, zz->rx, zz->ry);
	if (zz->data.img2 == NULL)
		oops_crash(zz, ERROR_INIT_IMG);
	zz->data.addr2 = (int *)mlx_get_data_addr(zz->data.img2,
			&zz->data.bits_per_pixel,
			&zz->data.line_length, &zz->data.endian);
	if (zz->data.addr2 == NULL)
		oops_crash(zz, ERROR_INIT_IMG_ADD);
}

static void	init_moves(t_game *zz)
{
	zz->data.forward = 0;
	zz->data.back = 0;
	zz->data.left = 0;
	zz->data.right = 0;
	zz->data.rotate_right = 0;
	zz->data.rotate_left = 0;
	zz->ray.posx = (double)zz->dx + 0.5;
	zz->ray.posy = (double)zz->dy + 0.5;
	zz->ray.dirx = 0;
	zz->ray.diry = 0;
	zz->ray.planx = 0;
	zz->ray.plany = 0;
	zz->ray.movespeed = 0.15;
	zz->ray.rotspeed = 0.15;
}

static void	init_pov(t_game *zz)
{
	if (zz->depart == 'N')
		zz->ray.dirx = -1;
	if (zz->depart == 'S')
		zz->ray.dirx = 1;
	if (zz->depart == 'E')
		zz->ray.diry = 1;
	if (zz->depart == 'W')
		zz->ray.diry = -1;
	if (zz->depart == 'N')
		zz->ray.plany = 0.66;
	if (zz->depart == 'S')
		zz->ray.plany = -0.66;
	if (zz->depart == 'E')
		zz->ray.planx = 0.66;
	if (zz->depart == 'W')
		zz->ray.planx = -0.66;
}

void	init_mlx(t_game *zz)
{
	init_moves(zz);
	init_pov(zz);
	zz->data.mlx_ptr = mlx_init();
	if (zz->data.mlx_ptr == NULL)
		oops_crash(zz, ERROR_MLX);
	zz->data.mlx_win = mlx_new_window(zz->data.mlx_ptr, zz->rx,
			zz->ry, "Cub3d_upgraded");
	if (zz->data.mlx_win == NULL)
		oops_crash(zz, ERROR_MLX_WIN);
	init_textures(zz);
	init_frames(zz);
	mlx_get_screen_size(zz->data.mlx_ptr, &zz->rx, &zz->ry);
}
