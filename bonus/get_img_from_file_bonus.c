/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_from_file_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:45:10 by fvastena          #+#    #+#             */
/*   Updated: 2023/10/02 13:29:24 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	get_img_sprites(t_data *datas)
{
	static char	*img[MAX_IMG] = {FLOOR, WALL, EXIT, VILAIN};
	int			i;

	i = -1;
	while (++i < MAX_IMG)
	{
		datas->img[i].ptr = mlx_xpm_file_to_image(datas->vars.mlx, img[i],
				&datas->img[i].width, &datas->img[i].height);
		if (!datas->img[i].ptr)
			ft_errors(datas, NULL, 8);
	}
}

static void	get_player_sprites(t_data *datas)
{
	static char	*p_img[MAX_P_IMG] = {PLAYER_RD, PLAYER_U, PLAYER_L,
		PLAYER_EV_RD, PLAYER_EV_U, PLAYER_EV_L};
	int			i;

	i = -1;
	while (++i < MAX_P_IMG)
	{
		datas->player.img[i].ptr = mlx_xpm_file_to_image(datas->vars.mlx,
				p_img[i], &datas->player.img[i].width,
				&datas->player.img[i].height);
		if (!datas->player.img[i].ptr)
			ft_errors(datas, NULL, 8);
	}
}

static void	get_antagonist_sprites(t_data *datas)
{
	static char	*a_img[MAX_A_IMG] = {ANTAGONIST_RD,
		ANTAGONIST_U, ANTAGONIST_L};
	int			i;

	i = -1;
	while (++i < MAX_A_IMG)
	{
		datas->antagonist.img[i].ptr = mlx_xpm_file_to_image(datas->vars.mlx,
				a_img[i], &datas->antagonist.img[i].width,
				&datas->antagonist.img[i].height);
		if (!datas->antagonist.img[i].ptr)
			ft_errors(datas, NULL, 8);
	}
}

void	get_sprites(t_data *datas)
{
	static char	*c_img[2] = {COLLECTIBLE1, COLLECTIBLE2};

	get_img_sprites(datas);
	get_player_sprites(datas);
	get_antagonist_sprites(datas);
	datas->c_img[0].ptr = mlx_xpm_file_to_image(datas->vars.mlx,
			c_img[0], &datas->c_img[0].width, &datas->c_img[1].height);
	datas->c_img[1].ptr = mlx_xpm_file_to_image(datas->vars.mlx,
			c_img[1], &datas->c_img[1].width, &datas->c_img[1].height);
	if (!datas->c_img[0].ptr || !datas->c_img[1].ptr)
		ft_errors(datas, NULL, 8);
}
