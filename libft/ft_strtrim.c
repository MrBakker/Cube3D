/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 15:20:58 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/06 17:18:39 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	index;

	index = 0;
	while (set[index])
		if (c == set[index++])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*output;
	int		start_index;
	int		end_index;
	int		out_index;

	out_index = 0;
	start_index = 0;
	end_index = ft_strlen(s1) - 1;
	while (s1[start_index] && is_in_set(s1[start_index], set))
		++start_index;
	while (is_in_set(s1[end_index], set) && end_index > start_index)
		--end_index;
	output = (char *)malloc((end_index - start_index + 2) * sizeof(char));
	if (!output)
		return (NULL);
	while (start_index <= end_index)
		output[out_index++] = s1[start_index++];
	output[out_index] = '\0';
	return (output);
}
