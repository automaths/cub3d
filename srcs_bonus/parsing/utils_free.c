/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:47:27 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 17:43:11 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_textures(t_game *zz)
{
	if (zz->no)
		free(zz->no);
	if (zz->so)
		free(zz->so);
	if (zz->we)
		free(zz->we);
	if (zz->ea)
		free(zz->ea);
}

void	good_exit(t_game *zz, char *str)
{
	if (zz)
	{
		free_all_one(zz);
		free_all_two(zz);
	}
	if (str)
		write(1, str, ft_strlen(str));
	exit(0);
}

void	oops_crash(t_game *zz, char *msg)
{
	if (zz)
	{
		free_all_one(zz);
		free_all_two(zz);
	}
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	clean_error_exit(t_game *zz, char *line, int fd, char *error_msg)
{
	if (line)
		free(line);
	if (fd)
		close(fd);
	oops_crash(zz, error_msg);
}
