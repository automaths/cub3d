/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keying.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:49:29 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 18:34:00 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	check_closed_door(t_game *zz, int y, int x)
{
	if (zz->map[y + 1][x] == '3')
		zz->map[y + 1][x] = '6';
	if (zz->map[y - 1][x] == '3')
		zz->map[y - 1][x] = '6';
	if (zz->map[y][x + 1] == '3')
		zz->map[y][x + 1] = '6';
	if (zz->map[y][x - 1] == '3')
		zz->map[y][x - 1] = '6';
}

void	check_open_door(t_game *zz, int y, int x)
{
	if (zz->map[y + 1][x] == '6')
		zz->map[y + 1][x] = '3';
	if (zz->map[y - 1][x] == '6')
		zz->map[y - 1][x] = '3';
	if (zz->map[y][x + 1] == '6')
		zz->map[y][x + 1] = '3';
	if (zz->map[y][x - 1] == '6')
		zz->map[y][x - 1] = '3';
}

void	button(t_game *zz)
{
	if (zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy
		+ (zz->ray.diry * 0.6))] == '2')
	{
		zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy
				+ (zz->ray.diry * 0.6))] = '4';
		check_closed_door(zz, (int)(zz->ray.posx), (int)(zz->ray.posy
				+ (zz->ray.diry * 0.6)));
	}
	else if (zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy
		+ (zz->ray.diry * 0.6))] == '4')
	{
		zz->map[(int)(zz->ray.posx)][(int)(zz->ray.posy
				+ (zz->ray.diry * 0.6))] = '2';
		check_open_door(zz, (int)(zz->ray.posx), (int)(zz->ray.posy
				+ (zz->ray.diry * 0.6)));
	}
}

int	keying(int keycode, t_game *zz)
{
	if (keycode == FORWARD_W_Z)
		zz->data.forward = 1;
	else if (keycode == BACK_S_S)
		zz->data.back = 1;
	else if (keycode == LEFT_A_Q)
		zz->data.left = 1;
	else if (keycode == RIGHT_D_D)
		zz->data.right = 1;
	else if (keycode == ROTATE_LEFT)
		zz->data.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		zz->data.rotate_right = 1;
	else if (keycode == 65307)
		exiting("Hope you have enjoyed the game!", zz);
	else if (keycode == 32)
		zz->ray.movespeed = 0.25;
	else if (keycode == 48)
		button(zz);
	else if (keycode == 49)
		print_pov(zz, 1);
	else if (keycode == 50)
		print_pov(zz, 2);
	return (1);
}
