/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:25:01 by xx                #+#    #+#             */
/*   Updated: 2025/11/08 15:15:28 by xx               ###   ########.fr       */
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
	char	**res;

	if (check_map_format(data->map))
		return (1);
	res = copy_map(data->map);
	data->maps = set_map_rectangle(res, get_width(res));
	return (0);
}
char	**copy_map(char **map)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	res = NULL;
	i = 6;
	k = 0;
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
	return (res[k] = NULL, res);
}

int	get_width(char **map)
{
	int	i;
	int	j;
	int	max_width;

	i = 0;
	max_width = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (max_width < j)
			max_width = j;
		i++;
	}
	return (max_width);
}

char	**set_map_rectangle(char **map, int s)
{
	int		i;
	int		j;
	char	**res;

	res = malloc_rectangle(map, s + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			res[i][j] = map[i][j];
			j++;
		}
		while (j < s)
		{
			res[i][j] = '1';
			j++;
		}
		res[i][j] = '\0';
		i++;
	}
	return (res[i] = NULL, res);
}

char	**malloc_rectangle(char **map, int s)
{
	int		count;
	int		k;
	char	**res;

	count = 0;
	while (map[count])
		count++;
	res = malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	k = 0;
	while (k < count)
	{
		res[k] = malloc(sizeof(char) * s);
		if (!res[k])
		{
			while (k-- > 0)
				free(res[k]);
			free(res);
			return (NULL);
		}
		k++;
	}
	res[count] = NULL;
	return (res);
}
