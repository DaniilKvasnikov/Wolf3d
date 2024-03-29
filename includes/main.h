/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:44:56 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/12 15:05:15 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ft_printf.h"
# include <mlx.h>
# include <math.h>

# define WIN_H 1300
# define WIN_W (WIN_H * 16 / 10)
# define WIN_S (WIN_W * WIN_H)
# define X_P 0
# define Y_P 1

# define B_SPACE 49
# define B_ESC 53
# define B_W 13
# define B_S 1
# define B_A 0
# define B_D 2
# define B_NUM_4 86
# define B_NUM_6 88

# define PRIN_RET(a,s) {if (a){ft_putendl(s); return (0);}}
# define BLOCK_1(a, b, c, d) {a -= b; c += d;}
# define BLOCK_2(a, b, c, d, e) {if ((a += e) >= b) BLOCK_1(a, b, c, d);}
# define SGN(x) ((x < 0) ? -1 : ((x > 0) ? 1 : 0))

# define RGB_RED 0xff0000
# define RGB_GREEN 0x00ff00
# define RGB_BLUE 0x87cefa
# define RGB_WHITE 0xffffff
# define RGB_YELLOW 0xffff33
# define RGB_BLACK 0x000000

# define BUF_SIZE 1024

typedef struct	s_raycast
{
	int		x;
	int		draw_pos[2];
	double	ray_dirx;
	double	ray_diry;
	int		mapx;
	int		mapy;
	double	side_distx;
	double	side_disty;
	int		stepx;
	int		stepy;
	double	delta_distx;
	double	delta_disty;
	double	perp_walldist;
	int		side;
	int		line_height;
	int		color;
	int		tex_num;
	int		y;
	double	wallx;
	int		texx;
	int		d;
	int		texy;
	double	floorx_wall;
	double	floory_wall;
	double	dist_wall;
	double	dist_player;
	double	current_dist;
	double	weight;
	double	current_floorx;
	double	current_floory;
	int		floor_texx;
	int		floor_texy;
}				t_raycast;

typedef struct	s_texture
{
	void		*image;
	int			*data;
	int			bpp;
	int			sizeline;
	int			end;
}				t_texture;

typedef struct	s_map
{
	int			*map;
	int			*flags;
	int			*size;
}				t_map;

typedef struct	s_mydata
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			**world_map;
	t_map		map;
	t_texture	texture[5];
	int			move;
	int			turn;
	int			run;
	char		**argv;
	int			argc;
}				t_mydata;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		*img;
	t_mydata	*mydata;
}				t_data;

void			ft_open_win(char *str, int argc, char **argv);

int				ft_draw(t_data *data);
void			ft_draw_px(t_data *data, int x, int y, int color);
void			line_fast(t_data *env, double *p1, double *p2, int color);
void			ft_linefast_int(t_data *data, int *p1, int *p2, int color);
void			ft_draw_square(t_data *data, int *pos, int rad, int color);
void			ft_clearwin(t_data *data);

int				key_press(int key, t_data *data);
int				key_release(int key, t_data *data);

int				ft_close(t_data *data);

void			ft_map_init(t_data *data, char *filename);
char			*ft_get_file_str(char *filename);
int				ft_check_str(char *str);
void			ft_create_map(t_data *data, char *str);
int				*ft_get_size(char *str);
void			ft_free_ptr(void *data);
void			ft_free(char **str);

void			load_textures(t_data *data);

void			ft_raycast(t_data *data);

void			player_move(t_data *data, double move_speed);
void			player_turn(t_data *data, double rot_speed);

int				ft_is_flag(t_data *data, char *str);

void			ft_raycast_block1(t_data *data, t_raycast *r);
void			ft_raycast_block2(t_data *data, t_raycast *r);
void			ft_raycast_block3(t_data *data, t_raycast *r);
void			ft_raycast_block4(t_raycast *r);
void			ft_raycast_block5(t_data *data, t_raycast *r);

void			ft_draw_map(t_data *data);
void			ft_map_check(t_data *data);
void			ft_map_clear(t_data *data);

#endif
