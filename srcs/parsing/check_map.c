/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:11:27 by xx                #+#    #+#             */
/*   Updated: 2025/11/08 17:00:39 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_extension(char *str)
{
	if (ft_strlen(str) <= 4)
		return (1);
	if (ft_strncmp(str + (ft_strlen(str) - 4), ".cub", 4) == 0)
		return (0);
	return (1);
}

void	destroy_map(char **map)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

int	check_map_content(char **map)
{
	int	i;
	int	count;
	int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	horizontal_walls(char **map)
{
	int	x;
	int	h;
	int	w;

	if (!map || !map[0])
		return (1);
	h = 0;
	while (map[h])
		h++;
	if (h == 0)
		return (1);
	w = ft_strlen(map[0]);
	x = 0;
	while (x < w)
	{
		if (map[0][x] != '1' || map[h - 1][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

int	vertical_walls(char **map)
{
	int	y;
	int	h;
	int	len;

	if (!map || !map[0])
		return (1);
	h = 0;
	while (map[h])
		h++;
	y = 0;
	while (y < h)
	{
		len = ft_strlen(map[y]);
		if (len == 0)
			return (1);
		if (map[y][0] != '1' || map[y][len - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}
