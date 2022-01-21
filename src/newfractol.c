/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newfractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:10:03 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/14 18:46:22 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/fractol.h"
#include <math.h>

void	ft_printnew(t_ima *num, int x, int y, t_generic *gen)
{
	int		cont;
	t_ima	a;
	t_ima	b;
	double	mu;

	a.x = num->x;
	a.y = 0.0;
	b.y = 0.0;
	b.x = num->y;
	cont = 0;
	while (cont++ < 100)
	{
		a.y = ((a.x * a.x) - (b.x * b.x));
		b.y = 2 * (sqrt((a.x * b.x) * (a.x * b.x)));
		a.x = num->x + a.y;
		b.x = num->y + b.y;
		if (sqrt((a.x * a.x) + (b.x * b.x)) > 25)
		{
			mu = cont + 100 - (log(log(sqrt((a.x * a.x))
							+ sqrt((b.x * b.x)))) / log(2));
			my_mlx_pixel_put(&gen->img, x, y, (mu) * gen->value.color);
			return ;
		}
	}
	my_mlx_pixel_put(&gen->img, x, y, 50);
}

void	ft_genstartnew(t_generic *gen)
{
	gen->value.xwin = 500;
	gen->value.ywin = 500;
	gen->value.xgmax = 2;
	gen->value.xgmin = -2;
	gen->value.ygmax = 2;
	gen->value.ygmin = -2;
	gen->value.color = 10000;
	gen->value.desy = 0;
	gen->value.desx = 0;
	gen->value.deg = 0.05;
	gen->value.mandel = 0;
	gen->value.julia = 0;
	gen->value.new = 1;
}

void	ft_newfractal(void)
{
	t_generic	gen;

	ft_genstartnew(&gen);
	gen.mlx = mlx_init();
	gen.mlx_win = mlx_new_window(gen.mlx,
			gen.value.xwin, gen.value.ywin, "Julia!");
	gen.img.img = mlx_new_image(gen.mlx, gen.value.xwin, gen.value.ywin);
	gen.img.addr = mlx_get_data_addr(gen.img.img,
			&gen.img.bits_per_pixel, &gen.img.line_length, &gen.img.endian);
	ft_win(&gen);
	mlx_put_image_to_window(gen.mlx, gen.mlx_win, gen.img.img, 0, 0);
	mlx_hook(gen.mlx_win, 2, 1L << 0, key_hook, &gen);
	mlx_hook(gen.mlx_win, 4, 1L << 2, mouse_win, &gen);
	mlx_loop(gen.mlx);
}
