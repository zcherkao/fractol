/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:35:01 by zcherkao          #+#    #+#             */
/*   Updated: 2022/02/18 18:15:31 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_drawfractal_mandelbrot(t_fract *f)
{
	f = ft_mlx();
	mlx_hook(f->window, 4, 0, ft_mouse_2, f);
	mlx_hook(f->window, 2, 0, ft_key_hook, f);
	mlx_hook(f->window, 17, 0, red_cross_1, f);
	mlx_loop_hook(f->mlx, &hundle_no_event, f);
	mlx_loop(f->mlx);
}

void	ft_drawfractal_julia(t_fract *f)
{
	f = ft_mlx();
	mlx_hook(f->window, 4, 0, ft_mouse_3, f);
	mlx_hook(f->window, 6, 0, ft_mouse_set, f);
	mlx_hook(f->window, 2, 0, ft_key_hook_1, f);
	mlx_hook(f->window, 17, 0, red_cross_1, f);
	mlx_loop_hook(f->mlx, &hundle_no_event_1, f);
	mlx_loop(f->mlx);
}
