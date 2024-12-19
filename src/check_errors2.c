/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:47:07 by rabatist          #+#    #+#             */
/*   Updated: 2024/12/19 15:25:32 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_errors(t_data *s)
{
	if_walls(s);
	character_valid(s);
	find_player(s);
	copy_map(s);
	check_valid_path(s);
}

static void	flood_fill(t_data *s, int x, int y)
{
	if (x < 0 || y < 0 || x >= s->lenmap || y >= s->heightmap
		|| s->map_copy[y][x] == '\0' || s->map_copy[y][x] == '1'
		|| s->map_copy[y][x] == 'V')
		return ;
	if (s->map_copy[y][x] == 'E')
	{
		s->map_copy[y][x] = '1';
		return ;
	}
	else
		s->map_copy[y][x] = 'V';
	flood_fill(s, x + 1, y);
	flood_fill(s, x - 1, y);
	flood_fill(s, x, y + 1);
	flood_fill(s, x, y - 1);
}

void	check_valid_path(t_data *s)
{
	int	y;
	int	x;

	y = s->player_y;
	x = s->player_x;
	flood_fill(s, x, y);
	y = 0;
	while (y < s->heightmap)
	{
		x = 0;
		while (x < s->lenmap)
		{
			if ((s->map[y][x] == 'C' && s->map_copy[y][x] != 'V')
				|| (s->map[y][x] == 'E' && s->map_copy[y][x] != '1'))
			{
				ft_printf("Error\nUnreachable Collectible or Exit\n");
				free_exit(s);
			}
			x++;
		}
		y++;
	}
}
