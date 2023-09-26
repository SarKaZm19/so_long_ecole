/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:39:44 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/25 19:08:14 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_null(t_data *datas)
{
	int	i;

	i = -1;
	datas->map = NULL;
	datas->vars.mlx = NULL;
	datas->vars.win = NULL;
	datas->player.transformed = 0;
	datas->player.facing = 0;
	datas->antagonist.transformed = 0;
	datas->player.facing = 0;
	datas->fd = -1;
	while (++i < MAX_IMG)
		datas->img[i].ptr = NULL;
	i = -1;
	while (++i < MAX_P_IMG)
		datas->player.img[i].ptr = NULL;
	i = -1;
	while (++i < MAX_A_IMG)
		datas->antagonist.img[i].ptr = NULL;
	datas->c_img[0].ptr = NULL;
	datas->c_img[1].ptr = NULL;
}

int	main(int ac, char **av)
{
	t_data	datas;

	if (ac != 2)
	{
		ft_printf("Error: Usage : ./so_long [PATH_TO_MAP]\n");
		return (1);
	}
	init_null(&datas);
	init_datas(&datas, av[1]);
	so_long(&datas);
	return (0);
}
