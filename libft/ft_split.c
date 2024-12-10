/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 15:37:17 by jbakker       #+#    #+#                 */
/*   Updated: 2024/07/17 17:39:21 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_zero(int *i1, int *i2)
{
	*i1 = 0;
	*i2 = 0;
}

static char	**ft_free(char **output, int index)
{
	while (--index >= 0)
		free(output[index]);
	free (output);
	return (NULL);
}

static int	count_substrings(char const *s, char c)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c)
			++index;
		if (s[index])
			++count;
		while (s[index] && s[index] != c)
			++index;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	int		out_index;
	int		string_index;
	int		start;
	int		out_len;

	out_len = count_substrings(s, c);
	set_zero(&out_index, &string_index);
	output = (char **)ft_calloc(out_len + 1, sizeof(char *));
	if (!output)
		return (NULL);
	while (out_index < out_len)
	{
		while (s[string_index] == c)
			++string_index;
		start = string_index;
		while (s[string_index] && s[string_index] != c)
			++string_index;
		output[out_index++] = malloc((string_index - start + 1) * sizeof(char));
		if (!output[out_index - 1])
			return (ft_free(output, out_index));
		ft_memcpy(output[out_index - 1], s + start, string_index - start + 1);
		output[out_index - 1][string_index - start] = '\0';
	}
	return (output);
}
