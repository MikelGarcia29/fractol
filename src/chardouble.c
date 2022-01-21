/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chardouble.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:13:15 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/14 18:55:11 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/fractol.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_isdigit_double(int c)
{
	if (c == '-')
		return (1);
	if ((c < 48 || c > 57) && c != '.')
		return (0);
	return (1);
}

int	check_neg(int *neg, char c)
{
	if (c == '-')
	{
		*neg = -1;
		return (1);
	}
	return (0);
}

double	ft_atoi_double(const char *str)
{
	double	out;
	int		neg_decimal[2];

	neg_decimal[0] = 0;
	neg_decimal[1] = 1;
	out = 0.0;
	if (check_neg(&neg_decimal[1], *str))
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			str++;
			neg_decimal[0] = 10;
		}
		if (!neg_decimal[0] && ft_isdigit_double(*str))
			out = out * 10 + (*str - '0');
		else if (neg_decimal[0] && ft_isdigit_double(*str))
		{
			out = out + ((double)(*str - '0') / neg_decimal[0]);
			neg_decimal[0] *= 10;
		}
		str++;
	}
	return (out * neg_decimal[1]);
}

char	check_digit(char *str)
{
	int		neg_decimal[2];
	double	n;

	if (!str)
		return (1);
	neg_decimal[0] = 0;
	neg_decimal[1] = 0;
	n = ft_atoi_double(str);
	if (n > 2.0 || n < -2.0)
		wrongdigit();
	while (*str)
	{
		if (!ft_isdigit_double(*str))
			return (1);
		if (*str == '.')
			neg_decimal[0]++;
		if (*str == '-')
			neg_decimal[1]++;
		if (neg_decimal[0] > 1 || neg_decimal[1] > 1)
			return (1);
		if (*str == '.' && *(str + 1) == 0)
			return (1);
		str++;
	}
	return (0);
}

void	wrongdigit(void)
{
	printf("Has escerito mal los digitos de Julia\n");
	ft_printoptions();
	exit (0);
}
