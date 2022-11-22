/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:48:20 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:48:23 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	check_nonsense_line(t_game *zz, char *line)
{
	size_t	i;

	i = 0;
	i = skip_blanks(line, i);
	if (ft_strncmp(line + i, "NO", 2) && ft_strncmp(line + i, "SO", 2)
		&& ft_strncmp(line + i, "EA", 2) && ft_strncmp(line + i, "WE", 2)
		&& ft_strncmp(line + i, "F", 1) && ft_strncmp(line + i, "C", 1))
		oops_crash(zz, ERROR_DATA_INVALID);
}

static bool	gathered_settings(t_game *zz)
{
	if (zz->no && zz->so && zz->we && zz->ea && zz->so
		&& zz->ground_color != -1 && zz->sky_color != -1)
		return (true);
	return (false);
}

void	check_info(t_game *zz)
{
	size_t	i;
	size_t	tab_len;
	size_t	last_valid_line;

	tab_len = get_tab_size(zz->my_file);
	last_valid_line = tab_len - 3;
	i = 0;
	while (zz->my_file[i])
	{
		i = skip_blank_lines(zz->my_file, i);
		check_nonsense_line(zz, zz->my_file[i]);
		get_paths(zz, zz->my_file[i]);
		get_colours(zz, zz->my_file[i]);
		if (gathered_settings(zz) == false && i == last_valid_line)
			oops_crash(zz, ERROR_DATA_INVALID);
		else if (gathered_settings(zz) == true)
		{
			get_map(zz, i + 1);
			break ;
		}
		i++;
	}
}
