/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:54:40 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/29 15:41:50 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	verify_shape(t_data *datas)
{
	int	x;
	int	y;

	datas->size_x = ft_strlen(datas->map[0]) - 1;
	y = 0;
	while (datas->map[y])
	{
		x = 0;
		while (datas->map[y][x] && datas->map[y][x] != '\n')
			x++;
		if (x != datas->size_x)
			ft_errors(datas, NULL, 2);
		y++;
	}
}

void	verify_borders(t_data *datas)
{
	int	i;

	i = -1;
	while (++i < datas->size_x)
		if (datas->map[0][i] != '1' || datas->map[datas->size_y - 1][i] != '1')
			ft_errors(datas, NULL, 4);
	i = -1;
	while (++i < datas->size_y)
		if (datas->map[i][0] != '1' || datas->map[i][datas->size_x - 1] != '1')
			ft_errors(datas, NULL, 4);
}

static int	verify_item(char item, t_cont *content)
{
	if (item == '0' || item == '1')
		return (1);
	else if (item == 'P')
		content->p += 1;
	else if (item == 'C')
		content->c += 1;
	else if (item == 'E')
		content->e += 1;
	else if (item == 'V')
		content->v += 1;
	else if (item == 'A')
		content->a += 1;
	else
		return (0);
	return (1);
}

void	verify_content(t_data *datas)
{
	t_cont	content;
	int		y;
	int		x;

	content.p = 0;
	content.c = 0;
	content.e = 0;
	content.v = 0;
	content.a = 0;
	y = -1;
	while (++y < datas->size_y)
	{
		x = -1;
		while (++x < datas->size_x)
			if (!verify_item(datas->map[y][x], &content))
				ft_errors(datas, NULL, 5);
	}
	datas->player.nb_collect = content.c;
	datas->enemy_count = content.v;
	if (content.p != 1 || content.c < 1 || content.e != 1)
		ft_errors(datas, NULL, 5);
}
