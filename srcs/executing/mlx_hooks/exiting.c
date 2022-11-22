/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:49:35 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:49:37 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	free_parsing(t_game *zz)
{
	size_t	i;

	i = 0;
	if (zz->no)
		free(zz->no);
	if (zz->so)
		free(zz->so);
	if (zz->we)
		free(zz->we);
	if (zz->ea)
		free(zz->ea);
	if (zz->map)
		while (i < zz->ylines)
			free(zz->map[i++]);
	if (zz->map)
		free(zz->map);
}

static void	free_mlx_one(t_game *zz)
{
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

static void	free_mlx_two(t_game *zz)
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
}

int	exiting(char *str, t_game *zz)
{
	free_parsing(zz);
	free_mlx_one(zz);
	free_mlx_two(zz);
	write(1, str, ft_strlen(str));
	mlx_loop_end(zz->data.mlx_ptr);
	exit(0);
}

int	cross_exit(int keycode, t_game *zz)
{
	(void)keycode;
	exiting("you closed the game window, hope you enjoyed the game!", zz);
	return (1);
}
