/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:11:22 by xx                #+#    #+#             */
/*   Updated: 2025/11/07 14:26:57 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*join_lines(char *all, char *line)
{
	char	*tmp;

	if (!all)
		return (ft_strdup(line));
	tmp = ft_strjoin(all, line);
	free(all);
	return (tmp);
}

static char	*read_all_lines(int fd)
{
	char	*line;
	char	*all;

	all = NULL;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		all = join_lines(all, line);
		free(line);
	}
	if (!all)
		all = ft_strdup("");
	return (all);
}

char	**get_map(char *carte)
{
	char	**map;
	int		fd;
	char	*all_lines;

	fd = open(carte, O_RDONLY);
	if (fd < 0)
		return (NULL);
	all_lines = read_all_lines(fd);
	close(fd);
	map = ft_split(all_lines, '\n');
	free(all_lines);
	map = delete_space(map);
	return (map);
}

char	**dup_map(char **src)
{
	int		i;
	char	**copy;

	i = 0;
	while (src[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (src[i])
	{
		copy[i] = ft_strdup(src[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	copy_without_spaces(char *dst, char *src, int start)
{
	int	i;

	i = 0;
	while (src[start])
		dst[i++] = src[start++];
	dst[i] = '\0';
}

static int	count_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**delete_space(char **map)
{
	char	**tmp;
	int		i;
	int		j;

	if (!map)
		return (NULL);
	tmp = malloc(sizeof(char *) * (count_lines(map) + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == 13)
			j++;
		tmp[i] = malloc(sizeof(char) * (ft_strlen(map[i]) - j + 1));
		if (!tmp[i])
			return (NULL);
		copy_without_spaces(tmp[i], map[i], j);
	}
	tmp[i] = NULL;
	return (tmp);
}

int	valid_map(char **map)
{
	char	**dup;
	int		i;

	dup = delete_space(map);
	if (!dup)
		return (0);
	i = 0;
	while (dup[i])
		free(dup[i++]);
	free(dup);
	return (1);
}
