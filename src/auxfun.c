/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:25:58 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/14 18:55:56 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/fractol.h"
#include <math.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_ima	function(t_ima num)
{
	t_ima	a;

	a.x = (num.x * num.x * num.x) + (3 * num.x * (-1 * num.y * num.y)) - 1;
	a.y = (3 * (num.x * num.x) * num.y) + (-1 * num.y * num.y * num.y);
	return (a);
}

t_ima	derivative(t_ima num)
{
	t_ima	a;

	a.x = 3 * ((num.x * num.x) - (num.y * num.y));
	a.y = 6 * (sqrt((num.x * num.y) * (num.x * num.y)));
	return (a);
}

t_ima	cdiv(t_ima a, t_ima b)
{
	t_ima	c;

	c.x = (((a.x * b.x) - (a.y * b.y))) / ((b.x * b.x) + (b.y * b.y));
	c.y = (((a.x * b.y) + (a.y * b.x))) / ((b.x * b.x) + (b.y * b.y));
	return (c);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
