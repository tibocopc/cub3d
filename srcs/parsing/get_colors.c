/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:19:11 by xx                #+#    #+#             */
/*   Updated: 2025/11/07 14:26:50 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parse_color_value(char *str, int *i)
{
	int		start;
	char	*num_str;
	int		value;
	int		len;

	while (ft_iswhitespace(str[*i]))
		(*i)++;
	start = *i;
	if (!ft_isdigit(str[*i]))
		return (-1);
	while (ft_isdigit(str[*i]))
		(*i)++;
	len = *i - start;
	if (len > 3 || len == 0)
		return (-1);
	if (str[*i] && !ft_iswhitespace(str[*i]) && str[*i] != ',')
		return (-1);
	num_str = ft_substr(str, start, len);
	if (!num_str)
		return (-1);
	value = ft_atoi(num_str);
	free(num_str);
	if (value < 0 || value > 255)
		return (-1);
	return (value);
}

static int	parse_rgb(char *line, int **color)
{
	int	i;
	int	k;

	i = 1;
	*color = malloc(sizeof(int) * 3);
	if (!*color)
		return (1);
	k = 0;
	while (k < 3)
	{
		(*color)[k] = parse_color_value(line, &i);
		if ((*color)[k] == -1)
			return (free(*color), *color = NULL, 1);
		while (ft_iswhitespace(line[i]))
			i++;
		if (k < 2 && line[i] != ',')
			return (free(*color), *color = NULL, 1);
		if (k < 2)
			i++;
		k++;
	}
	while (ft_iswhitespace(line[i]))
		i++;
	if (line[i] != '\0')
		return (free(*color), *color = NULL, 1);
	return (0);
}

int	get_colors(t_map *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) > 1 && data->map[i][0] == 'F')
		{
			if (parse_rgb(data->map[i], &data->floor_color))
				return (1);
		}
		else if (ft_strlen(data->map[i]) > 1 && data->map[i][0] == 'C')
		{
			if (parse_rgb(data->map[i], &data->ceiling_color))
				return (1);
		}
		i++;
	}
	return (0);
}
