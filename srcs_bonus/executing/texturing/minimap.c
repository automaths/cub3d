/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:48:37 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:48:39 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	print_player(t_game *zz, int side)
{
	int	i;
	int	j;
	int	color_player;

	i = -1;
	j = -1;
	color_player = convert_rgb(255, 255, 0, 0);
	while (++i < (side / 4))
	{
		j = -1;
		while (++j < (side / 4))
		{
			zz->data.addr[(j + ((int)(zz->ray.posx * side)))
				* zz->data.line_length / 4
				+ i + ((int)(zz->ray.posy * side))] = color_player;
		}
	}
}

static void	print_cubes_one(t_game *zz, int colors[5], int side)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = -1;
	while (++i < (int)zz->ylines)
	{
		j = -1;
		while (++j < (int)zz->xlines)
		{
			if (zz->map[i][j] == '6')
			{
				k = -1;
				while (++k < side)
				{
					l = -1;
					while (++l < side)
						zz->data.addr[(l + (side * i))
							* zz->data.line_length / 4
							+ k + (j * side)] = colors[0];
				}
			}
		}
	}
}

static void	print_cubes_two(t_game *zz, int colors[5], int side)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = -1;
	while (++i < (int)zz->ylines)
	{
		j = -1;
		while (++j < (int)zz->xlines)
		{
			if (zz->map[i][j] >= '0' && zz->map[i][j] <= '5')
			{	
				k = -1;
				while (++k < side)
				{
					l = -1;
					while (++l < side)
						zz->data.addr[(l + (side * i))
							* zz->data.line_length / 4
							+ k + (j * side)] = colors[zz->map[i][j] - 48];
				}
			}
		}
	}
}

void	print_minimap(t_game *zz)
{
	int	colors[5];
	int	x_size;
	int	y_size;
	int	side;

	x_size = (zz->rx / 4) / zz->xlines;
	y_size = (zz->ry / 4) / zz->ylines;
	colors[0] = convert_rgb(70, 70, 70, 70);
	colors[1] = convert_rgb(125, 125, 125, 125);
	colors[2] = convert_rgb(120, 0, 120, 0);
	colors[3] = convert_rgb(0, 70, 70, 70);
	colors[4] = convert_rgb(70, 200, 70, 70);
	colors[5] = convert_rgb(70, 70, 200, 70);
	if (x_size < y_size)
		side = x_size;
	else
		side = y_size;
	print_cubes_one(zz, colors, side);
	print_cubes_two(zz, colors, side);
	print_player(zz, side);
}
