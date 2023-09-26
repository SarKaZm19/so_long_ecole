/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:54:40 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/25 16:25:45 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			ft_errors(datas, NULL, 3);
		y++;
	}
	if (datas->size_x * datas->size_y < 15 || datas->size_x < 3
		|| datas->size_y < 3)
		ft_errors(datas, NULL, 2);
	if (datas->size_x * RES > 1920 || datas->size_y * RES > 1080)
		ft_errors(datas, NULL, 4);
}

void	verify_borders(t_data *datas)
{
	int	i;

	i = -1;
	while (++i < datas->size_x)
		if (datas->map[0][i] != '1' || datas->map[datas->size_y - 1][i] != '1')
			ft_errors(datas, NULL, 5);
	i = -1;
	while (++i < datas->size_y)
		if (datas->map[i][0] != '1' || datas->map[i][datas->size_x - 1] != '1')
			ft_errors(datas, NULL, 5);
}

static int	verify_item(char item, int *p, int *c, int *e)
{
	if (item == '0' || item == '1')
		return (1);
	else if (item == 'P')
		*p += 1;
	else if (item == 'C')
		*c += 1;
	else if (item == 'E')
		*e += 1;
	else
		return (0);
	return (1);
}

void	verify_content(t_data *datas)
{
	int	p;
	int	c;
	int	e;
	int	y;
	int	x;

	p = 0;
	c = 0;
	e = 0;
	y = -1;
	while (++y < datas->size_y)
	{
		x = -1;
		while (++x < datas->size_x)
			if (!verify_item(datas->map[y][x], &p, &c, &e))
				ft_errors(datas, NULL, 6);
	}
	datas->player.nb_collect = c;
	if (p != 1 || c < 1 || e != 1)
		ft_errors(datas, NULL, 6);
}
