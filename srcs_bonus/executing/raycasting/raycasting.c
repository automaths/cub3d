/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:49:02 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:49:04 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	change_frame(t_game *zz)
{
	void	*tmp;

	tmp = zz->data.img;
	zz->data.img = zz->data.img2;
	zz->data.img2 = tmp;
	tmp = zz->data.addr;
	zz->data.addr = zz->data.addr2;
	zz->data.addr2 = tmp;
}

static void	sending_ray(t_game *zz, int type)
{
	reset_ray(zz);
	incrementing(zz, type);
	calculating(zz);
}

static void	raycast_walls(t_game *zz)
{
	while (zz->ray.x < zz->rx)
	{
		sending_ray(zz, 1);
		texturing_scene(zz);
		zz->ray.x++;
	}
}

static void	raycast_environment(t_game *zz)
{
	zz->ray.x = 0;
	while (zz->ray.x < zz->rx)
	{
		sending_ray(zz, 2);
		if (zz->ray.hit != 1)
			texturing_environment(zz);
		zz->ray.x++;
	}
}

int	raycasting(t_game *zz)
{
	zz->ray.x = 0;
	raycast_walls(zz);
	raycast_environment(zz);
	print_pov(zz, 0);
	print_minimap(zz);
	mlx_put_image_to_window(zz->data.mlx_ptr, zz->data.mlx_win,
		zz->data.img, 0, 0);
	updating_movements(zz);
	change_frame(zz);
	return (0);
}
