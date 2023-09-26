/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:37:24 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/27 00:02:43 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "so_long_defines.h"

# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
}			t_img;

typedef struct s_player 
{
	int		pos_x;
	int		pos_y;
	size_t	nb_moves;
	int		nb_collect;
}				t_player;

typedef struct s_data 
{
	int			fd;
	int			size_x;
	int			size_y;
	int			color;
	char		**map;
	t_vars		vars;
	t_img		img[5];
	t_player	player;
}				t_data;

// datas.c
void	init_datas(t_data *datas, char *map_file);

// errors.c
void	ft_errors(t_data *datas, char *content, int errcode);
void	ft_errors2(t_data *datas, int errcode);

// ft_free.c
void	ft_free_datas(t_data **datas);

// img_to_win.c
void	show_map(t_data *datas);

// key_handler.c
void	move_up(t_data *datas);
void	move_down(t_data *datas);
void	move_left(t_data *datas);
void	move_right(t_data *datas);
void	escape_key(t_data *datas);

// pathfinding.c
void	verify_path(t_data *datas);

// player.c
void	get_player_datas(t_data *datas);

// read.c
char	*ft_read(t_data *datas);

// so_long.c
void	so_long(t_data *datas);

// verify_map.c
void	verify_shape(t_data *datas);
void	verify_borders(t_data *datas);
void	verify_content(t_data *datas);

#endif