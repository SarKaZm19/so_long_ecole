/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:37:24 by fvastena          #+#    #+#             */
/*   Updated: 2023/10/04 12:23:17 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include "so_long_defines_bonus.h"

# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>

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
	int			pos_x;
	int			pos_y;
	size_t		nb_moves;
	int			nb_collect;
	int			transformed;
	int			facing;
	t_img		img[6];
}				t_player;

typedef struct s_cont
{
	int			p;
	int			a;
	int			c;
	int			e;
	int			v;
}				t_cont;

typedef struct s_data 
{
	int				fd;
	int				size_x;
	int				size_y;
	int				color;
	int				enemy_count;
	int				nb_player;
	char			**map;
	unsigned long	start_time;
	unsigned long	elapsed;
	t_cont			content;
	t_vars			vars;
	t_img			img[4];
	t_img			c_img[2];
	t_player		antagonist;
	t_player		player;
}				t_data;

// antag_key_handler_bonus.c
void			a_move_up(t_data *datas);
void			a_move_down(t_data *datas);
void			a_move_left(t_data *datas);
void			a_move_right(t_data *datas);

// datas_bonus.c
void			init_datas(t_data *datas, char *map_file);

// errors_bonus.c
void			ft_errors(t_data *datas, char *content, int errcode);

// exit_handler_bonus.c
void			exit_handler(t_data *datas, int exit_code);
void			enemy_handler(t_data *datas, char c);

// ft_free_bonus.c
void			ft_free_datas(t_data **datas);

// get_img_from_file_bonus.c
void			get_sprites(t_data *datas);

// img_to_win_bonus.c
void			show_map(t_data *datas);

// pathfinding_bonus.c
void			verify_path(t_data *datas);

// player_key_handler_bonus.c
void			p_move_up(t_data *datas);
void			p_move_down(t_data *datas);
void			p_move_left(t_data *datas);
void			p_move_right(t_data *datas);

// players_bonus.c
void			get_player_datas(t_data *datas);
void			get_antag_datas(t_data *datas);

// put_players_to_win_bonus.c
void			put_player_facing_img(t_data *datas, int x, int y);
void			put_player_ev_facing_img(t_data *datas, int x, int y);
void			put_player_img(t_data *datas, int x, int y);
void			put_antagonist_img(t_data *datas, int x, int y);

// read_bonus.c
char			*ft_read(t_data *datas);

// render_bonus.c
int				render(t_data *datas);

//so_long_bonus.c
void			so_long(t_data *datas);

// time_bonus.c
unsigned long	gettime(t_data *datas);

// utils_bonus.c
char			*ft_strdup2(t_data *datas, const char *s);
char			*ft_strjoin2(t_data *datas, char const *s1, char const *s2);
char			*create_str(t_data *datas, char *str, char *dup_str, int nb);

// verify_map_bonus.c
void			verify_shape(t_data *datas);
void			verify_borders(t_data *datas);
void			verify_content(t_data *datas);

#endif