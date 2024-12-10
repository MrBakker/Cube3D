/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:27:00 by jbakker       #+#    #+#                 */
/*   Updated: 2024/08/15 18:39:16 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*output;
	int		size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	output = (char *)malloc((size + 1) * sizeof(char));
	if (!output)
		return (0);
	output[size] = '\0';
	while (size--)
		output[size] = *(s + size);
	return (output);
}
