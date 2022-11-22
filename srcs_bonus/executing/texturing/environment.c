/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:48:43 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 17:43:48 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	texturing_sprites_two(t_game *zz)
{
	int	x;
	int	y;

	x = zz->ray.x;
	y = zz->ray.drawstart - 1;
	while (++y <= zz->ray.drawend)
	{
		zz->t.texy = (int)zz->t.texpos
			& (zz->texture[zz->t.texdir].height - 1);
		zz->t.texpos += zz->t.step;
		if (zz->texture[zz->t.texdir].addr[zz->t.texy
				* zz->texture[zz->t.texdir].line_length
				/ 4 + zz->t.texx] != 16777215)
		{
			if (y < zz->ry && x < zz->rx)
				zz->data.addr[y * zz->data.line_length / 4 + x]
					= zz->texture[zz->t.texdir].addr[zz->t.texy
					* zz->texture[zz->t.texdir].line_length
					/ 4 + zz->t.texx];
		}
	}
}

static void	texturing_sprites_one(t_game *zz)
{
	zz->t.step = 1.0 * zz->texture[zz->t.texdir].height / zz->ray.lineheight;
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
}

void	texturing_environment(t_game *zz)
{
	zz->t.texdir = zz->ray.hit;
	if (zz->ray.side == 0)
		zz->t.wallx = zz->ray.posy + zz->ray.perpwalldist
			* zz->ray.raydiry;
	else
		zz->t.wallx = zz->ray.posx + zz->ray.perpwalldist
			* zz->ray.raydirx;
	zz->t.wallx -= floor((zz->t.wallx));
	texturing_sprites_one(zz);
	texturing_sprites_two(zz);
}
