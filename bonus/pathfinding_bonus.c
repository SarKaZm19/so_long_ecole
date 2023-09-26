/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:22:49 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/23 12:34:48 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	**clone_map(t_data *datas)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * ((datas->size_y) + 1));
	if (!new_map)
		ft_errors(datas, "malloc", 1);
	i = -1;
	while (++i < datas->size_y)
	{
		new_map[i] = ft_strdup(datas->map[i]);
		if (!new_map[i])
			ft_errors(datas, "malloc", 1);
	}
	new_map[i] = NULL;
	return (new_map);
}

static int	verify_path_finding(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == '0' ||
				map[i][j] == 'X' || map[i][j] == '\n')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

static void	path_finding(char **map, int nb_collect, int j, int i)
{
	if (map[j][i] == '1')
		return ;
	if (map[j][i] == 'X')
		return ;
	map[j][i] = 'X';
	path_finding(map, nb_collect, j, i + 1);
	path_finding(map, nb_collect, j, i - 1);
	path_finding(map, nb_collect, j + 1, i);
	path_finding(map, nb_collect, j - 1, i);
}

void	verify_path(t_data *datas)
{
	char	**map_clone;
	int		i;
	int		j;
	int		collect;

	map_clone = clone_map(datas);
	collect = datas->player.nb_collect;
	i = datas->player.pos_x;
	j = datas->player.pos_y;
	path_finding(map_clone, collect, j, i);
	if (verify_path_finding(map_clone))
	{
		ft_free_strs_tab(map_clone);
		ft_errors(datas, NULL, 10);
	}
	ft_free_strs_tab(map_clone);
}
