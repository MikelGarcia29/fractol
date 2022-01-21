/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:07:03 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/14 18:54:26 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/fractol.h"
#include <math.h>

void	ft_julia(char **argv)
{
	t_generic	gen;

	if (check_digit(argv[2]) || check_digit(argv[3]))
		wrongdigit();
	ft_genstartjulia(&gen);
	gen.value.xjulia = ft_atoi_double(argv[2]);
	gen.value.yjulia = ft_atoi_double(argv[3]);
	gen.mlx = mlx_init();
	gen.mlx_win = mlx_new_window(gen.mlx, gen.value.xwin,
			gen.value.ywin, "Julia!");
	gen.img.img = mlx_new_image(gen.mlx, gen.value.xwin, gen.value.ywin);
	gen.img.addr = mlx_get_data_addr(gen.img.img,
			&gen.img.bits_per_pixel, &gen.img.line_length, &gen.img.endian);
	ft_win(&gen);
	mlx_put_image_to_window(gen.mlx, gen.mlx_win, gen.img.img, 0, 0);
	mlx_hook(gen.mlx_win, 2, 1L << 0, key_hook, &gen);
	mlx_hook(gen.mlx_win, 4, 1L << 2, mouse_win, &gen);
	mlx_hook(gen.mlx_win, 6, 1L << 6, mouse_win1, &gen);
	mlx_loop(gen.mlx);
}

void	ft_genstartjulia(t_generic *gen)
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
	gen->value.julia = 1;
	gen->value.xmap = 0.0;
	gen->value.ymap = 0.0;
}

void	ft_printjulia(t_ima *num, int x, int y, t_generic *gen)
{
	int		cont;
	t_ima	a;
	t_ima	b;
	double	mu;

	a.x = num->x;
	gen->value.xmap = num->x;
	gen->value.ymap = num->y;
	b.x = num->y;
	cont = 0;
	while (cont++ < 100)
	{
		a.y = ((a.x * a.x) - (b.x * b.x));
		b.y = (2 * a.x * b.x);
		a.x = gen->value.xjulia + a.y;
		b.x = gen->value.yjulia + b.y;
		if (sqrt((a.x * a.x) + (b.x * b.x)) > 25)
		{
			mu = cont + 100 - (log(log(sqrt((a.x * a.x))
							+ sqrt((b.x * b.x)))) / log(2));
			my_mlx_pixel_put(&gen->img, x, y, (mu) * gen->value.color);
			return ;
		}
	}
	my_mlx_pixel_put(&gen->img, x, y, 0xFFFF00);
}
