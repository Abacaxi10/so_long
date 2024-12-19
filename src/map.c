/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:56:50 by rabatist          #+#    #+#             */
/*   Updated: 2024/12/17 17:32:36 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	len_of_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static int	add_line(t_data *s, char *line)
{
	int		i;

	if (!line)
		return (0);
	s->heightmap++;
	s->tmp = (char **)malloc(sizeof(char *) * (s->heightmap + 1));
	if (!s->tmp)
		return (0);
	i = 0;
	while (i < s->heightmap - 1)
	{
		s->tmp[i] = s->map[i];
		i++;
	}
	s->tmp[s->heightmap - 1] = line;
	s->tmp[s->heightmap] = NULL;
	if (s->map)
		free (s->map);
	s->map = s->tmp;
	return (1);
}

int	map_reading(t_data *s, char **av)
{
	char	*readmap;

	s->fd = open(av[1], O_RDONLY);
	if (s->fd == -1)
	{
		ft_printf("Error\nFiles does not exist or cannot be opened\n");
		free_exit (s);
	}
	while (1)
	{
		readmap = get_next_line(s->fd);
		if (!readmap)
			break ;
		if (!add_line(s, readmap))
		{
			free (readmap);
			break ;
		}
	}
	close (s->fd);
	s->lenmap = len_of_map(s->map[0]);
	return (1);
}

void	find_player(t_data *s)
{
	int	x;
	int	y;

	y = 0;
	while (y < s->heightmap)
	{
		x = 0;
		while (x < s->lenmap)
		{
			if (s->map[y][x] == 'P')
			{
				s->player_x = x;
				s->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
