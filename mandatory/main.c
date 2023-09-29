/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:39:44 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/29 15:15:35 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_null(t_data *datas)
{
	int	n;

	n = 0;
	datas->map = NULL;
	datas->vars.mlx = NULL;
	datas->vars.win = NULL;
	datas->fd = -1;
	while (n < MAX_IMG)
	{
		datas->img[n].ptr = NULL;
		n++;
	}
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
