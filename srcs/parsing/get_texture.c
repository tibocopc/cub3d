/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:56:59 by xx                #+#    #+#             */
/*   Updated: 2025/11/08 15:31:42 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_dup_texture(t_map *data)
{
	int	i;
	int	n;
	int	s;
	int	w;
	int	e;

	free((n = 0, s = 0, w = 0, e = 0, i = -1, NULL));
	while (data->map[++i])
	{
		if (ft_strlen(data->map[i]) > 2 && data->map[i][0] == 'N'
			&& data->map[i][1] == 'O')
			n++;
		if (ft_strlen(data->map[i]) > 2 && data->map[i][0] == 'S'
			&& data->map[i][1] == 'O')
			s++;
		if (ft_strlen(data->map[i]) > 2 && data->map[i][0] == 'E'
			&& data->map[i][1] == 'A')
			e++;
		if (ft_strlen(data->map[i]) > 2 && data->map[i][0] == 'W'
			&& data->map[i][1] == 'E')
			w++;
	}
	if (w != 1 || s != 1 || e != 1 || n != 1)
		return (1);
	return (0);
}

int	check_xpm(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (!str)
		return (1);
	if (ft_strlen(str) < 4)
		return (1);
	while (str[i])
	{
		if (str[i] == '.')
			flag = 1;
		if (str[i] == ' ' && flag == 0)
			return (1);
		i++;
	}
	i--;
	while (ft_iswhitespace(str[i]))
		i--;
	i -= 3;
	if (ft_strncmp(&str[i], ".xpm", 4))
		return (1);
	return (0);
}

int	check_texture(t_map *data)
{
	if (check_xpm(data->no_texture) || check_xpm(data->so_texture)
		|| check_xpm(data->we_texture) || check_xpm(data->ea_texture))
		return (1);
	return (0);
}

void	get_north(t_map *data)
{
	int	j;
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) > 2 && data->map[i][0] == 'N'
			&& data->map[i][1] == 'O')
		{
			j = 2;
			while (ft_iswhitespace(data->map[i][j]))
				j++;
			data->no_texture = malloc(sizeof(char) * ft_strlen(data->map[i]) - j
					+ 1);
			if (!data->no_texture)
				return ;
			data->no_texture = ft_strncpy(data->no_texture, &data->map[i][j],
					ft_strlen(data->map[i]) - j);
		}
		i++;
	}
}

void	get_south(t_map *data)
{
	int	j;
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) > 2 && data->map[i][0] == 'S'
			&& data->map[i][1] == 'O')
		{
			j = 2;
			while (ft_iswhitespace(data->map[i][j]))
				j++;
			data->so_texture = malloc(sizeof(char) * ft_strlen(data->map[i]) - j
					+ 1);
			if (!data->so_texture)
				return ;
			data->so_texture = ft_strncpy(data->so_texture, &data->map[i][j],
					ft_strlen(data->map[i]) - j);
		}
		i++;
	}
}

void	get_west(t_map *data)
{
	int	j;
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) > 2 && data->map[i][0] == 'W'
			&& data->map[i][1] == 'E')
		{
			j = 2;
			while (ft_iswhitespace(data->map[i][j]))
				j++;
			data->ea_texture = malloc(sizeof(char) * ft_strlen(data->map[i]) - j
					+ 1);
			if (!data->ea_texture)
				return ;
			data->ea_texture = ft_strncpy(data->ea_texture, &data->map[i][j],
					ft_strlen(data->map[i]) - j);
		}
		i++;
	}
}

void	get_east(t_map *data)
{
	int	j;
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) > 2 && data->map[i][0] == 'E'
			&& data->map[i][1] == 'A')
		{
			j = 2;
			while (ft_iswhitespace(data->map[i][j]))
				j++;
			data->we_texture = malloc(sizeof(char) * ft_strlen(data->map[i]) - j
					+ 1);
			if (!data->we_texture)
				return ;
			data->we_texture = ft_strncpy(data->we_texture, &data->map[i][j],
					ft_strlen(data->map[i]) - j);
		}
		i++;
	}
}
