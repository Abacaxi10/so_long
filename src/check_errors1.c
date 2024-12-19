/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:44:03 by rabatist          #+#    #+#             */
/*   Updated: 2024/12/18 17:26:00 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	horizontalwall(t_data *s)
{
	int	len;

	len = 0;
	while (len < s->lenmap)
	{
		if (s->map[0][len] != '1'
			|| s->map[s->heightmap - 1][len] != '1')
			return (0);
		len++;
	}
	return (1);
}

static int	verticalwall(t_data *s)
{
	int	height;

	height = 0;
	while (height < s->heightmap)
	{
		if (s->map[height][0] != '1'
		|| s->map[height][s->lenmap - 1] != '1')
			return (0);
		height++;
	}
	return (1);
}

void	if_walls(t_data *s)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(s);
	horizontalwalls = horizontalwall(s);
	if (!verticalwalls || !horizontalwalls)
	{
		ft_printf("Error\nWalls not closed\n");
		free_exit (s);
	}
}

static void	checker(t_data *s, int height, int len)
{
	char	i;

	i = s->map[height][len];
	if (i != '1' && i != '0' && i != 'P' && i != 'E' && i != 'C' && i != '\n')
	{
		ft_printf("Error\nWrong character used in *.ber\n");
		free_ptr(s);
		free_exit(s);
	}
	if (i == 'C')
		s->ccount++;
	if (i == 'P')
		s->pcount++;
	if (i == 'E')
		s->ecount++;
}

void	character_valid(t_data *s)
{
	int	height;
	int	len;

	len = 0;
	height = 0;
	while (height < s->heightmap - 1)
	{
		len = 0;
		while (len < s->lenmap)
		{
			checker(s, height, len);
			len++;
		}
		height++;
	}
	if (s->ccount < 1 || s->ecount != 1 || s->pcount != 1)
	{
		ft_printf("Error\nEither player, coin or exit issue\n");
		free_exit (s);
	}
}
