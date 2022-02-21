/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils1_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:40:04 by zcherkao          #+#    #+#             */
/*   Updated: 2022/02/18 18:15:18 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_mouse_2(int mousekey, int x, int y, t_fract *f)
{
	if (mousekey == 5)
	{
		f->zw *= 0.5;
		f->zh *= 0.5;
		f->xmin = f->xmin + (x * f->zw);
		f->ymin = f->ymin + (y * f->zh);
	}
	else if (mousekey == 4)
	{
		f->xmin = f->xmin - (x * f->zw);
		f->ymin = f->ymin - (y * f->zh);
		f->zw /= 0.5;
		f->zh /= 0.5;
	}
	ft_draw_fractal(f);
	return (0);
}

int	ft_mouse_3(int mousekey, int x, int y, t_fract *f)
{
	if (mousekey == 5)
	{
		f->zw *= 0.5;
		f->zh *= 0.5;
		f->xmin = f->xmin + (x * f->zw);
		f->ymin = f->ymin + (y * f->zh);
	}
	else if (mousekey == 4)
	{
		f->xmin = f->xmin - (x * f->zw);
		f->ymin = f->ymin - (y * f->zh);
		f->zw /= 0.5;
		f->zh /= 0.5;
	}
	ft_draw_fractal_1(f);
	return (0);
}

int	ft_mouse_set(int x, int y, t_fract *f)
{
	f->x0 = x * (f->zw) + f->ymin;
	f->y0 = y * (f->zh) + f->ymin;
	ft_draw_fractal_1(f);
	return (0);
}
