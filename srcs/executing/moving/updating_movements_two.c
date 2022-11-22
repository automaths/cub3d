/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating_movements_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:49:07 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:49:10 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	rotate_left(t_game *zz)
{
	double	last_dir_x;
	double	last_plan_x;

	last_dir_x = zz->ray.dirx;
	last_plan_x = zz->ray.planx;
	zz->ray.dirx = zz->ray.dirx * cos(zz->ray.rotspeed / 2)
		- zz->ray.diry * sin(zz->ray.rotspeed / 2);
	zz->ray.diry = last_dir_x * sin(zz->ray.rotspeed / 2)
		+ zz->ray.diry * cos(zz->ray.rotspeed / 2);
	zz->ray.planx = zz->ray.planx * cos(zz->ray.rotspeed / 2)
		- zz->ray.plany * sin(zz->ray.rotspeed / 2);
	zz->ray.plany = last_plan_x * sin(zz->ray.rotspeed / 2)
		+ zz->ray.plany * cos(zz->ray.rotspeed / 2);
}

void	rotate_right(t_game *zz)
{
	double	last_dir_x;
	double	last_plan_x;

	last_dir_x = zz->ray.dirx;
	last_plan_x = zz->ray.planx;
	zz->ray.dirx = zz->ray.dirx * cos(-zz->ray.rotspeed / 2)
		- zz->ray.diry * sin(-zz->ray.rotspeed / 2);
	zz->ray.diry = last_dir_x * sin(-zz->ray.rotspeed / 2)
		+ zz->ray.diry * cos(-zz->ray.rotspeed / 2);
	zz->ray.planx = zz->ray.planx * cos(-zz->ray.rotspeed / 2)
		- zz->ray.plany * sin(-zz->ray.rotspeed / 2);
	zz->ray.plany = last_plan_x * sin(-zz->ray.rotspeed / 2)
		+ zz->ray.plany * cos(-zz->ray.rotspeed / 2);
}
