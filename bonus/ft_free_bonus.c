/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:37:13 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/25 19:08:09 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_free_imgs(t_data **datas)
{
	int	i;

	i = -1;
	while (++i < MAX_IMG)
	{
		if ((*datas)->img[i].ptr)
			mlx_destroy_image((*datas)->vars.mlx, (*datas)->img[i].ptr);
	}
	i = -1;
	while (++i < MAX_P_IMG)
	{
		if ((*datas)->player.img[i].ptr)
			mlx_destroy_image((*datas)->vars.mlx, (*datas)->player.img[i].ptr);
	}
	i = -1;
	while (++i < MAX_A_IMG)
	{
		if ((*datas)->antagonist.img[i].ptr)
			mlx_destroy_image((*datas)->vars.mlx,
				(*datas)->antagonist.img[i].ptr);
	}
}

void	ft_free_datas(t_data **datas)
{
	if ((*datas)->fd >= 0)
		close((*datas)->fd);
	if ((*datas)->map)
		ft_free_strs_tab((*datas)->map);
	ft_free_imgs(datas);
	if ((*datas)->vars.win)
		mlx_destroy_window((*datas)->vars.mlx, (*datas)->vars.win);
}
