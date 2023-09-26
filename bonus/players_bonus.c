/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:54:53 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/26 13:08:15 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_player_datas(t_data *datas)
{
	int	x;
	int	y;

	y = -1;
	while (++y < datas->size_y)
	{
		x = -1;
		while (++x < datas->size_x)
		{
			if (datas->map[y][x] == 'P')
			{
				datas->player.pos_x = x;
				datas->player.pos_y = y;
				datas->player.nb_moves = 0;
				datas->player.transformed = 0;
				datas->player.facing = 0;
				datas->nb_player = 1;
				return ;
			}
		}
	}
}

void	get_antag_datas(t_data *datas)
{
	int	x;
	int	y;

	y = -1;
	while (++y < datas->size_y)
	{
		x = -1;
		while (++x < datas->size_x)
		{
			if (datas->map[y][x] == 'A')
			{
				datas->antagonist.pos_x = x;
				datas->antagonist.pos_y = y;
				datas->antagonist.nb_moves = 0;
				datas->antagonist.transformed = 0;
				datas->antagonist.facing = 0;
				datas->nb_player = 2;
				return ;
			}
		}
	}
}
