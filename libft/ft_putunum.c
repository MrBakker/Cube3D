/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 14:35:59 by jbakker       #+#    #+#                 */
/*   Updated: 2024/04/26 13:46:49 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_uint(unsigned int numb, int print)
{
	char	c;
	int		out;

	out = 1;
	if (numb < 10)
		c = numb + '0';
	else
	{
		out += ft_put_uint(numb / 10, print);
		c = numb % 10 + '0';
	}
	if (print)
		ft_write(0, &c, 1);
	return (out);
}

static void	get_flag_data(int num, int *extra_0, int *extra_s, t_flags *flag)
{
	int	length;

	*extra_0 = 0;
	*extra_s = 0;
	length = ft_put_uint(num, 0);
	if (flag->dot == 0 && num == 0)
		length = 0;
	if (flag->dot > length)
		*extra_0 = flag->dot - length;
	if (flag->dot == -1 && !flag->dash && flag->zero && flag->width > length)
		*extra_0 = flag->width - length;
	if (flag->width > length + *extra_0)
		*extra_s = flag->width - length - *extra_0;
}

int	ft_putunum(int num, t_flags *flags)
{
	int	output;
	int	extra_0;
	int	extra_space;

	get_flag_data(num, &extra_0, &extra_space, flags);
	output = extra_0 + extra_space;
	if (!flags->dash && extra_space > 0)
		while (extra_space--)
			ft_write(0, " ", 1);
	while (extra_0-- > 0)
		ft_write(0, "0", 1);
	if (!(flags->dot == 0 && num == 0))
		output += ft_put_uint(num, 1);
	while (extra_space-- > 0)
		ft_write(0, " ", 1);
	return (output);
}
