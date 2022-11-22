/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:48:27 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:48:29 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	init_texture(t_game *zz)
{
	if (zz->ray.side == 0 && zz->ray.raydirx < 0)
		zz->t.texdir = 6;
	if (zz->ray.side == 0 && zz->ray.raydirx >= 0)
		zz->t.texdir = 7;
	if (zz->ray.side == 1 && zz->ray.raydiry < 0)
		zz->t.texdir = 8;
	if (zz->ray.side == 1 && zz->ray.raydiry >= 0)
		zz->t.texdir = 9;
	if (zz->ray.side == 0)
		zz->t.wallx = zz->ray.posy + zz->ray.perpwalldist \
						* zz->ray.raydiry;
	else
		zz->t.wallx = zz->ray.posx + zz->ray.perpwalldist \
						* zz->ray.raydirx;
	zz->t.wallx -= floor(zz->t.wallx);
}

static void	texturing_walls(t_game *zz, int x, int y)
{
	y = zz->ray.drawstart - 1;
	init_texture(zz);
	zz->t.step = 1.0 * zz->texture[0].height / zz->ray.lineheight;
	zz->t.texx = (int)(zz->t.wallx * (double)zz->texture
		[zz->t.texdir].width);
	if (zz->ray.side == 0 && zz->ray.raydirx > 0)
		zz->t.texx = zz->texture[zz->t.texdir].width
			- zz->t.texx - 1;
	if (zz->ray.side == 1 && zz->ray.raydiry < 0)
		zz->t.texx = zz->texture[zz->t.texdir].width
			- zz->t.texx - 1;
	zz->t.texpos = (zz->ray.drawstart - zz->ry / 2
			+ zz->ray.lineheight / 2) * zz->t.step;
	while (++y <= zz->ray.drawend)
	{
		zz->t.texy = (int)zz->t.texpos
			& (zz->texture[zz->t.texdir].height - 1);
		zz->t.texpos += zz->t.step;
		if (y < zz->ry && x < zz->rx)
			zz->data.addr[y * zz->data.line_length / 4 + x]
				= zz->texture[zz->t.texdir].addr[zz->t.texy
				* zz->texture[zz->t.texdir].line_length
				/ 4 + zz->t.texx];
	}
}

void	texturing_scene(t_game *zz)
{
	int	j;
	int	i;

	j = -1;
	zz->ray.drawend = zz->ry - zz->ray.drawstart;
	i = zz->ray.drawend;
	while (++j < zz->ray.drawstart)
		zz->data.addr[j * zz->data.line_length / 4
			+ zz->ray.x] = zz->sky_color;
	if (j <= zz->ray.drawend)
		texturing_walls(zz, zz->ray.x, j);
	j = i;
	while (++j < zz->ry)
		zz->data.addr[j * zz->data.line_length / 4
			+ zz->ray.x] = zz->ground_color;
}
