/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:01:57 by zcherkao          #+#    #+#             */
/*   Updated: 2022/02/18 13:31:29 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include<stdlib.h>
# include<stdio.h>
# include<mlx.h>
# include<unistd.h>

typedef struct s_fract
{
	void		*mlx;
	void		*window;
	int			*tab_img;

	long double	zw;
	long double	zh;
	long double	width;
	long double	hight;
	long double	xmin;
	long double	xmax;
	long double	ymin;
	long double	ymax;
	int			speed;
	long double	x0;
	long double	y0;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_fract;
typedef struct s_fract2
{
	long double	tmpr;
	long double	tmpi;
	long double	c_re;
	long double	c_im;
	long double	z_re;
	long double	z_im;
	int			color;
	int			i;
}				t_fract2;
void	ft_put_pix(t_fract *f, int x, int y, int color);
void	ft_draw_fractal(t_fract *f);
void	ft_draw_fractal_5(t_fract *f);
void	ft_draw_fractal_1(t_fract *f);
int		mandelbrot_1(long double x, long double y, t_fract *f);
int		mandelbrot_5(long double x, long double y, t_fract *f);
int		mandelbrot(long double x, long double y, t_fract *f);
void	ft_drawfractal_mandelbrot_5(t_fract *f);
void	ft_drawfractal_mandelbrot(t_fract *f);
void	ft_drawfractal_julia(t_fract *f);

t_fract	*ft_mlx(void);
int		ft_key_hook(int key, t_fract *f);
int		ft_key_hook_1(int key, t_fract *f);
int		ft_key_hook_5(int key, t_fract *f);
int		ft_mouse_1(int mousekey, int x, int y, t_fract *f);
int		ft_mouse_2(int mousekey, int x, int y, t_fract *f);
int		ft_mouse_3(int mousekey, int x, int y, t_fract *f);
int		ft_mouse_set(int x, int y, t_fract *f);
int		hundle_no_event(t_fract *f);
int		hundle_no_event_5(t_fract *f);
int		hundle_no_event_1(t_fract *f);
void	ft_init(long double x, long double y, t_fract2 *g, t_fract *f);
int		red_cross(t_fract *f);
int		red_cross_1(t_fract *f);
int		ft_xalloc(t_fract2 *g);
#endif
