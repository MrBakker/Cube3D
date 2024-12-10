/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:18:06 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/09 12:28:16 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	depth;

	index = 0;
	depth = 0;
	if (!little[0])
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[index] && index < len)
	{
		while (big[index + depth] == little[depth] && little[depth])
			depth++;
		if (!little[depth] && depth + index <= len)
			return ((char *)big + index);
		depth = 0;
		index++;
	}
	if (!index && !big[0] && !little[0])
		return ((char *)big);
	return (NULL);
}
