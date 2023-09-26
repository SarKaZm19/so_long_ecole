/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:54:53 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/20 19:24:06 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				return ;
			}
		}
	}
}
