/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:08:11 by jbakker       #+#    #+#                 */
/*   Updated: 2024/05/19 20:58:48 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	if (!s)
		return (0);
	index = 0;
	c = (unsigned char)c;
	while (s[index] && s[index] != c)
		++index;
	if (s[index] == c)
		return (((char *)s) + index);
	return (0);
}
