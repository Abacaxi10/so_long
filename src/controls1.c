/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:53:52 by rabatist          #+#    #+#             */
/*   Updated: 2024/12/19 13:29:22 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	keyboard_w(t_data *s)
{
	int	len;
	int	heigh;

	len = s->player_x;
	heigh = s->player_y;
	heigh--;
	if (s->map[heigh][len] == '1')
		return (0);
	if (!right_move(s, len, heigh))
		return (0);
	s->map[heigh + 1][len] = '0';
	ft_printf("Steps Taken :%i\n", s->mouvescount);
	return (1);
}

static int	keyboard_s(t_data *s)
{
	int	len;
	int	heigh;

	len = s->player_x;
	heigh = s->player_y;
	heigh++;
	if (s->map[heigh][len] == '1')
		return (0);
	if (!right_move(s, len, heigh))
		return (0);
	s->map[heigh - 1][len] = '0';
	ft_printf("Steps Taken :%i\n", s->mouvescount);
	return (1);
}

static int	keyboard_a(t_data *s)
{
	int	len;
	int	heigh;

	len = s->player_x;
	heigh = s->player_y;
	len--;
	if (s->map[heigh][len] == '1')
		return (0);
	if (!right_move(s, len, heigh))
		return (0);
	s->map[heigh][len + 1] = '0';
	ft_printf("Steps Taken :%i\n", s->mouvescount);
	return (1);
}

static int	keyboard_d(t_data *s)
{
	int	len;
	int	heigh;

	len = s->player_x;
	heigh = s->player_y;
	len++;
	if (s->map[heigh][len] == '1')
		return (0);
	if (!right_move(s, len, heigh))
		return (0);
	s->map[heigh][len - 1] = '0';
	ft_printf("Steps Taken :%i\n", s->mouvescount);
	return (1);
}

int	ft_controls(int keycode, t_data *s)
{
	int	works;

	works = 0;
	if (keycode == 65307)
		free_exit(s);
	if (keycode == 119)
		works = keyboard_w(s);
	if (keycode == 115)
		works = keyboard_s(s);
	if (keycode == 97)
		works = keyboard_a(s);
	if (keycode == 100)
		works = keyboard_d(s);
	if (works)
		place_graphics(s);
	return (1);
}
