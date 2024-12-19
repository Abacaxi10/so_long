/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:00:54 by rabatist          #+#    #+#             */
/*   Updated: 2024/12/19 17:08:29 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	right_move(t_data *s, int len, int heigh)
{
	if (s->map[heigh][len] == 'E')
	{
		if (s->ccount != 0)
			return (0);
		s->mouvescount++;
		ft_printf("Bien joué, moussaillon ! T'as l'œil d'un requin et la main d'un capitaine !\n");
		free_ptr(s);
		free_exit(s);
	}
	if (s->map[heigh][len] == '0')
	{
		s->map[heigh][len] = 'P';
		s->player_x = len;
		s->player_y = heigh;
		s->mouvescount++;
	}
	if (s->map[heigh][len] == 'C')
	{
		s->map[heigh][len] = 'P';
		s->player_x = len;
		s->player_y = heigh;
		s->ccount--;
		s->mouvescount++;
	}
	return (1);
}
