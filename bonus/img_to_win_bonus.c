/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_win_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:23:11 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/26 13:25:41 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_scoreboard_simple(t_data *datas)
{
	char	*total;

	total = NULL;
	total = create_str(datas, total, "Moves: ", datas->player.nb_moves);
	mlx_string_put(datas->vars.mlx, datas->vars.win,
		(datas->size_x - 2) / 2 * RES, 
		datas->size_y * RES + RES / 3, 0x000000FF, total);
	free(total);
}

static void	put_scoreboard_full(t_data *datas)
{
	char	*total;
	int		total_size;

	total = NULL;
	total = create_str(datas, total, "Moves: ", datas->player.nb_moves);
	total = create_str(datas, total, "    Collectibles: ",
			datas->player.nb_collect);
	total = create_str(datas, total, "    Enemies: ", datas->enemy_count);
	total_size = ft_strlen(total);
	mlx_string_put(datas->vars.mlx, datas->vars.win,
		(datas->size_x - 9) / 2 * RES,
		datas->size_y * RES + RES / 3, 0x000000FF, total);
	free(total);
}

static void	put_collect_img(t_data *datas, int x, int y)
{
	int	pos_p;
	int	pos_a;

	pos_p = datas->player.pos_x + datas->player.pos_y;
	pos_a = datas->antagonist.pos_x + datas->antagonist.pos_y;
	if ((pos_p + pos_a) % 2)
	{
		mlx_put_image_to_window(datas->vars.mlx, datas->vars.win,
			datas->c_img[0].ptr, x * RES, y * RES);
	}
	else
	{
		mlx_put_image_to_window(datas->vars.mlx, datas->vars.win,
			datas->c_img[1].ptr, x * RES, y * RES);
	}
}

static void	insert_img_to_map(t_data *datas, char c, int x, int y)
{
	int			i;
	static char	str[5] = "01EV";

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	if (c == 'P')
		put_player_img(datas, x, y);
	else if (c == 'A')
		put_antagonist_img(datas, x, y);
	else if (c == 'C')
		put_collect_img(datas, x, y);
	else
	{
		mlx_put_image_to_window(datas->vars.mlx,
			datas->vars.win, datas->img[i].ptr, x * RES, y * RES);
	}
}

void	show_map(t_data *datas)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	mlx_clear_window(datas->vars.mlx, datas->vars.win);
	while (y < datas->size_y)
	{
		x = 0;
		while (x < datas->size_x)
		{
			insert_img_to_map(datas, datas->map[y][x], x, y);
			x++;
		}
		y++;
	}
	if (datas->size_x >= 9)
		put_scoreboard_full(datas);
	else
		put_scoreboard_simple(datas);
}
