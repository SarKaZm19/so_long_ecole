/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:26:13 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/28 14:53:36 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_handler(t_data *datas, int exit_code)
{
	if (exit_code == 0 && datas->player.nb_collect == 0)
	{
		ft_printf("I hope you had fun in this so_long !\n");
		ft_free_datas(&datas);
		exit(EXIT_SUCCESS);
	}
	else if (exit_code == 1)
	{
		ft_free_datas(&datas);
		exit(EXIT_SUCCESS);
	}
}

static void	enemy_exit_handler(t_data *datas, char *msg, int code)
{
	if (code == 0)
	{
		ft_printf(msg);
		datas->enemy_count--;
	}
	else if (code == 1)
	{
		ft_printf(msg);
		exit_handler(datas, 1);
	}
}

void	enemy_handler(t_data *datas, char c)
{
	if (datas->player.transformed == 0)
	{
		if (c == 'V')
			enemy_exit_handler(datas, "Player defeated\n", 1);
		else if (c == 'A')
			enemy_exit_handler(datas, "Antagonist Won\n", 1);
	}
	else if (datas->player.transformed == 1)
	{
		if (c == 'V')
			enemy_exit_handler(datas, "Enemy defeated\n", 0);
		else if (c == 'A')
			enemy_exit_handler(datas, "Antagonist Won\n", 1);
	}
}
