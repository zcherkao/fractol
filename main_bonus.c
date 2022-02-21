/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherkao <zcherkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:23:29 by zcherkao          #+#    #+#             */
/*   Updated: 2022/02/20 15:31:23 by zcherkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*l;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s1;
	l = (unsigned char *)s2;
	if (!s1 && !s2)
		return (0);
	if (n == 0)
		return (0);
	while (p[i] == l[i] && (i < n) && p[i] && l[i])
		i++;
	if (i == n)
		return (0);
	return (p[i] - l[i]);
}

void	ft_mlx_init(t_fract *f)
{
	f->xmin = -2.0;
	f->xmax = 2.0;
	f->ymin = -2.0;
	f->ymax = 2.0;
	f->width = 1000;
	f->hight = 1000;
	f->zw = (f->xmax - f->xmin) / 1000.0;
	f->zh = (f->ymax - f->ymin) / 1000.0;
}

t_fract	*ft_mlx(void)
{
	t_fract	*f;

	f = malloc(sizeof(t_fract));
	if (!f)
	{
		free (f);
		return (NULL);
	}
	ft_mlx_init(f);
	f->mlx = mlx_init();
	f->window = mlx_new_window(f->mlx, f->width, f->hight, "fractol");
	f->img = mlx_new_image(f->mlx, f->width, f->hight);
	f->tab_img = (int *)mlx_get_data_addr
		(f->img, &f->bpp, &f->size_line, &f->endian);
	return (f);
}

void	ft_put_pix(t_fract *f, int x, int y, int color)
{
	if (x < f->width && x >= 0 && y < f->hight && y >= 0)
		f->tab_img[x + y * (int) f->width] = color;
}

int	main(int ac, char **av)
{
	t_fract	*f;

	f = NULL;
	if (ac > 2)
		write (1, "Too many arguments", 18);
    else if (ac == 2)
    {
        if (!ft_strncmp(av[1], "mandelbrot_5", 13))
		    ft_drawfractal_mandelbrot_5(f);
    }
	else
		write (1, "mandelbrot_5\n", 14);
	return (0);
}
