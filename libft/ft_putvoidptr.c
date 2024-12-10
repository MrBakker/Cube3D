/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putvoidptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:43:41 by jbakker       #+#    #+#                 */
/*   Updated: 2024/04/26 13:46:52 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put_ulong(unsigned long numb, int print)
{
	char	c;
	int		out;

	out = 1;
	if (numb > 15)
		out += ft_put_ulong(numb / 16, print);
	if (print)
	{
		c = num_to_hex(numb % 16, 'a');
		ft_write(0, &c, 1);
	}
	return (out);
}

int	ft_putvoidptr(void *ptr, t_flags *flags)
{
	int	length;
	int	extra;

	if (ptr)
		length = ft_put_ulong((unsigned long)ptr, 0) + 2;
	else
		length = 5;
	extra = flags->width - length;
	if (extra > 0 && !flags->dash)
		while (extra--)
			ft_write(0, " ", 1);
	if (ptr)
	{
		ft_write(0, "0x", 2);
		ft_put_ulong((unsigned long)ptr, 1);
	}
	else
		ft_write(0, "(nil)", 5);
	if (extra > 0 && flags->dash)
		while (extra--)
			ft_write(0, " ", 1);
	return (ft_max(flags->width, length));
}
