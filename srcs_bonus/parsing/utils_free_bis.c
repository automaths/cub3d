/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:47:33 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 17:43:06 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_all_one(t_game *zz)
{
	free_textures(zz);
	free_tab(zz->map);
	free_tab(zz->my_file);
	if (zz->data.img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->data.img);
	if (zz->data.img2)
		mlx_destroy_image(zz->data.mlx_ptr, zz->data.img2);
	if (zz->texture[0].img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[0].img);
	if (zz->texture[1].img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[1].img);
	if (zz->texture[2].img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[2].img);
	if (zz->texture[3].img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[3].img);
	if (zz->texture[4].img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[4].img);
}

void	free_all_two(t_game *zz)
{
	if (zz->texture[5].img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[5].img);
	if (zz->texture[6].img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[6].img);
	if (zz->texture[7].img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[7].img);
	if (zz->texture[8].img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[8].img);
	if (zz->texture[9].img)
		mlx_destroy_image(zz->data.mlx_ptr, zz->texture[9].img);
	if (zz->data.mlx_win)
		mlx_destroy_window(zz->data.mlx_ptr, zz->data.mlx_win);
	if (zz->data.mlx_ptr != NULL)
	{
		mlx_destroy_display(zz->data.mlx_ptr);
		free(zz->data.mlx_ptr);
	}
}
