/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:34:18 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/18 17:13:59 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/fractol.h"
#include <math.h>
#include <stdio.h>

void	ft_mandel(int x, int y, t_generic *gen)
{
	t_ima	num;

	num.x = ((sqrt(gen->value.xgmax * gen->value.xgmax)
				+ sqrt(gen->value.ygmin * gen->value.ygmin))
			/ gen->value.xwin) * x;
	num.y = ((sqrt(gen->value.ygmax * gen->value.ygmax)
				+ sqrt(gen->value.ygmin * gen->value.ygmin))
			/ gen->value.ywin) * y;
	num.y = ((gen->value.ygmax - gen->value.ygmin) / 2)
		- num.y + gen->value.desy;
	num.x = num.x - ((gen->value.xgmax - gen->value.xgmin)
			/ 2) + gen->value.desx;
	if (gen->value.mandel)
		ft_printmandel(&num, x, y, gen);
	else if (gen->value.julia)
		ft_printjulia(&num, x, y, gen);
	else if (gen->value.new)
		ft_printnew(&num, x, y, gen);
}	

void	ft_win(t_generic *gen)
{
	int	x;
	int	y;

	x = 0;
	while (x < gen->value.xwin)
	{
		y = 0;
		while (y < gen->value.ywin)
		{
			ft_mandel(x, y, gen);
			y++;
		}
		x++;
	}
}

void	ft_printoptions(void)
{
	printf("1 = Mandelbroot\n2 = Julia\n3 = Extra\n");
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (ft_strlen(argv[1]) == 1 && argv[1][0] == '1')
			ft_mandelbroot();
		else if (ft_strlen(argv[1]) == 1 && argv[1][0] == '2')
			ft_julia(argv);
		else if (ft_strlen(argv[1]) == 1 && argv[1][0] == '3')
			ft_newfractal();
		else
			ft_printoptions();
	}
	else
		ft_printoptions();
}
