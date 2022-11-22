/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:47:47 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:47:50 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	init_xylines(t_game *zz)
{
	size_t	map_size;

	map_size = get_tab_size(zz->map);
	if (map_size < 3)
		oops_crash(zz, ERROR_MAP_SIZE);
	zz->xlines = get_max_len(zz->map);
	zz->ylines = map_size;
}

void	get_map(t_game *zz, size_t i)
{
	size_t	j;
	size_t	size;

	size = get_tab_size(zz->my_file);
	zz->map = (char **)ft_calloc(size - i + 1, sizeof(char *));
	if (zz->map == NULL)
		oops_crash(zz, ERROR_MALLOC);
	i = skip_blank_lines(zz->my_file, i);
	j = 0;
	while (zz->my_file[i])
	{
		if (zz->my_file[i + 1] && is_only_blanks(zz->my_file[i]) == true
			&& is_only_blanks(zz->my_file[i + 1]) == false)
			oops_crash(zz, ERROR_MAP_SHAPE);
		zz->map[j] = ft_strdup(zz->my_file[i]);
		if (zz->map[j] == NULL)
			oops_crash(zz, ERROR_MALLOC);
		j++;
		i++;
	}
	if (!zz->map)
		oops_crash(zz, ERROR_DATA_MISSING);
	zz->map[j] = NULL;
	init_xylines(zz);
}
