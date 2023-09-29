/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:39:40 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/29 15:35:42 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_btn(t_data *datas)
{
	ft_free_datas(&datas);
	exit(EXIT_SUCCESS);
	return (0);
}

void	escape_key(t_data *datas)
{
	ft_free_datas(&datas);
	exit(EXIT_SUCCESS);
}

static int	key_hook(int keycode, t_data *datas)
{
	if (keycode == 13 || keycode == 122)
		move_up(datas);
	else if (keycode == 0 || keycode == 113)
		move_left(datas);
	else if (keycode == 1 || keycode == 115)
		move_down(datas);
	else if (keycode == 2 || keycode == 100)
		move_right(datas);
	else if (keycode == 53 || keycode == 65307)
		escape_key(datas);
	show_map(datas);
	return (0);
}

static void	get_sprites(t_data *datas)
{
	static char	*img[MAX_IMG] = {FLOOR, WALL, PLAYER, COLLECTIBLE, EXIT};
	int			i;

	i = 0;
	while (i < MAX_IMG)
	{
		datas->img[i].ptr = mlx_xpm_file_to_image(datas->vars.mlx, img[i],
				&datas->img[i].width, &datas->img[i].height);
		if (!datas->img[i].ptr)
			ft_errors(datas, NULL, 8);
		i++;
	}
}

void	so_long(t_data *datas)
{
	datas->vars.mlx = mlx_init();
	if (!datas->vars.mlx)
		ft_errors(datas, NULL, 6);
	datas->vars.win = mlx_new_window(datas->vars.mlx, datas->size_x * RES,
			datas->size_y * RES, "So_Long");
	if (!datas->vars.win)
		ft_errors(datas, NULL, 7);
	get_sprites(datas);
	show_map(datas);
	mlx_key_hook(datas->vars.win, key_hook, datas);
	mlx_hook(datas->vars.win, 17, 0, close_btn, datas);
	mlx_loop(datas->vars.mlx);
}
