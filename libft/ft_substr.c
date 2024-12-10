/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 15:01:17 by jbakker       #+#    #+#                 */
/*   Updated: 2023/11/08 14:23:04 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*output;
	size_t			effective_len;
	unsigned int	index;

	index = 0;
	effective_len = len;
	if (start + len > ft_strlen(s))
		effective_len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		effective_len = 0;
	output = (char *)malloc((effective_len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	while (s[start + index] && index < effective_len)
	{
		output[index] = s[start + index];
		++index;
	}
	output[index] = '\0';
	return (output);
}
