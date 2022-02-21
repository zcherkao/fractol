/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_5->c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student->42->fr>          +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:00:42 by zcherkao          #+#    #+#             */
/*   Updated: 2022/02/17 18:38:31 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_init(long double x, long double y, t_fract2 *g, t_fract *f)
{
	g->tmpr = 0.0;
	g->tmpi = 0.0;
	g->z_re = 0.0;
	g->z_im = 0.0;
	g->c_re = x * f->zw;
	g->c_im = y * f->zh;
	g->c_re = g->c_re + f->xmin;
	g->c_im = g->c_im + f->ymin;
}

int	mandelbrot_5(long double x, long double y, t_fract *f)
{
	int			i;
	t_fract2	*g;

	g = malloc (sizeof(t_fract2));
	if (!g)
		ft_xalloc (g);
	i = 0;
	ft_init (x, y, g, f);
	while (i < 255 && g->z_re * g->z_re + g->z_im * g->z_im <= 4)
	{
		g->tmpr = g->z_re * g->z_re * g->z_re * g->z_re
			* g->z_re - 10 * g->z_re * g->z_re
			* g->z_re * g->z_im * g->z_im + 5 * g->z_re
			* g->z_im * g->z_im * g->z_im * g->z_im + g->c_re;
		g->tmpi = 5 * g->z_re * g->z_re * g->z_re * g->z_re
			* g->z_im - 10 * g->z_re * g->z_re
			* g->z_im * g->z_im * g->z_im + g->z_im
			* g->z_im * g->z_im * g->z_im * g->z_im + g->c_im;
		g->z_re = g->tmpr;
		g->z_im = g->tmpi;
		i++;
	}
	return ((i * 22) % (255 * 255 * 255));
}

void	ft_draw_fractal_5(t_fract *f)
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
			color = mandelbrot_5(x, y, f);
			ft_put_pix(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->img, 0, 0);
}

int	hundle_no_event_5(t_fract *f)
{
	ft_draw_fractal_5 (f);
	return (0);
}

int	ft_xalloc(t_fract2 *g)
{
	free (g);
	return (0);
}
