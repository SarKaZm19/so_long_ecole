/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:37:13 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/26 13:05:23 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_datas(t_data **datas)
{
	int	i;

	i = -1;
	if ((*datas)->fd >= 0)
		close((*datas)->fd);
	if ((*datas)->map)
		ft_free_strs_tab((*datas)->map);
	while (++i < MAX_IMG)
	{
		if ((*datas)->img[i].ptr)
			mlx_destroy_image((*datas)->vars.mlx, (*datas)->img[i].ptr);
	}
	if ((*datas)->vars.win)
		mlx_destroy_window((*datas)->vars.mlx, (*datas)->vars.win);
}
