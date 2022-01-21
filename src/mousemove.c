/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:21:16 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/14 19:23:21 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/fractol.h"
#include <math.h>
#include <stdlib.h>

void	ft_putcoord(t_generic *gen, int x, int y)
{
	t_ima	num;
	char	*let;

	num.x = ((sqrt(gen->value.xgmax * gen->value.xgmax)
				+ sqrt(gen->value.ygmin * gen->value.ygmin))
			/ gen->value.xwin) * x;
	num.y = ((sqrt(gen->value.ygmax * gen->value.ygmax)
				+ sqrt(gen->value.ygmin * gen->value.ygmin))
			/ gen->value.ywin) * y;
	num.y = ((gen->value.ygmax - gen->value.ygmin)
			/ 2) - num.y + gen->value.desy;
	num.x = num.x - ((gen->value.xgmax - gen->value.xgmin)
			/ 2) + gen->value.desx;
	mlx_string_put(gen->mlx, gen->mlx_win, x + 20, y + 30, 0x000000, "X ");
	let = ft_double_to_char(num.x);
	mlx_string_put(gen->mlx, gen->mlx_win, x + 35, y + 30,
		0x000000, let);
	free(let);
	mlx_string_put(gen->mlx, gen->mlx_win, x + 20, y + 50, 0x000000, "Y ");
	let = ft_double_to_char(num.y);
	mlx_string_put(gen->mlx, gen->mlx_win, x + 35, y + 50,
		0x000000, let);
	free(let);
}

int	mouse_win1(int x, int y, t_generic *gen)
{
	mlx_clear_window(gen->mlx, gen->mlx_win);
	ft_win(gen);
	mlx_put_image_to_window(gen->mlx, gen->mlx_win, gen->img.img, 0, 0);
	gen->window.addr = "minilibx/image.xpm";
	if (x < gen->value.xwin && y < gen->value.ywin && x > 0 && y > 0)
	{
		gen->window.img = mlx_xpm_file_to_image(gen->mlx,
				gen->window.addr, &gen->window.width, &gen->window.high);
		mlx_put_image_to_window(gen->mlx, gen->mlx_win, gen->window.img, x, y);
		ft_putcoord(gen, x, y);
	}
	return (0);
}

char	*ft_smallnum(double a, char *dest, int cast, int pas)
{
	int	len;

	if (a < 0)
	{
		a *= -1;
		pas = 1;
	}
	len = 8 + pas;
	dest = malloc((len + 1) * sizeof(char));
	if (pas)
		dest[0] = '-';
	cast = (int) a;
	dest[0 + pas] = cast + 48;
	dest[len] = 0;
	a -= cast;
	a *= 1000000;
	while (len-- > 1 + pas)
	{
		cast = (int) a % 10;
		dest[len] = cast + 48;
		a /= 10;
	}
	dest[1 + pas] = '.';
	dest[5 + pas] = 0;
	return (dest);
}

char	*ft_bignum(double a, char *dest, int cast, int pas)
{
	int	len;

	if (a < 0)
	{
		a *= -1;
		pas = 1;
	}
	len = 9 + pas;
	dest = malloc((len + 1) * sizeof(char));
	if (pas)
		dest[0] = '-';
	cast = (int) a;
	dest[1 + pas] = (cast % 10) + 48;
	dest[0 + pas] = (cast / 10) + 48;
	dest[len] = 0;
	a = (a - cast) * 1000000;
	while (len-- > 2 + pas)
	{
		cast = (int) a % 10;
		dest[len] = cast + 48;
		a /= 10;
	}
	dest[2 + pas] = '.';
	dest[6 + pas] = 0;
	return (dest);
}

char	*ft_double_to_char(double a)
{
	char	*dest;
	int		cast;
	int		pas;

	cast = 0;
	dest = NULL;
	pas = 0;
	if ((a < 10 && a >= 0) || (a > -10 && a < 0))
		dest = ft_smallnum(a, dest, cast, pas);
	if (a >= 10 || a <= -10)
		dest = ft_bignum(a, dest, cast, pas);
	if (!dest)
		dest = NULL;
	return (dest);
}
