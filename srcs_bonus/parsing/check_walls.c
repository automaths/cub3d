/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:48:05 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:48:08 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static bool	get_down_char(t_game *zz, char *down_char, size_t i, size_t j)
{
	if (i == get_tab_size(zz->map) - 1)
		return (false);
	else
	{
		if (j < ft_strlen(zz->map[i + 1]))
			*down_char = zz->map[i + 1][j];
		else
			return (false);
	}
	return (true);
}

static bool	get_up_char(t_game *zz, char *up_char, size_t i, size_t j)
{
	if (j < ft_strlen(zz->map[i - 1]))
		*up_char = zz->map[i - 1][j];
	else
		return (false);
	return (true);
}

static void	check_inside(t_game *zz, size_t i, size_t j)
{
	const char	prev_char = zz->map[i][j - 1];
	const char	next_char = zz->map[i][j + 1];
	char		up_char;
	char		down_char;

	if (zz->map[i][j] == '0' && j != ft_strlen(zz->map[i]) - 1)
	{
		if (!prev_char || ft_isset(prev_char, SPACE_TAB))
			oops_crash(zz, ERROR_MAP_OPEN);
		if (!next_char || ft_isset(next_char, SPACE_TAB))
			oops_crash(zz, ERROR_MAP_OPEN);
		if (get_up_char(zz, &up_char, i, j) == true)
			if (!up_char || ft_isset(up_char, SPACE_TAB))
				oops_crash(zz, ERROR_MAP_OPEN);
		if (get_down_char(zz, &down_char, i, j) == true)
			if (!down_char || ft_isset(down_char, SPACE_TAB))
				oops_crash(zz, ERROR_MAP_OPEN);
	}
	check_special_case(zz);
}

static void	check_outside(t_game *zz, size_t i, size_t j)
{
	const size_t	top_line = 0;
	const size_t	top_char = 0;
	const size_t	last_line = get_tab_size(zz->map) - 1;
	const size_t	last_char = ft_strlen(zz->map[i]) - 1;

	if ((i == top_line || i == last_line) && !ft_isset(zz->map[i][j], " 	1"))
		oops_crash(zz, ERROR_MAP_EDGES);
	else if (j == top_char && zz->map[i][j] != '1')
	{
		j = skip_blanks(zz->map[i], j);
		if (zz->map[i][j] != '1')
			oops_crash(zz, ERROR_MAP_EDGES);
	}
	else if (j == last_char && zz->map[i][j] != '1')
	{
		j = skip_rev_blanks(zz->map[i], j);
		if (zz->map[i][j] != '1')
			oops_crash(zz, ERROR_MAP_EDGES);
	}
}

void	check_walls(t_game *zz)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (zz->map[++i])
	{
		j = 0;
		while (zz->map[i][j])
		{
			check_outside(zz, i, j);
			j++;
		}
	}
	i = 1;
	while (zz->map[i] && i < get_tab_size(zz->map) - 1)
	{
		j = 1;
		while (zz->map[i][j] && j < ft_strlen(zz->map[i]) - 1)
		{
			check_inside(zz, i, j);
			j++;
		}
		i++;
	}
}
