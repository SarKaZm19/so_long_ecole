/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:37:19 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/29 16:02:08 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**add_line(t_data *datas, char **map, char *line, int *count_line)
{
	char	**new_map;
	int		i;

	*count_line += 1;
	if (!line)
		return (map);
	new_map = malloc(sizeof(char *) * (*count_line + 1));
	if (!new_map)
		return (ft_errors(datas, "malloc", 1), NULL);
	i = -1;
	while (map[++i])
		new_map[i] = map[i];
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}

static char	**get_map(t_data *datas)
{
	char	**map;
	int		count_line;

	map = malloc(sizeof(char *) * 2);
	if (!map)
		ft_errors(datas, "malloc", 1);
	map[1] = NULL;
	map[0] = ft_read(datas);
	count_line = 1;
	while (map[count_line - 1])
	{
		if (count_line * RES > 1080)
			ft_errors(datas, NULL, 3);
		map = add_line(datas, map, ft_read(datas), &count_line);
	}
	datas->size_y = count_line - 1;
	return (map);
}

static int	ber_error(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 5)
		return (0);
	if (ft_strncmp(file_name + len - 4, ".ber", 4))
		return (0);
	return (1);
}

void	init_datas(t_data *datas, char *map_file)
{
	if (!ber_error(map_file))
		ft_errors(datas, map_file, 0);
	datas->fd = open(map_file, O_RDONLY);
	if (datas->fd < 0)
		ft_errors(datas, "open", 1);
	datas->map = get_map(datas);
	if (datas->fd >= 0)
	{
		close(datas->fd);
		datas->fd = -1;
	}
	verify_shape(datas);
	verify_borders(datas);
	verify_content(datas);
	get_player_datas(datas);
	verify_path(datas);
}
