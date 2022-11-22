# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 17:02:44 by nsartral          #+#    #+#              #
#    Updated: 2022/11/21 17:30:04 by nsartral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		cub3d
NAME_BONUS	=		cub3d_bonus
MLX			=		minilibx-linux/libmlx.a
LFT			= 		libft/libft.a
CC			=		gcc
CFLAGS		=		-Wall -Wextra -Werror -g3 -MMD -MP
LIBS		=		-L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
INC			=		inc/cub3d.h 								\
					inc/error_msgs.h 							\

SRCS		=		main.c 										\
					parsing/check_info.c 						\
					parsing/check_map.c 						\
					parsing/check_walls_bis.c					\
					parsing/check_walls.c 						\
					parsing/get_colours.c						\
					parsing/get_file.c 							\
					parsing/get_map.c							\
					parsing/get_paths.c 						\
					parsing/utils_free.c 						\
					parsing/utils_free_bis.c 					\
					parsing/utils_str.c 						\
					parsing/utils_tab.c 						\
					parsing/utils_whitespaces.c					\
					executing/initing/game.c 					\
					executing/initing/textures.c 				\
					executing/mlx_hooks/exiting.c				\
					executing/mlx_hooks/keying.c 				\
					executing/mlx_hooks/releasing.c 			\
					executing/moving/updating_movements_one.c 	\
					executing/moving/updating_movements_two.c 	\
					executing/raycasting/reset_ray.c 			\
					executing/raycasting/raycasting.c 			\
					executing/raycasting/utils.c 				\
					executing/texturing/walls.c 				\

SRCS_BONUS	=		main.c 										\
					parsing/check_info.c 						\
					parsing/check_map.c 						\
					parsing/check_walls_bis.c					\
					parsing/check_walls.c 						\
					parsing/get_colours.c						\
					parsing/get_file.c 							\
					parsing/get_map.c							\
					parsing/get_paths.c 						\
					parsing/utils_free.c 						\
					parsing/utils_free_bis.c 					\
					parsing/utils_str.c 						\
					parsing/utils_tab.c 						\
					parsing/utils_whitespaces.c					\
					executing/initing/game.c 					\
					executing/initing/textures.c 				\
					executing/mlx_hooks/exiting.c				\
					executing/mlx_hooks/keying.c 				\
					executing/mlx_hooks/releasing.c 			\
					executing/moving/invisibility.c 			\
					executing/moving/updating_movements_one.c 	\
					executing/moving/updating_movements_two.c 	\
					executing/raycasting/reset_ray.c 			\
					executing/raycasting/raycasting.c 			\
					executing/raycasting/utils.c 				\
					executing/texturing/minimap.c 				\
					executing/texturing/environment.c 			\
					executing/texturing/pov.c 					\
					executing/texturing/walls.c 				\

OBJS		:=		$(addprefix ./objs/,$(SRCS:%.c=%.o))
OBJS_BONUS	:=		$(addprefix ./objs_bonus/,$(SRCS_BONUS:%.c=%.o))
DEP			=		$(addprefix ./objs/,$(OBJS:%.o=%.d))

all:				$(MLX) $(LFT) $(NAME)

-include $(DEP)

./objs/%.o: 		./srcs/%.c
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) -o $@ -c $<

./objs_bonus/%.o: 	./srcs_bonus/%.c
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):			$(OBJS) $(INC)
					$(CC) $(CFLAGS) -I incl -o $(NAME) $(OBJS) $(LIBS)

$(MLX):
					make -C ./minilibx-linux
$(LFT):
					make -C ./libft

bonus:				$(MLX) $(LFT) $(OBJS_BONUS) $(INC)
					$(CC) $(CFLAGS) -I incl -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBS)

clean:
					rm -rf objs/
					rm -rf objs_bonus/
					make -C ./libft clean

fclean:				clean
					rm -rf $(NAME)
					rm -rf cub3d_bonus
					make -C ./libft fclean

re:					fclean all

.PHONY:				all clean fclean re
