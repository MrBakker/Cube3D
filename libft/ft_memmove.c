/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 19:45:51 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/09 12:04:55 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;

	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	if (!dest && !src)
		return (dest);
	if (dest_ptr < src_ptr)
		ft_memcpy(dest_ptr, src_ptr, n);
	else
		while (n--)
			dest_ptr[n] = src_ptr[n];
	return (dest);
}
