/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:19:43 by zcherkao          #+#    #+#             */
/*   Updated: 2022/02/18 15:20:40 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_drawfractal_mandelbrot_5(t_fract *f)
{
	f = ft_mlx();
	mlx_hook(f->window, 4, 0, ft_mouse_1, f);
	mlx_hook(f->window, 2, 0, ft_key_hook_5, f);
	mlx_hook(f->window, 17, 0, red_cross, f);
	mlx_loop_hook(f->mlx, &hundle_no_event_5, f);
	mlx_loop(f->mlx);
}
