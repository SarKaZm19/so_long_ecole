/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:39:40 by fvastena          #+#    #+#             */
/*   Updated: 2023/10/04 12:21:52 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	close_btn(t_data *datas)
{
	ft_free_datas(&datas);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	player_key_hook(int keycode, t_data *datas)
{
	if (keycode == 13 || keycode == 122)
		p_move_up(datas);
	if (keycode == 0 || keycode == 113)
		p_move_left(datas);
	if (keycode == 1 || keycode == 115)
		p_move_down(datas);
	if (keycode == 2 || keycode == 100)
		p_move_right(datas);
}

static void	antagonist_key_hook(int keycode, t_data *datas)
{
	if (keycode == 126)
		a_move_up(datas);
	if (keycode == 123)
		a_move_left(datas);
	if (keycode == 125)
		a_move_down(datas);
	if (keycode == 124)
		a_move_right(datas);
}

static int	key_hook(int keycode, t_data *datas)
{
	if (keycode == 53)
		exit_handler(datas, 1);
	player_key_hook(keycode, datas);
	if (datas->nb_player == 2)
		antagonist_key_hook(keycode, datas);
	if (datas->player.transformed == 0 && datas->player.nb_collect == 0)
		datas->player.transformed = 1;
	return (0);
}

void	so_long(t_data *datas)
{
	datas->vars.mlx = mlx_init();
	if (!datas->vars.mlx)
		ft_errors(datas, NULL, 6);
	datas->vars.win = mlx_new_window(datas->vars.mlx, datas->size_x * RES,
			datas->size_y * RES + RES, "So_Long");
	if (!datas->vars.win)
		ft_errors(datas, NULL, 7);
	get_sprites(datas);
	datas->start_time = gettime(datas);
	mlx_hook(datas->vars.win, 17, 0, close_btn, datas);
	mlx_hook(datas->vars.win, 02, 1L << 0, key_hook, datas);
	mlx_loop_hook(datas->vars.mlx, render, datas);
	mlx_loop(datas->vars.mlx);
}
