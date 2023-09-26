/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:22:49 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/26 23:59:56 by fvastena         ###   ########.fr       */
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

/* static int	verify_path_finding(char **map)
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
} */

/* static void	path_finding(char **map, int nb_collect, int j, int i)
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
} */

/* void	verify_path(t_data *datas)
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
} */

static void	path_finding_collect(char **map, int *collect, int j, int i)
{
	if (map[j][i] == 'C')
		*collect -= 1;
	map[j][i] = 'X';
	if (map[j][i + 1] != '1' && map[j][i + 1] != 'X' && map[j][i + 1] != 'E'  && map[j][i + 1] != 'V')
		path_finding_collect(map, collect, j, i + 1);
	if (map[j][i - 1] != '1' && map[j][i - 1] != 'X' && map[j][i - 1] != 'E'  && map[j][i - 1] != 'V')
		path_finding_collect(map, collect, j, i - 1);
	if (map[j + 1][i] != '1' && map[j + 1][i] != 'X' && map[j + 1][i] != 'E'  && map[j + 1][i] != 'V')
		path_finding_collect(map, collect, j + 1, i);
	if (map[j - 1][i] != '1' && map[j - 1][i] != 'X' && map[j - 1][i] != 'E'  && map[j - 1][i] != 'V')
		path_finding_collect(map, collect, j - 1, i);
}

static void	path_finding_exit(char **map, int *collect, int j, int i)
{
	if (map[j][i] == 'E')
	{
		*collect -= 1;
		map[j][i] = 'X';
		return ;
	}
	map[j][i] = 'X';
	if (map[j][i + 1] != '1' && map[j][i + 1] != 'X')
		path_finding_exit(map, collect, j, i + 1);
	if (map[j][i - 1] != '1' && map[j][i - 1] != 'X')
		path_finding_exit(map, collect,j, i - 1);
	if (map[j + 1][i] != '1' && map[j + 1][i] != 'X')
		path_finding_exit(map, collect,j + 1, i);
	if (map[j - 1][i] != '1' && map[j - 1][i] != 'X')
		path_finding_exit(map, collect,j - 1, i);
}

static void	print_map(char **map)
{
	int i = -1;
	while (map[++i])
	{
		ft_printf("%s", map[i]);
	}
}

void	verify_path(t_data *datas)
{
	char	**map_clone;
	char	**map_clone2;
	int		i;
	int		j;
	int		collect;

	map_clone = clone_map(datas);
	map_clone2 = clone_map(datas);
	collect = datas->player.nb_collect + 1;
	i = datas->player.pos_x;
	j = datas->player.pos_y;
	path_finding_collect(map_clone, &collect, j, i);
	print_map(map_clone);
	if (collect == 1)
	{
		ft_printf("\ncollect = %d\n", collect);
		path_finding_exit(map_clone2, &collect, j, i);
		print_map(map_clone2);
	}
	if (collect)
	{
		ft_printf("\ncollect_error = %d\n", collect);
		ft_free_strs_tab(map_clone);
		ft_free_strs_tab(map_clone2);
		ft_errors(datas, NULL, 10);
	}
	ft_printf("\ncollect_ex = %d\n", collect);
	ft_free_strs_tab(map_clone);
	ft_free_strs_tab(map_clone2);
}
