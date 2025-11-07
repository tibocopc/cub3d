/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:25:01 by xx                #+#    #+#             */
/*   Updated: 2025/11/07 15:21:10 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**ft_get_size(char **map, char **res)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		i++;
	res = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		res[i] = malloc(sizeof(char) * j + 1);
		i++;
	}
	return (res);
}
int	check_map_format(char **map)
{
	int	i;
	int	j;

	i = 6;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			while (ft_iswhitespace(map[i][j]))
				j++;
			while (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'N'
				|| map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S'
				|| map[i][j] == ' ')
				j++;
			if (map[i][j] != 0)
				return (1);
		}
		i++;
	}
	return (0);
}

int	get_map_gen(t_map *data)
{
	if (check_map_format(data->map))
		return (1);
	data->map = copy_map(data->map);
    
	return (0);
}
char	**copy_map(char **map)
{
	int i = 6;
	int j;
	int k = 0;
	char **res;
	res = ft_get_size(map, res);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_iswhitespace(map[i][j]))
				res[k][j] = '1';
			else
				res[k][j] = map[i][j];
			j++;
		}
		res[k][j] = 0;
		i++;
		k++;
	}
	res[k] = NULL;
	return (res);
}