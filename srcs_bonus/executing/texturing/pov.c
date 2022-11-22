/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:48:32 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 17:44:13 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

int	check_invisibility(t_game *zz)
{
	if (zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy)] == '3')
		return (1);
	if (zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy)] == '5')
		return (1);
	return (0);
}

void	check_destroy_box(t_game *zz)
{
	if (zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy
		+ (zz->ray.diry * 0.2))] == '5')
	{
		zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy
				+ (zz->ray.diry * 0.2))] = '0';
	}
	if (zz->map[(int)(zz->ray.posx + (zz->ray.dirx
				* 0.2))][(int)zz->ray.posy] == '5')
	{
		zz->map[(int)(zz->ray.posx + (zz->ray.dirx
					* 0.2))][(int)zz->ray.posy] = '0';
	}
}

int	change_pov(int pov, int change)
{
	if (pov == 2)
		pov = 3;
	else if (pov == 3)
		pov = 2;
	if (change == 1 && pov < 2)
			++pov;
	if (change == 2 && pov > 0)
	{
			--pov;
		if (pov == 3 || pov == 2)
			pov = 1;
	}
	return (pov);
}

void	display_item(t_game *zz, int pov)
{
	int	i;
	int	j;

	i = 650;
	if (pov == 2)
		pov = 1;
	while (++i < zz->texture[pov].height + 650)
	{
		j = 300;
		while (++j < zz->texture[pov].width + 300)
		{
			if (zz->texture[pov].addr[(i - 650)
					* zz->texture[pov].line_length
					/ 4 + j - 300] != -16777216)
			{
				zz->data.addr[i * zz->data.line_length / 4 + j]
					= zz->texture[pov].addr[(i - 650)
					* zz->texture[pov].line_length
					/ 4 + j - 300];
			}
		}
	}
}

int	print_pov(t_game *zz, int change)
{
	static int	pov;

	if (change == 3)
		return (pov);
	if (check_invisibility(zz))
		return (0);
	if (pov == 1)
		check_destroy_box(zz);
	pov = change_pov(pov, change);
	if (pov == 0 || pov == 1 || pov == 2)
		display_item(zz, pov);
	return (0);
}
