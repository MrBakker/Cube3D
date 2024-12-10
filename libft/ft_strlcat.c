/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 19:28:48 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/09 12:31:58 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_index;
	size_t	src_index;

	dst_index = 0;
	src_index = 0;
	while (dst && dst[dst_index] && dst_index < size)
		dst_index++;
	while (dst_index + 1 < size && src[src_index])
		dst[dst_index++] = src[src_index++];
	if (size > 0 && src_index > 0)
		dst[dst_index] = '\0';
	while (src[src_index++])
		++dst_index;
	return (dst_index);
}
