/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:46:48 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 19:16:31 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (ft_putstr_fd(ERROR_NB_ARGS, 2), false);
	if (ft_strlen(argv[1]) < 5)
		return (ft_putstr_fd(ERROR_FILE_FORMAT, 2), false);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 5) != 0)
		return (ft_putstr_fd(ERROR_FILE_FORMAT, 2), false);
	return (true);
}

static void	parsing(char **argv, t_game *zz)
{	
	init(argv, zz);
	get_file(zz);
	check_info(zz);
	check_map(zz);
}

void	launch_game(t_game *zz)
{
	init_mlx(zz);
	mlx_hook(zz->data.mlx_win, 2, 1L << 0, keying, zz);
	mlx_hook(zz->data.mlx_win, 3, 1L << 1, releasing, zz);
	mlx_hook(zz->data.mlx_win, 17, 1L << 17, mlx_loop_end, zz->data.mlx_ptr);
	mlx_loop_hook(zz->data.mlx_ptr, raycasting, zz);
	mlx_loop(zz->data.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game	zz;

	if (check_args(argc, argv) == false)
		return (1);
	parsing(argv, &zz);
	launch_game(&zz);
	free_all_one(&zz);
	free_all_two(&zz);
	return (0);
}
