/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:21:16 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/14 19:19:38 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/fractol.h"
#include <stdlib.h>

void	ft_keyhook2(int keycode, t_generic *gen)
{
	if (keycode == 126)
	{
		gen->value.desy += gen->value.deg;
		ft_win(gen);
		mlx_put_image_to_window(gen->mlx, gen->mlx_win, gen->img.img, 0, 0);
	}
	if (keycode == 124)
	{
		gen->value.desx += gen->value.deg;
		ft_win(gen);
		mlx_put_image_to_window(gen->mlx, gen->mlx_win, gen->img.img, 0, 0);
	}
	if (keycode == 125)
	{
		gen->value.desy -= gen->value.deg;
		ft_win(gen);
		mlx_put_image_to_window(gen->mlx, gen->mlx_win, gen->img.img, 0, 0);
	}
}

int	key_hook(int keycode, t_generic *gen)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 8)
	{
		gen->value.color += 1000;
		ft_win(gen);
		mlx_put_image_to_window(gen->mlx, gen->mlx_win, gen->img.img, 0, 0);
	}
	if (keycode == 9)
	{
		gen->value.color -= 1000;
		ft_win(gen);
		mlx_put_image_to_window(gen->mlx, gen->mlx_win, gen->img.img, 0, 0);
	}
	if (keycode == 123)
	{
		gen->value.desx -= gen->value.deg;
		ft_win(gen);
		mlx_put_image_to_window(gen->mlx, gen->mlx_win, gen->img.img, 0, 0);
	}
	ft_keyhook2(keycode, gen);
	return (1);
}
