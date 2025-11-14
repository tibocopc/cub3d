/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tniagolo <tniagolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:33:32 by xx                #+#    #+#             */
/*   Updated: 2025/11/14 16:19:21 by tniagolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			write(1, &str[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_map	*data;

	if (ac != 2 || check_extension(av[1]))
		return (printf("Error, wrong file name\n"), 1);
	data = malloc(sizeof(t_map));
	if (!data)
		return (printf("Error: malloc failed\n"), 1);
	ft_bzero(data, sizeof(t_map));
	data->map = get_map(av[1]);
	if (!data->map)
		return (printf("Error: could not read map\n"), 1);
	if (get_map_gen(data))
		return (printf("Error: invalid map\n"), 1);
	if (check_dup_texture(data))
		return (printf("error"), 1);
	if (get_colors(data))
		return (printf("Error: invalid color format\n"), 1);
	get_north(data);
	get_south(data);
	get_east(data);
	get_west(data);
	if (check_texture(data))
		return (printf("error"), 1);
	if (vertical_walls(data->maps))
		return (printf("zia"));
	if (check_map_content(data->maps))
		return (printf("content zbi"));
	for (int i = 0; i < 3; i++)
	{
		printf("F : %d\n", data->floor_color[i]);
		printf("C : %d\n", data->ceiling_color[i]);
	}
	printf("North : %s\n", data->no_texture);
	printf("South : %s\n", data->so_texture);
	printf("East  : %s\n", data->ea_texture);
	printf("West  : %s\n", data->we_texture);
	print_map(data->maps);
}
