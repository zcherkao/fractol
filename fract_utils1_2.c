/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils1_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:35:11 by zcherkao          #+#    #+#             */
/*   Updated: 2022/02/18 18:15:24 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_key_hook(int key, t_fract *f)
{
	if (key == 123)
		f->xmin += 30 * f->zw;
	else if (key == 124)
		f->xmin -= 30 * f->zw;
	else if (key == 125)
		f->ymin -= 30 * f->zh;
	else if (key == 126)
		f->ymin += 30 * f->zh;
	else if (key == 53)
	{
		mlx_destroy_window(f->mlx, f->window);
		free(f);
		exit(1);
	}
	ft_draw_fractal(f);
	return (0);
}

int	ft_key_hook_1(int key, t_fract *f)
{
	if (key == 123)
		f->xmin += 30 * f->zw;
	else if (key == 124)
		f->xmin -= 30 * f->zw;
	else if (key == 125)
		f->ymin -= 30 * f->zh;
	else if (key == 126)
		f->ymin += 30 * f->zh;
	else if (key == 53)
	{
		mlx_destroy_window(f->mlx, f->window);
		free(f);
		exit(1);
	}	
	ft_draw_fractal_1(f);
	return (0);
}

int	red_cross_1(t_fract *f)
{
	free(f);
	exit(1);
}
