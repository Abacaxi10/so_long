/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:04:17 by rabatist          #+#    #+#             */
/*   Updated: 2024/12/19 17:30:08 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_exit(t_data *s)
{
	int	i;

	i = 0;
	if (s->map)
	{
		while (i < s->heightmap)
			free(s->map[i++]);
		free (s->map);
		s->map = NULL;
	}
	if (s->map_copy)
	{
		i = 0;
		while (i < s->heightmap)
			free(s->map_copy[i++]);
		free (s->map_copy);
		s->map_copy = NULL;
	}
	exit (1);
}

void	free_ptr(t_data *s)
{
	if (s->floor)
		mlx_destroy_image(s->mlxptr, s->floor);
	if (s->wall)
		mlx_destroy_image(s->mlxptr, s->wall);
	if (s->player)
		mlx_destroy_image(s->mlxptr, s->player);
	if (s->exit)
		mlx_destroy_image(s->mlxptr, s->exit);
	if (s->collectible)
		mlx_destroy_image(s->mlxptr, s->collectible);
	if (s->winptr)
		mlx_destroy_window(s->mlxptr, s->winptr);
	if (s->mlxptr)
	{
		mlx_destroy_display(s->mlxptr);
		free(s->mlxptr);
	}
}

int	main(int ac, char **av)
{
	t_data	s;

	if (ac != 2)
	{
		ft_printf("Error\nUsage : ./so_long maps/Map.ber\n");
		exit (1);
	}
	if (ft_strlen(av[1]) < 4
		|| ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\nWrong map format, .ber needed\n");
		exit(1);
	}
	ft_bzero(&s, sizeof(t_data));
	if (!map_reading(&s, av))
		free_exit(&s);
	check_errors(&s);
	start_game(&s);
	ft_printf("bon code ma poule\n");
	free_exit(&s);
}
