/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:47:41 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:47:43 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static char	*find_path(t_game *zz, char *line, char *zz_path, char *dir)
{
	char	*path;
	char	**tmp_path;

	if (zz_path)
		oops_crash(zz, ERROR_DATA_CLONE);
	tmp_path = ft_split_set(line, SPACE_TAB);
	if (!tmp_path)
		oops_crash(zz, ERROR_MALLOC);
	if (get_tab_size(tmp_path) != 2 || ft_strcmp(dir, tmp_path[0]))
	{
		free_tab(tmp_path);
		oops_crash(zz, ERROR_BAD_ID);
	}
	path = ft_strdup(tmp_path[1]);
	if (path == NULL)
	{
		free_tab(tmp_path);
		oops_crash(zz, ERROR_MALLOC);
	}
	free_tab(tmp_path);
	return (path);
}

static void	stock_path(t_game *zz, char *line, char **zz_path, char *dir)
{
	char	*path;

	path = find_path(zz, line, *zz_path, dir);
	*zz_path = ft_strdup(path);
	free(path);
	if (*zz_path == NULL)
		oops_crash(zz, ERROR_MALLOC);
}

void	get_paths(t_game *zz, char *line)
{
	size_t	i;

	i = 0;
	i = skip_blanks(line, i);
	if (ft_strncmp(line + i, "NO", 2) == 0)
		stock_path(zz, line + i, &zz->no, "NO");
	else if (ft_strncmp(line + i, "SO", 2) == 0)
		stock_path(zz, line + i, &zz->so, "SO");
	else if (ft_strncmp(line + i, "EA", 2) == 0)
		stock_path(zz, line + i, &zz->ea, "EA");
	else if (ft_strncmp(line + i, "WE", 2) == 0)
		stock_path(zz, line + i, &zz->we, "WE");
}
