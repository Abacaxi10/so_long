/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:00:35 by rabatist          #+#    #+#             */
/*   Updated: 2024/12/18 17:24:18 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "Libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_start
{
	int		fd;
	int		heightmap;
	int		lenmap;
	int		ccount;
	int		ecount;
	int		pcount;
	int		player_x;
	int		player_y;
	int		coin;
	int		mouvescount;

	char	**tmp;
	char	**map;
	char	**map_copy;

	void	*winptr;
	void	*mlxptr;
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
}			t_data;

void	start_game(t_data *s);
void	copy_map(t_data *s);
void	find_player(t_data *s);
void	check_errors(t_data *s);
void	character_valid(t_data *s);
void	if_walls(t_data *s);
void	check_errors(t_data *s);
int		map_reading(t_data *s, char **av);
void	free_exit(t_data *s);
void	check_valid_path(t_data *s);
int		ft_controls(int keycode, t_data *s);
void	place_images_in_game(t_data *s);
void	place_graphics(t_data *s);
int	right_move(t_data *s, int i, int j);
void	free_ptr(t_data *s);

#endif