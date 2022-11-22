/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:49:40 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:49:42 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	get_texture(t_game *zz, char *path, int n)
{
	zz->texture[n].img = mlx_xpm_file_to_image(zz->data.mlx_ptr,
			path, &(zz->texture[n].width), &(zz->texture[n].height));
	if (zz->texture[n].img == NULL)
		oops_crash(zz, ERROR_INIT_IMG);
	zz->texture[n].addr = (int *)mlx_get_data_addr(zz->texture[n].img,
			&zz->texture[n].bits_per_pixel,
			&zz->texture[n].line_length, &zz->texture[n].endian);
	if (zz->texture[n].addr == NULL)
		oops_crash(zz, ERROR_INIT_IMG);
}

void	init_textures(t_game *zz)
{
	get_texture(zz, "./textures/mamashotgun.xpm", 0);
	get_texture(zz, "./textures/mamapunch.xpm", 1);
	get_texture(zz, "./textures/lock.xpm", 2);
	get_texture(zz, "./textures/gate.xpm", 3);
	get_texture(zz, "./textures/key.xpm", 4);
	get_texture(zz, "./textures/box.xpm", 5);
	get_texture(zz, zz->no, 6);
	get_texture(zz, zz->so, 7);
	get_texture(zz, zz->ea, 8);
	get_texture(zz, zz->we, 9);
}
