/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set_split.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/24 13:34:43 by jbakker       #+#    #+#                 */
/*   Updated: 2024/06/24 14:15:35 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_split(char c, const char *set)
{
	int	index;

	index = 0;
	while (set[index])
		if (c == set[index++])
			return (1);
	return (0);
}

static int	count_splits(char const *s, char const *set)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (s[index] && is_split(s[index], set))
		++index;
	while (s[index])
	{
		if (s[index])
			++count;
		while (s[index] && !is_split(s[index], set))
			++index;
	}
	return (count);
}

char	**ft_set_split(char const *s, char const *set)
{
	char	**output;
	int		out_index;
	int		string_index;
	int		split_len;
	int		end;

	split_len = count_splits(s, set);
	output = (char **)malloc((split_len + 1) * sizeof(char *));
	if (!output)
		return (NULL);
	out_index = split_len - 1;
	string_index = ft_strlen(s) - 1;
	while (out_index >= 0)
	{
		while (string_index >= 0 && is_split(s[string_index], set))
			--string_index;
		end = string_index;
		while (string_index >= 0 && !is_split(s[string_index], set))
			--string_index;
		output[out_index] = ft_substr(s, string_index + 1, end - string_index);
		if (!output[out_index])
			return (ft_free(output, split_len));
	}
}
