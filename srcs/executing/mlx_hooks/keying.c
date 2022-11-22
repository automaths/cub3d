/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keying.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:49:29 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 16:29:33 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

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
		exiting("you have exited the game, hope you enjoyed it!\n", zz);
	return (1);
}
