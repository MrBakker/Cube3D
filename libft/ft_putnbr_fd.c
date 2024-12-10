/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 16:57:24 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/06 17:19:48 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	place(int n, int fd)
{
	char	out;

	if (n > -10)
		out = '0' - n;
	else
	{
		place(n / 10, fd);
		out = '0' - n % 10;
	}
	write(fd, &out, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		n *= -1;
	else
		write(fd, "-", 1);
	place(n, fd);
}
