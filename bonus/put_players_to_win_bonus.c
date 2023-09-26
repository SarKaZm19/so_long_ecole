/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_players_to_win_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:49:05 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/25 14:50:27 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_player_facing_img(t_data *datas, int x, int y)
{
	if (datas->player.facing == 0)
	{
		mlx_put_image_to_window(datas->vars.mlx, datas->vars.win,
			datas->player.img[0].ptr, x * RES, y * RES);
	}
	else if (datas->player.facing == 1)
	{
		mlx_put_image_to_window(datas->vars.mlx, datas->vars.win,
			datas->player.img[1].ptr, x * RES, y * RES);
	}
	else
	{
		mlx_put_image_to_window(datas->vars.mlx, datas->vars.win,
			datas->player.img[2].ptr, x * RES, y * RES);
	}
}

void	put_player_ev_facing_img(t_data *datas, int x, int y)
{
	if (datas->player.facing == 0)
	{
		mlx_put_image_to_window(datas->vars.mlx, datas->vars.win,
			datas->player.img[3].ptr, x * RES, y * RES);
	}
	else if (datas->player.facing == 1)
	{
		mlx_put_image_to_window(datas->vars.mlx, datas->vars.win,
			datas->player.img[4].ptr, x * RES, y * RES);
	}
	else
	{
		mlx_put_image_to_window(datas->vars.mlx, datas->vars.win,
			datas->player.img[5].ptr, x * RES, y * RES);
	}
}

void	put_player_img(t_data *datas, int x, int y)
{
	if (!datas->player.transformed)
		put_player_facing_img(datas, x, y);
	else
		put_player_ev_facing_img(datas, x, y);
}

void	put_antagonist_img(t_data *datas, int x, int y)
{
	if (datas->antagonist.facing == 0)
	{
		mlx_put_image_to_window(datas->vars.mlx, datas->vars.win,
			datas->antagonist.img[0].ptr, x * RES, y * RES);
	}
	else if (datas->antagonist.facing == 1)
	{
		mlx_put_image_to_window(datas->vars.mlx, datas->vars.win,
			datas->antagonist.img[1].ptr, x * RES, y * RES);
	}
	else
	{
		mlx_put_image_to_window(datas->vars.mlx, datas->vars.win,
			datas->antagonist.img[2].ptr, x * RES, y * RES);
	}
}
