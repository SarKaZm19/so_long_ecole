/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:39:02 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/29 15:34:59 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_handler(t_data *datas)
{
	if (datas->player.nb_collect == 0)
	{
		ft_printf("GG ! I hope you had fun with this so_long !\n");
		ft_free_datas(&datas);
		exit(EXIT_SUCCESS);
	}
}

void	move_left(t_data *datas)
{
	int	x;
	int	y;

	y = datas->player.pos_y;
	x = datas->player.pos_x;
	if (datas->map[y][x - 1] != '1')
	{
		if (datas->map[y][x - 1] == 'C' || datas->map[y][x - 1] == '0')
		{
			if (datas->map[y][x - 1] == 'C')
				datas->player.nb_collect--;
			datas->map[y][x - 1] = 'P';
			datas->map[y][x] = '0';
			datas->player.pos_x--;
			if (datas->player.nb_moves < INT_MAX)
				datas->player.nb_moves++;
			ft_printf("Moves : %d\n", datas->player.nb_moves);
		}
		else if (datas->map[y][x - 1] == 'E')
			exit_handler(datas);
	}
}

void	move_right(t_data *datas)
{
	int	x;
	int	y;

	y = datas->player.pos_y;
	x = datas->player.pos_x;
	if (datas->map[y][x + 1] != '1')
	{
		if (datas->map[y][x + 1] == 'C' || datas->map[y][x + 1] == '0')
		{
			if (datas->map[y][x + 1] == 'C')
				datas->player.nb_collect--;
			datas->map[y][x + 1] = 'P';
			datas->map[y][x] = '0';
			datas->player.pos_x++;
			if (datas->player.nb_moves < INT_MAX)
				datas->player.nb_moves++;
			ft_printf("Moves : %d\n", datas->player.nb_moves);
		}
		else if (datas->map[y][x + 1] == 'E')
			exit_handler(datas);
	}
}

void	move_down(t_data *datas)
{
	int	x;
	int	y;

	y = datas->player.pos_y;
	x = datas->player.pos_x;
	if (datas->map[y + 1][x] != '1')
	{
		if (datas->map[y + 1][x] == 'C' || datas->map[y + 1][x] == '0')
		{
			if (datas->map[y + 1][x] == 'C')
				datas->player.nb_collect--;
			datas->map[y + 1][x] = 'P';
			datas->map[y][x] = '0';
			datas->player.pos_y++;
			if (datas->player.nb_moves < INT_MAX)
				datas->player.nb_moves++;
			ft_printf("Moves : %d\n", datas->player.nb_moves);
		}
		else if (datas->map[y + 1][x] == 'E')
			exit_handler(datas);
	}
}

void	move_up(t_data *datas)
{
	int	x;
	int	y;

	y = datas->player.pos_y;
	x = datas->player.pos_x;
	if (datas->map[y - 1][x] != '1')
	{
		if (datas->map[y - 1][x] == 'C' || datas->map[y - 1][x] == '0')
		{
			if (datas->map[y - 1][x] == 'C')
				datas->player.nb_collect--;
			datas->map[y - 1][x] = 'P';
			datas->map[y][x] = '0';
			datas->player.pos_y--;
			if (datas->player.nb_moves < INT_MAX)
				datas->player.nb_moves++;
			ft_printf("Moves : %d\n", datas->player.nb_moves);
		}
		else if (datas->map[y - 1][x] == 'E')
			exit_handler(datas);
	}
}
