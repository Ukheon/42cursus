/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ukwon <Ukwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 03:33:37 by ukwon             #+#    #+#             */
/*   Updated: 2021/03/07 23:44:19 by Ukwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D
// # include "../mlx2/mlx.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFFER_SIZE		100
# define _ERROR				-1
# define _ENDFILE			0
# define _NOTEND			1
# define A 0
# define S 1
# define D 2
# define W 13
# define Q 12
# define E 14
# define ESC 53
# define map_w 24
# define map_h 24
# define text_width 64
# define text_height 64

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		len;
	int			index;
}				t_sprite;

typedef struct	s_storage
{
	struct s_storage	*next;
	char				*data;
}				t_storage;

typedef struct	s_grid
{
	int			check_map_data;
	int			i;
	int			j;
	int			x;
	int			y;
	double		width_size;
	double		height_size;
	double		width;
	double		height;
	double		player_x;
	double		player_y;
}				t_grid;

typedef struct	s_zip
{
	int			w;
	int			h;
	char		*file_name;
	
	int			key_m;
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_q;
	int			key_e;
	int			key_esc;

	int			row;
	int			flag_count;
	int			temp_i;
	int			temp_j;
	int			map_check_flag;
	int			player_check;
	char		**map;
	char		*line;
	char		**split;
	int			fd;
	int			ret;
	int			height_size;
	int			width_size;
	int			check;
	int			num;
	int			res;
	int			count;
	int			idx;
	char		**color_save;
	int			c_color;
	int			f_color;
	int			map_width;
	int			map_height;

	int			width;
	int			height;
	double		save_wall_len[4096];
	void		*mlx;
	void		*win;
	t_img		img;
	double		dir_x;
	double		dir_y;
	double		player_x;
	double		player_y;
	double		ray_x;
	double		ray_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;

	int			**buf;
	int			**texture;

	double		camera;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_x;
	double		delta_y;
	double		raylen;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;

	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall;
	int			text_num;
	int			text_x;
	int			text_y;
	double		text_step;
	double		text_pos;

	int			count_sprite;
	int			*order;
	t_sprite	*sprite;
	double		relative_x;
	double		relative_y;
	double		transform_x;
	double		transform_y;
	int			sprite_screen;
	int			sprite_height;
	int			sprite_width;
	int			sprite_start_x;
	int			sprite_start_y;
	int			sprite_end_x;
	int			sprite_end_y;
	int			color;
	double		sub;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*s_texture;
}				t_zip;

//main
void			add_storage(t_storage *target, char *str, t_zip *zip);
void			get_map(t_zip *zip, int i, char *str, t_storage *head);
void			zip_set(t_zip *zip);
void			draw(t_zip *zip, int x, int y);
void			calc(t_zip *zip, int x, int y);
void			get_img(t_zip *zip, int *texture, char *path, t_img *img);
void			img_load(t_zip *zip);
int				main_loop(t_zip *zip);
int				player_move(t_zip *zip);
int				key_press(int key, t_zip *zip);
int				key_release(int key, t_zip *zip);
void			get_bitmap_data(t_zip *zip);
void			check_player_vec(t_zip *zip);
void			get_sprite(t_zip *zip, int x);
void			check_size(t_zip *zip);
void			init_game(t_zip *zip, char *str);
void			draw_map(t_zip *zip);
int				key_exit(void);
void			split_free(t_zip *zip);
char 			*ft_strnstr(const char *big, const char *little, size_t len);
//mapcheck
void 			map_row_test(int i, int j, t_zip *zip);
void			map_col_test(int i, int j, t_zip *zip);
void			map_check(t_zip *zip);
void			cub3d_error(char *error);
int				parsing_error(t_zip *zip);
void			cub_file_check(int argc, char *str);
//gnl
int				get_next_line(int fd, char **line);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s1);
//libft
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			**ft_split(char const *s, char *sep, t_zip *zip);

void no_texture(t_zip *zip);
void we_texture(t_zip *zip);
void ea_texture(t_zip *zip);
void s_texture(t_zip *zip);
void so_texture(t_zip *zip);
#endif
