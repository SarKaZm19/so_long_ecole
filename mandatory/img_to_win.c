/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:23:11 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/21 21:03:33 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	insert_img_to_map(t_data *data, char c, int x, int y)
{
	int			n;
	static char	str[6] = "01PCE";

	n = 0;
	while (str[n])
	{
		if (str[n] == c)
			break ;
		n++;
	}
	mlx_put_image_to_window(data->vars.mlx, data->vars.win, data->img[n].ptr,
		x * RES, y * RES);
}

void	show_map(t_data *datas)
{
	int	x;
	int	y;

	y = 0;
	if (datas->player.nb_moves > INT_MAX)
		ft_errors(datas, NULL, 11);
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
}
