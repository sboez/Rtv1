/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:42:21 by sboez             #+#    #+#             */
/*   Updated: 2018/03/02 20:04:32 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "../minilibx_macos/mlx.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

# define F_ROUGE "\033[0;31m"
# define C_ROUGE "\033[1;31m"
# define F_VERT "\033[0;32m"
# define C_VERT "\033[1;32m"
# define F_JAUNE "\033[0;33m"
# define C_JAUNE "\033[1;33m"
# define F_BLEU "\033[0;34m"
# define C_BLEU "\033[1;34m"
# define F_ROSE "\033[0;35m"
# define C_ROSE "\033[1;35m"
# define F_TURQUOISE "\033[0;36m"
# define C_TURQUOISE "\033[1;36m"
# define F_GREY "\033[0;37m"
# define C_GREY "\033[1;37m"
# define FIN "\033[0m"
# define BLACK_IN_WHITE "\033[1;48;5;255;38;5;16m"
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define WIN_X 1200
# define WIN_Y 750
# define PI M_PI
# define RAD(x) PI * x / 180
# define EXIT 53
# define PLAN 1
# define SPHERE 2
# define CYLINDRE 3
# define CONE 4
# define LUMIERE 5
# define CAMERA 6

typedef struct		s_quad
{
	int				a;
	int				b;
	int				c;
	int				d;
}					t_quad;

typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef struct		s_tvec
{
	t_vect			a;
	t_vect			b;
	t_vect			c;
}					t_tvec;

typedef struct		s_obj
{
	t_vect			ctr;
	double			ray;
	int				color;
	t_vect			n;
	double			angle;
	t_vect			pt;
	t_vect			pos;
	t_vect			view;
	double			p_dist;
	double			p_width;
	double			p_height;
	t_vect			upleft;
	t_vect			idtx;
	t_vect			idty;
	double			its;
}					t_obj;

typedef struct		s_fnd
{
	int				fd;
	double			t;
	int				color;
	int				norm_2;
	t_vect			pt;
	t_obj			*obj;
	t_vect			norm;
	t_vect			norm2;
}					t_fnd;

typedef struct		s_lst
{
	int				name;
	t_obj			*obj;
	void			(*find_obj)(t_vect, t_vect, t_obj *, t_fnd *);
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_env
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	t_obj			*cam;
}					t_env;

int					ft_name(char *buf);
int					ft_error(int i);
int					ft_red_cross(void);
int					ft_key(int keycode);
int					check_main(t_lst *lst);
int					main(int argc, char **argv);
t_lst				*lst_join(t_lst *lst, t_lst *nw);
t_lst				*make_list(char *buf);
int					val_fd(char *filename, char **buf);
t_lst				*file_extract(char *filename);
int					check_buf3(char *str, char *name);
int					check_buf2(char *str);
int					check_buf(char *str);
void				set_obj11(t_obj *obj);
void				set_obj1(int name, char *str, int i, t_obj *obj);
void				set_obj2(int name, char *str, int i, t_obj *obj);
void				set_obj3(int name, char *str, int i, t_obj *obj);
t_obj				*make_obj(int name, char *str, int i);
int					ft_atoi_base(char *str, int base);
int					issp(char c);
int					ft_count_s(char *str);
int					get_next_nbr(char *str, int *i, int base);
t_vect				vec_cross(t_vect a, t_vect b);
t_vect				vec_add(t_vect a, t_vect b);
t_vect				vec_sub(t_vect a, t_vect b);
t_vect				vec_prod(t_vect a, double i);
t_vect				rev_vec(t_vect a);
t_vect				vec_proj(t_vect u, t_vect v);
t_vect				mkvec(t_vect a, t_vect b);
t_vect				do_vec(double x, double y, double z);
t_vect				norma(t_vect a);
double				scal(t_vect a, t_vect b);
double				scal_sqrd(t_vect a);
double				do_dist_sqrd(t_vect a, t_vect b);
double				do_dist(t_vect a);
void				ft_pixies(t_env *e, int x, int y, int color);
double				ft_pow(double a, double b);
double				ft_sqrt(double a);
t_vect				vec_div(t_vect a, double i);
double				ft_solver(double a, double b, double c);
void				ft_plan(t_vect o, t_vect d, t_obj *plan, t_fnd *find);
void				ft_blob(t_vect o, t_vect d, t_obj *sphere, t_fnd *find);
void				ft_ice_cone(t_vect o, t_vect d, t_obj *cne, t_fnd *find);
void				ft_cylinder(t_vect o, t_vect d, t_obj *cld, t_fnd *find);
double				ft_light(t_vect d_li, t_vect norm, t_vect norm2, int color);
int					ft_ray_of_deathmetal(double x, double y, t_lst *lst);
int					ft_ray_of_deathmetal2(t_lst *lst, t_fnd find);
void				ft_ray_of_deathmetal3(t_env *e, int x, int y, t_lst *lst);
int					ft_color_mix(t_quad color);
t_vect				ft_decomp_color(int color);
void				ft_hardstyle_loop(t_env *e, t_lst *lst);
t_vect				ft_whisky(double t, t_vect o, t_vect d);
void				ft_copy_fnd(t_fnd a, t_fnd *b);
double				ft_solver(double a, double b, double c);
double				vec_coss(t_vect u, t_vect v);
t_fnd				init_find(void);
void				set_cam(t_vect *o, t_vect *d, t_lst *lst, t_vect pt);
double				set_light(t_vect *o, t_vect *d, t_fnd *find, t_lst *lst);

#endif
