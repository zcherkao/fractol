/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils_1_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:18:52 by zcherkao          #+#    #+#             */
/*   Updated: 2022/02/18 15:19:17 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_key_hook_5(int key, t_fract *f)
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
	ft_draw_fractal_5(f);
	return (0);
}

int	red_cross(t_fract *f)
{
	free(f);
	exit(1);
}
