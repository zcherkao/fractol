/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:41:17 by zcherkao          #+#    #+#             */
/*   Updated: 2022/02/17 15:49:21 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	mandelbrot(long double x, long double y, t_fract *f)
{
	int			i;
	t_fract2	g;

	i = 0;
	g.tmpr = 0.0;
	g.tmpi = 0.0;
	g.z_re = 0.0;
	g.z_im = 0.0;
	g.c_re = x * f->zw;
	g.c_im = y * f->zh;
	g.c_re = g.c_re + f->xmin;
	g.c_im = g.c_im + f->ymin;
	while (i < 255 && g.z_re * g.z_re + g.z_im * g.z_im <= 4)
	{
		g.tmpr = g.z_re * g.z_re - g.z_im * g.z_im + g.c_re;
		g.tmpi = 2 * g.z_re * g.z_im + g.c_im;
		g.z_re = g.tmpr;
		g.z_im = g.tmpi;
		i++;
	}
	g.color = ((i * 22) % (255 * 255 * 255));
	return (g.color);
}

void	ft_draw_fractal(t_fract *f)
{
	int	x;
	int	y;
	int	color;

	color = 0;
	x = 0;
	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			color = mandelbrot(x, y, f);
			ft_put_pix(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->img, 0, 0);
}

int	hundle_no_event(t_fract *f)
{
	ft_draw_fractal (f);
	return (0);
}
