/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:48:10 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:48:13 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	check_before_space(t_game *zz, char *one, char *two)
{
	size_t	i;

	i = 0;
	while (one[i] && ft_isset(one[i], SPACE_TAB))
	{
		if (two[i] == '0')
			oops_crash(zz, ERROR_MAP_OPEN);
		++i;
	}
}

static void	check_special_lines(t_game *zz, char *one, char *two)
{
	size_t	i;

	i = 0;
	while (one[i])
		++i;
	while ((ft_strlen(two) > i - 1) && two[i])
	{
		if (two[i] == '0')
			oops_crash(zz, ERROR_MAP_OPEN);
		++i;
	}
}

void	check_special_case(t_game *zz)
{
	size_t	i;

	i = 1;
	check_before_space(zz, zz->map[0], zz->map[1]);
	check_before_space(zz, zz->map[1], zz->map[2]);
	if (ft_strlen(zz->map[1]) > ft_strlen(zz->map[0]))
		check_special_lines(zz, zz->map[0], zz->map[1]);
	if (ft_strlen(zz->map[2]) > ft_strlen(zz->map[1]))
		check_special_lines(zz, zz->map[1], zz->map[2]);
	while (zz->xlines > 3 && zz->map[i + 1] != NULL)
	{
		if (ft_strlen(zz->map[i - 1]) > ft_strlen(zz->map[i]))
			check_special_lines(zz, zz->map[i], zz->map[i - 1]);
		if (ft_strlen(zz->map[i + 1]) > ft_strlen(zz->map[i]))
			check_special_lines(zz, zz->map[i], zz->map[i + 1]);
		check_before_space(zz, zz->map[i], zz->map[i + 1]);
		++i;
	}
}
