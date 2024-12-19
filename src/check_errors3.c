/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:18:18 by rabatist          #+#    #+#             */
/*   Updated: 2024/12/17 17:31:12 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	copy_map(t_data *s)
{
	int	i;

	s->map_copy = malloc(sizeof(char *) * (s->heightmap + 1));
	if (!s->map_copy)
	{
		ft_printf("Error\nmalloc failed");
		free_exit (s);
	}
	i = 0;
	while (i < s->heightmap)
	{
		s->map_copy[i] = ft_strdup(s->map[i]);
		if (!s->map_copy[i])
		{
			ft_printf("Error\nft_strdup failed\n");
			free_exit (s);
		}
		i++;
	}
	s->map_copy[i] = NULL;
}
