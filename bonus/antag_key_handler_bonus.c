/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antag_key_handler_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:41:14 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/25 19:06:43 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	a_move_left(t_data *datas)
{
	int	x;
	int	y;

	y = datas->antagonist.pos_y;
	x = datas->antagonist.pos_x;
	if (datas->map[y][x - 1] == '0' || datas->map[y][x - 1] == 'P')
	{
		if (datas->map[y][x - 1] == 'P')
		{
			ft_printf("Antagonist won\n");
			ft_free_datas(&datas);
			exit(EXIT_SUCCESS);
		}
		datas->map[y][x - 1] = 'A';
		datas->map[y][x] = '0';
		datas->antagonist.pos_x--;
	}
	datas->antagonist.facing = 2;
}

void	a_move_right(t_data *datas)
{
	int	x;
	int	y;

	y = datas->antagonist.pos_y;
	x = datas->antagonist.pos_x;
	if (datas->map[y][x + 1] == '0' || datas->map[y][x + 1] == 'P')
	{
		if (datas->map[y][x + 1] == 'P')
		{
			ft_printf("Antagonist won\n");
			ft_free_datas(&datas);
			exit(EXIT_SUCCESS);
		}
		datas->map[y][x + 1] = 'A';
		datas->map[y][x] = '0';
		datas->antagonist.pos_x++;
	}
	datas->antagonist.facing = 0;
}

void	a_move_down(t_data *datas)
{
	int	x;
	int	y;

	y = datas->antagonist.pos_y;
	x = datas->antagonist.pos_x;
	if (datas->map[y + 1][x] == '0' || datas->map[y + 1][x] == 'P')
	{
		if (datas->map[y + 1][x] == 'P')
		{
			ft_printf("Antagonist won\n");
			ft_free_datas(&datas);
			exit(EXIT_SUCCESS);
		}
		datas->map[y + 1][x] = 'A';
		datas->map[y][x] = '0';
		datas->antagonist.pos_y++;
	}
	datas->antagonist.facing = 0;
}

void	a_move_up(t_data *datas)
{
	int	x;
	int	y;

	y = datas->antagonist.pos_y;
	x = datas->antagonist.pos_x;
	if (datas->map[y - 1][x] == '0' || datas->map[y - 1][x] == 'P')
	{
		if (datas->map[y - 1][x] == 'P')
		{
			ft_printf("Antagonist won\n");
			ft_free_datas(&datas);
			exit(EXIT_SUCCESS);
		}
		datas->map[y - 1][x] = 'A';
		datas->map[y][x] = '0';
		datas->antagonist.pos_y--;
	}
	datas->antagonist.facing = 1;
}
