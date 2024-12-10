/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:56:24 by jbakker       #+#    #+#                 */
/*   Updated: 2024/04/26 13:46:41 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c, t_flags *flags)
{
	int	extra;

	extra = flags->width - 1;
	while (extra-- > 0 && !flags->dash)
		ft_write(0, " ", 1);
	ft_write(0, &c, 1);
	while (extra-- >= 0)
		ft_write(0, " ", 1);
	return (ft_max(1, flags->width));
}
