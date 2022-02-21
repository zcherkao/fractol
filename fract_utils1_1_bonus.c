/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils1_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:17:02 by zcherkao          #+#    #+#             */
/*   Updated: 2022/02/18 15:17:57 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_mouse_1(int mousekey, int x, int y, t_fract *f)
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
	ft_draw_fractal_5(f);
	return (0);
}
