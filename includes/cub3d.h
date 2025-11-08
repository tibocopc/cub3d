/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:53:57 by xx                #+#    #+#             */
/*   Updated: 2025/11/08 14:54:35 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char	**map;
	char	*no_texture;
	char	*ea_texture;
	char	*we_texture;
	char	*so_texture;
	int		*floor_color;
	int		*ceiling_color;
	char	**maps;
}			t_map;

int			check_dup_texture(t_map *data);
int			check_texture(t_map *data);
char		**dup_map(char **src);
char		**get_map(char *carte);
int			check_extension(char *str);
int			check_last_element(char **map);
char		**delete_space(char **map);
void		get_north(t_map *data);
void		get_south(t_map *data);
void		get_east(t_map *data);
void		get_west(t_map *data);
int			get_colors(t_map *data);
void		destroy_map_cpy(char **map);
char		**copy_map(char **map);
char		**malloc_rectangle(char **map, int s);
char		**set_map_rectangle(char **map, int s);
int			get_width(char **map);
int			get_map_gen(t_map *data);
int			check_map_content(char **map);
int			vertical_walls(char **map);
// test//
void		print_map(char **str);
#endif
