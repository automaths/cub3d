/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:47:53 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:47:56 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init(char **argv, t_game *zz)
{
	ft_memset(zz, 0, sizeof(t_game));
	ft_memset(zz->texture, 0, sizeof(t_data));
	zz->map_name = argv[1];
	zz->no = 0;
	zz->so = 0;
	zz->ea = 0;
	zz->we = 0;
	zz->map = NULL;
	zz->my_file = NULL;
	zz->ground_color = -1;
	zz->sky_color = -1;
	zz->rx = 2565;
	zz->ry = 2048;
}

static bool	check_if_ascii(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isascii(line[i]))
			return (false);
		i++;
	}
	return (true);
}

void	get_file(t_game *zz)
{
	int		fd;
	int		ret;
	char	buffer[10000 + 1];

	buffer[0] = 0;
	fd = open(zz->map_name, __O_DIRECTORY);
	if (fd != -1)
		clean_error_exit(zz, NULL, 0, ERROR_FILE_DIR);
	fd = open(zz->map_name, O_RDONLY);
	if (fd == -1)
		clean_error_exit(zz, NULL, 0, ERROR_FILE_OPEN);
	ret = read(fd, buffer, 10000);
	if (ret == 0)
		clean_error_exit(zz, NULL, fd, ERROR_FILE_EMPTY);
	buffer[ret] = '\0';
	if (check_if_ascii(buffer) == false)
		clean_error_exit(zz, NULL, fd, ERROR_FILE_ASCII);
	zz->my_file = ft_split_with_sep(buffer, '\n');
	if (zz->my_file == NULL)
		clean_error_exit(zz, NULL, fd, ERROR_MALLOC);
	close(fd);
}
