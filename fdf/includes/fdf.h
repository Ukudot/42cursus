/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:36:39 by gpanico           #+#    #+#             */
/*   Updated: 2023/08/01 13:51:01 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line_bonus.h"

// macro
# define TRS 50
# define WIDTH 1500
# define HEIGHT 1500

// structs
typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	long	color;
}	t_point;

typedef struct s_mat
{
	int		row;
	int		col;
	t_point	**mat_p;
	t_point	**sphere_p;
	t_point	**p_top_p;
	t_point	**p_front_p;
	t_point	**p_side_p;
}	t_mat;

typedef struct s_wnd
{
	int		height;
	int		width;
	void	*x_ptr;
	void	*wnd_ptr;
}	t_wnd;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_all
{
	t_wnd	wnd;
	t_mat	mat;
	t_img	img;
}	t_all;

// utils
unsigned long	ft_atoul(char *num);
long			ft_atol(char *num);
int				ft_isexa(char c);
void			*ft_realloc(void *p, size_t size, int dim, int new_dim);
void			ft_swap(long *a, long *b);

// map functions
char			***ft_fill_map(char *file, t_mat *mat);
void			ft_destroy_map(char ***map, int row);

// matrix functions
void			ft_map_to_mat(char ***map, t_mat *mat, t_wnd wmd);
t_point			**ft_create_mat_p(int row, int col);
void			ft_destroy_mat_p(t_point **mat_p, int row);
unsigned long	ft_color(char *elem);
void			ft_normalize(t_mat *mat, t_wnd wnd);
void			ft_copy_mat(t_point **dest, t_point **src, int row, int col);

// sphere functions
float			ft_x_s(float x_p, float y_p, float r, int dist[2]);
float			ft_y_s(float x_p, float y_p, float r, int dist[2]);
float			ft_z_s(float x_p, float y_p, float r, int dist[2]);
void			ft_mat_to_sphere(t_mat *mat, t_wnd wnd);
void			ft_draw_sphere(t_all *all);

// check functions
char			***ft_check_input_error(int argc, char *file, t_mat *mat);
void			ft_check_format(int argc);
void			ft_check_map(char ***map, t_mat *mat);
int				ft_count_col(char **map_line);
void			ft_check_map_ext(char *file);
void			ft_check_empty_map(char *file);
void			ft_check_elem(char ***map, t_mat *mat);
void			ft_check_digit(char *elem, char ***map, int row);
void			ft_check_ex(char *elem, char ***map, int row);

// window functions
void			ft_init_window(t_all *all);
void			ft_first_image(t_all *all);

// render functions
void			ft_draw_point(t_all *all, t_point point);
void			ft_draw_lines_rows(t_all *all, t_mat *mat, t_point **points);
void			ft_draw_lines_cols(t_all *all, t_mat *mat, t_point **points);
void			ft_draw_line(t_all *all, t_point point1, t_point point2);
void			ft_draw_mat_p(t_all *all);
long			ft_color_line(long col1, long col2, float x, float l);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);

// bresenham line algorithm
void			ft_draw_line_bresenham(t_all *all, t_point p_1, t_point p_2);
void			ft_bresenham_high(t_all *all, int p1[2], int p[2],
					long color[2]);
void			ft_bresenham_low(t_all *all, int p1[2], int p[2],
					long color[2]);
t_point			ft_new_point_low(int x, int p1[2], int p2[2], long color[2]);
t_point			ft_new_point_high(int i, int p1[2], int p2[2], long color[2]);
void			ft_line_bresenham(t_all *all, int p1[2], int p2[2],
					long color[2]);
void			ft_line_r_bresenham(t_all *all, int p1[2], int p2[2],
					long color[2]);

// commands functions
void			ft_commands_hook(t_all *all);
int				ft_key_control(int keycode, void *param);
void			ft_init_rotate_s(void (*ft_s[6])(t_mat *, float));
void			ft_init_translate(void (*ft_t[150])(t_mat *, float));
int				ft_end(void *param);
void			ft_mat_control(int keycode, t_all *all);
void			ft_sphere_control(int keycode, t_all *all);
int				ft_toggle_p(int keycode, int toggle_p, t_all *all);

// rotate functions
void			ft_rotate_x(t_mat *mat, float theta);
void			ft_rotate_y(t_mat *mat, float theta);
void			ft_rotate_z(t_mat *mat, float theta);
void			ft_rotate_inverse_x(t_mat *mat, float theta);
void			ft_rotate_inverse_y(t_mat *mat, float theta);
void			ft_rotate_inverse_z(t_mat *mat, float theta);

// rotate sphere functions
void			ft_s_rotate_x(t_wnd wnd, t_mat *mat, float theta);
void			ft_s_rotate_y(t_wnd wnd, t_mat *mat, float theta);
void			ft_s_rotate_z(t_wnd wnd, t_mat *mat, float theta);

// parallel functions
void			ft_mat_to_parallel(t_mat *mat);
void			ft_top_rotate_x(t_mat *mat, float theta);
void			ft_top_rotate_y(t_mat *mat, float theta);
void			ft_top_rotate_z(t_mat *mat, float theta);
void			ft_front_rotate_x(t_mat *mat, float theta);
void			ft_front_rotate_y(t_mat *mat, float theta);
void			ft_front_rotate_z(t_mat *mat, float theta);
void			ft_side_rotate_x(t_mat *mat, float theta);
void			ft_side_rotate_y(t_mat *mat, float theta);
void			ft_side_rotate_z(t_mat *mat, float theta);
void			ft_draw_p_top_p(t_all *all);
void			ft_draw_p_front_p(t_all *all);
void			ft_draw_p_side_p(t_all *all);

// translate functions
void			ft_translate_u(t_mat *mat, float trs);
void			ft_translate_d(t_mat *mat, float trs);
void			ft_translate_r(t_mat *mat, float trs);
void			ft_translate_l(t_mat *mat, float trs);

// zoom functions
void			ft_zoom(int x, int y, t_all *all, float zoom);
#endif
