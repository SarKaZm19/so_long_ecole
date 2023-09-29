/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_key_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:39:02 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/29 16:06:46 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	p_move_left(t_data *datas)
{
	int	x;
	int	y;

	y = datas->player.pos_y;
	x = datas->player.pos_x;
	if (datas->map[y][x - 1] != '1')
	{
		if (!(datas->map[y][x - 1] == 'E'))
		{
			if (datas->map[y][x - 1] == 'C')
				datas->player.nb_collect--;
			if (datas->map[y][x - 1] == 'V' || datas->map[y][x - 1] == 'A')
				enemy_handler(datas, datas->map[y][x - 1]);
			datas->map[y][x - 1] = 'P';
			datas->map[y][x] = '0';
			datas->player.pos_x--;
			if (datas->player.nb_moves < INT_MAX)
				datas->player.nb_moves++;
		}
		else
			exit_handler(datas, 0);
	}
	datas->player.facing = 2;
}

void	p_move_right(t_data *datas)
{
	int	x;
	int	y;

	y = datas->player.pos_y;
	x = datas->player.pos_x;
	if (datas->map[y][x + 1] != '1')
	{
		if (!(datas->map[y][x + 1] == 'E'))
		{
			if (datas->map[y][x + 1] == 'C')
				datas->player.nb_collect--;
			if (datas->map[y][x + 1] == 'V' || datas->map[y][x + 1] == 'A')
				enemy_handler(datas, datas->map[y][x + 1]);
			datas->map[y][x + 1] = 'P';
			datas->map[y][x] = '0';
			datas->player.pos_x++;
			if (datas->player.nb_moves < INT_MAX)
				datas->player.nb_moves++;
		}
		else
			exit_handler(datas, 0);
	}
	datas->player.facing = 0;
}

void	p_move_down(t_data *datas)
{
	int	x;
	int	y;

	y = datas->player.pos_y;
	x = datas->player.pos_x;
	if (datas->map[y + 1][x] != '1')
	{
		if (!(datas->map[y + 1][x] == 'E'))
		{
			if (datas->map[y + 1][x] == 'C')
				datas->player.nb_collect--;
			if (datas->map[y + 1][x] == 'V' || datas->map[y + 1][x] == 'A')
				enemy_handler(datas, datas->map[y + 1][x]);
			datas->map[y + 1][x] = 'P';
			datas->map[y][x] = '0';
			datas->player.pos_y++;
			if (datas->player.nb_moves < INT_MAX)
				datas->player.nb_moves++;
		}
		else
			exit_handler(datas, 0);
	}
	datas->player.facing = 0;
}

void	p_move_up(t_data *datas)
{
	int	x;
	int	y;

	y = datas->player.pos_y;
	x = datas->player.pos_x;
	if (datas->map[y - 1][x] != '1')
	{
		if (!(datas->map[y - 1][x] == 'E'))
		{
			if (datas->map[y - 1][x] == 'C')
				datas->player.nb_collect--;
			if (datas->map[y - 1][x] == 'V' || datas->map[y - 1][x] == 'A')
				enemy_handler(datas, datas->map[y - 1][x]);
			datas->map[y - 1][x] = 'P';
			datas->map[y][x] = '0';
			datas->player.pos_y--;
			if (datas->player.nb_moves < INT_MAX)
				datas->player.nb_moves++;
		}
		else
			exit_handler(datas, 0);
	}
	datas->player.facing = 1;
}
