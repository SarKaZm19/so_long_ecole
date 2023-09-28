/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:31:10 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/28 14:09:08 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_errors(t_data *datas, char *content, int errcode)
{
	ft_printf("Error\n");
	if (errcode == 0)
		ft_printf("\"%s\". Map should be a .ber file\n", content);
	else if (errcode == 1)
		ft_printf("%s failed\n", content);
	else if (errcode == 2)
		ft_printf("Map is too small\n");
	else if (errcode == 3)
		ft_printf("Map has wrong shape\n");
	else if (errcode == 4)
		ft_printf("Map is too big (max 1920x1080)\n");
	else if (errcode == 5)
		ft_printf("Map is not surronded by walls\n");
	else if (errcode == 6)
		ft_printf("Map has invalid items\n");
	else if (errcode == 7)
		ft_printf("mlx_ptr could not be set\n");
	else if (errcode == 8)
		ft_printf("mlx_win could not be set\n");
	else if (errcode == 9)
		ft_printf("Images could not be generated\n");
	else if (errcode == 10)
		ft_printf("Could not find a path to solve the map\n");
	ft_free_datas(&datas);
	exit(EXIT_FAILURE);
}
