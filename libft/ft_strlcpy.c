/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 18:30:45 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/06 16:13:23 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	while (index + 1 < size && src[index])
	{
		dest[index] = src[index];
		++index;
	}
	if (size > 0)
		dest[index] = '\0';
	while (src[index])
		++index;
	return (index);
}
