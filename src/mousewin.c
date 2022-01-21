/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:21:16 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/14 18:45:33 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/fractol.h"
#include <math.h>

void	ft_button5(int x, int y, t_generic *gen)
{
	double	b;
	double	a;

	mlx_clear_window(gen->mlx, gen->mlx_win);
	a = x - (gen->value.xwin / 2);
	a = a / (gen->value.xwin / 2);
	gen->value.desx += (a) * gen->value.deg;
	b = y - (gen->value.ywin / 2);
	b = b / (gen->value.ywin / 2);
	gen->value.desy -= (b) * gen->value.deg;
	gen->value.xgmax -= gen->value.deg;
	gen->value.xgmin += gen->value.deg;
	gen->value.ygmax -= gen->value.deg;
	gen->value.ygmin += gen->value.deg;
	ft_win(gen);
	mlx_put_image_to_window(gen->mlx, gen->mlx_win, gen->img.img, 0, 0);
}

void	ft_button4(int x, int y, t_generic *gen)
{
	double	c;
	double	d;

	mlx_clear_window(gen->mlx, gen->mlx_win);
	c = x - (gen->value.xwin / 2);
	c = c / (gen->value.xwin / 2);
	gen->value.desx += (c) * gen->value.deg;
	d = y - (gen->value.ywin / 2);
	d = d / (gen->value.ywin / 2);
	gen->value.desy -= (d) * gen->value.deg;
	gen->value.xgmax += gen->value.deg;
	gen->value.xgmin -= gen->value.deg;
	gen->value.ygmax += gen->value.deg;
	gen->value.ygmin -= gen->value.deg;
	ft_win(gen);
	mlx_put_image_to_window(gen->mlx, gen->mlx_win, gen->img.img, 0, 0);
}

void	ft_button1(int x, int y, t_generic *gen)
{
	gen->value.xjulia = ((sqrt(gen->value.xgmax * gen->value.xgmax)
				+ sqrt(gen->value.ygmin * gen->value.ygmin))
			/ gen->value.xwin) * x;
	gen->value.yjulia = ((sqrt(gen->value.ygmax * gen->value.ygmax)
				+ sqrt(gen->value.ygmin * gen->value.ygmin))
			/ gen->value.ywin) * y;
	gen->value.yjulia = ((gen->value.ygmax - gen->value.ygmin) / 2)
		- gen->value.yjulia + gen->value.desy;
	gen->value.xjulia = gen->value.xjulia
		- ((gen->value.xgmax - gen->value.xgmin) / 2) + gen->value.desx;
	ft_win(gen);
	mlx_put_image_to_window(gen->mlx, gen->mlx_win, gen->img.img, 0, 0);
}

int	mouse_win(int button, int x, int y, t_generic *gen)
{
	gen->value.deg = (gen->value.xgmax - gen->value.xgmin) * 0.025;
	if (button == 1)
		ft_button1(x, y, gen);
	if (button == 5)
		ft_button5(x, y, gen);
	if (button == 4)
		ft_button4(x, y, gen);
	return (1);
}
