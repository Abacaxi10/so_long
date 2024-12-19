/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:53:17 by rabatist          #+#    #+#             */
/*   Updated: 2024/12/19 17:20:45 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_game(t_data *s)
{
	s->mlxptr = mlx_init();
	s->winptr = mlx_new_window(s->mlxptr, (s->lenmap * 192),
			(s->heightmap * 192), "Fortinite 2");
	place_images_in_game(s);
	place_graphics(s);
	mlx_key_hook(s->winptr, ft_controls, s);
	mlx_hook(s->winptr, 17, 0, (void *)exit, 0);
	mlx_loop(s->mlxptr);
}

void	place_images_in_game(t_data *s)
{
	int	i;
	int	j;

	s->floor = mlx_xpm_file_to_image(s->mlxptr,
			"images/Floor.xpm", &i, &j);
	s->wall = mlx_xpm_file_to_image(s->mlxptr,
			"images/Wall.xpm", &i, &j);
	s->player = mlx_xpm_file_to_image(s->mlxptr,
			"images/Player.xpm", &i, &j);
	s->exit = mlx_xpm_file_to_image(s->mlxptr,
			"images/Exit.xpm", &i, &j);
	s->collectible = mlx_xpm_file_to_image(s->mlxptr,
			"images/Collectible1.xpm", &i, &j);
}

static void	place_collectible(t_data *s, int height, int len)
{
	mlx_put_image_to_window(s->mlxptr, s->winptr, s->collectible, len * 192,
		height * 192);
}

static void	place_player(t_data *s, int height, int len)
{
	mlx_put_image_to_window(s->mlxptr, s->winptr, s->player, len * 192,
		height * 192);
	s->player_y = height;
	s->player_x = len;
}

void	place_graphics(t_data *s)
{
	int	height;
	int	len;

	height = -1;
	while (++height < s->heightmap)
	{
		len = -1;
		while (s->map[height][++len])
		{
			if (s->map[height][len] == '1')
				mlx_put_image_to_window(s->mlxptr, s->winptr, s->wall,
					len * 192, height * 192);
			if (s->map[height][len] == 'C')
				place_collectible(s, height, len);
			if (s->map[height][len] == 'P')
				place_player(s, height, len);
			if (s->map[height][len] == 'E')
				mlx_put_image_to_window(s->mlxptr, s->winptr, s->exit,
					len * 192, height * 192);
			if (s->map[height][len] == '0')
				mlx_put_image_to_window(s->mlxptr, s->winptr, s->floor,
					len * 192, height * 192);
		}
	}
}
