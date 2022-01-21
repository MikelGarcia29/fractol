/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:56:58 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/13 19:29:44 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		width;
	int		high;
}	t_image;

typedef struct s_info {
	int		xwin;
	int		ywin;
	double	xgmax;
	double	ygmax;
	double	xgmin;
	double	ygmin;
	int		color;
	double	desy;
	double	desx;
	double	deg;
	int		mandel;
	int		julia;
	int		new;
	int		newton;
	double	xjulia;
	double	yjulia;
	double	xmap;
	double	ymap;
}	t_info;

typedef struct s_generic {
	t_info	value;
	t_data	img;
	t_image	window;
	void	*mlx;
	void	*mlx_win;
}	t_generic;

typedef struct s_imaginario {
	double	x;
	double	y;
}	t_ima;

//Mandel fractal
void	ft_printmandel(t_ima *num, int x, int y, t_generic *gen);
void	ft_genstartmandel(t_generic *gen);
void	ft_mandelbroot(void);
//Julia fractal
void	ft_printjulia(t_ima *num, int x, int y, t_generic *gen);
void	ft_genstartjulia(t_generic *gen);
void	ft_julia(char **argv);
//Boat fractal
void	ft_printnew(t_ima *num, int x, int y, t_generic *gen);
void	ft_genstartnew(t_generic *gen);
void	ft_newfractal(void);
//Key hook
int		key_hook(int keycode, t_generic *gen);
void	ft_keyhook2(int keycode, t_generic *gen);
//Mouse win
int		mouse_win(int button, int x, int y, t_generic *gen);
void	ft_button5(int x, int y, t_generic *gen);
void	ft_button4(int x, int y, t_generic *gen);
void	ft_button1(int x, int y, t_generic *gen);
//Mouse move
void	ft_putcoord(t_generic *gen, int x, int y);
int		mouse_win1(int x, int y, t_generic *gen);
char	*ft_double_to_char(double a);
char	*ft_bignum(double a, char *dest, int cast, int pas);
char	*ft_smallnum(double a, char *dest, int cast, int pas);
//Aux functions
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_ima	function(t_ima num);
t_ima	derivative(t_ima num);
t_ima	cdiv(t_ima a, t_ima b);
int		ft_strlen(char *s);
//Common functions
void	ft_mandel(int x, int y, t_generic *gen);
void	ft_win(t_generic *gen);
void	ft_printoptions(void);
//From char to doble
int		ft_isdigit_double(int c);
int		check_neg(int *neg, char c);
double	ft_atoi_double(const char *str);
char	check_digit(char *str);
void	wrongdigit(void);

#endif
