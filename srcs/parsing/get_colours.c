/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colours.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:48:00 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:48:03 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	convert_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	stock_colours(t_game *zz, char *line)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 1;
	while (line[i])
	{
		i = skip_blanks(line, i);
		if (!ft_isdigit(line[i]))
			oops_crash(zz, ERROR_NON_DIGIT_COLOUR);
		while (ft_isdigit(line[i]))
		{
			zz->rgb[j] = zz->rgb[j] * 10 + line[i++] - 48;
			if (zz->rgb[j] > 255)
				oops_crash(zz, ERROR_COLOUR_SIZE);
		}
		i = skip_blanks(line, i);
		if (j < 2 && line[i] != ',')
			oops_crash(zz, ERROR_COLOUR_COMMA);
		else if (j < 2 && line[i] == ',')
			i++;
		i = skip_blanks(line, i);
		j++;
	}
}

void	get_colours(t_game *zz, char *line)
{
	size_t	i;

	zz->rgb[0] = 0;
	zz->rgb[1] = 0;
	zz->rgb[2] = 0;
	i = 0;
	i = skip_blanks(line, i);
	if (ft_strncmp(line + i, "F", 1) == 0)
	{
		if (zz->ground_color != -1)
			oops_crash(zz, ERROR_DATA_CLONE);
		stock_colours(zz, line + i);
		zz->ground_color = convert_rgb(0, zz->rgb[0], zz->rgb[1], zz->rgb[2]);
	}
	else if (ft_strncmp(line + i, "C", 1) == 0)
	{
		if (zz->sky_color != -1)
			oops_crash(zz, ERROR_DATA_CLONE);
		stock_colours(zz, line + i);
		zz->sky_color = convert_rgb(0, zz->rgb[0], zz->rgb[1], zz->rgb[2]);
	}
}
