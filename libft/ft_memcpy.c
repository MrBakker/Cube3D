/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 18:17:48 by jbakker       #+#    #+#                 */
/*   Updated: 2024/04/26 13:51:14 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;
	size_t	index;

	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	if (!dest || !src)
		return (dest);
	index = 0;
	while (index < n)
	{
		dest_ptr[index] = src_ptr[index];
		++index;
	}
	return (dest);
}
