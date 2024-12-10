/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printhex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 15:16:57 by jbakker       #+#    #+#                 */
/*   Updated: 2024/04/26 13:46:38 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put_hex(unsigned int numb, int hex, int print)
{
	char	c;
	int		out;

	out = 1;
	if (numb > 15)
		out += ft_put_hex(numb / 16, hex, print);
	if (print)
	{
		c = num_to_hex(numb % 16, hex);
		ft_write(0, &c, 1);
	}
	return (out);
}

static void	get_flag_data(int num, int *extra_0, int *extra_s, t_flags *flag)
{
	int	l;

	*extra_0 = 0;
	*extra_s = 0;
	l = ft_put_hex((unsigned int)num, 'a', 0);
	if (flag->dot == 0 && num == 0)
		l = 0;
	if (flag->dot > l)
		*extra_0 = flag->dot - l;
	if (flag->dot == -1 && !flag->dash && flag->zero && flag->width > l)
		*extra_0 = flag->width - l;
	if (flag->width > l + *extra_0 + (flag->hashtag && num != 0) * 2)
		*extra_s = flag->width - l - *extra_0 - (flag->hashtag && num != 0) * 2;
}

int	ft_printhex(int num, int hex, t_flags *flags)
{
	int	output;
	int	extra_0;
	int	extra_space;

	get_flag_data(num, &extra_0, &extra_space, flags);
	output = extra_0 + extra_space;
	if (!flags->dash && extra_space > 0)
		while (extra_space--)
			ft_write(0, " ", 1);
	if (flags->hashtag && hex == 'a' && num != 0)
		ft_write(0, "0x", 2);
	else if (flags->hashtag && hex == 'A' && num != 0)
		ft_write(0, "0X", 2);
	while (extra_0-- > 0)
		ft_write(0, "0", 1);
	if (!(flags->dot == 0 && num == 0))
		ft_put_hex((unsigned int)num, hex, 1);
	while (extra_space-- > 0)
		ft_write(0, " ", 1);
	return (output);
}
