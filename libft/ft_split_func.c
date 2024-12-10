/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_func.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/13 13:47:08 by jbakker       #+#    #+#                 */
/*   Updated: 2024/07/14 14:52:03 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_substrings(char const *s, int (*is_split)(char*))
{
	int	count;
	int	index;
	int	prev;

	index = -1;
	count = 0;
	prev = 0;
	while (s[++index])
	{
		if (is_split((char *)s + index))
		{
			count += prev;
			prev = 0;
		}
		else
			prev = 1;
	}
	count += prev;
	return (count);
}

static char	*ft_substr_mask(char *str, int length, char *mask)
{
	char	*output;
	int		str_index;
	int		mask_index;

	output = ft_calloc(length + 1, sizeof(char));
	if (!output)
		return (NULL);
	str_index = -1;
	mask_index = 0;
	while (++str_index < length)
		if (!ft_strchr(mask, str[str_index]))
			output[mask_index++] = str[str_index];
	return (output);
}

char	**ft_split_func(char const *s, int (*is_split)(char*), char *hidden)
{
	char	**output;
	char	*ptr;
	int		len;
	int		str_index;
	int		split_i;

	len = count_substrings(s, is_split);
	output = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!output)
		return (NULL);
	str_index = 0;
	split_i = 0;
	while (s[str_index])
	{
		while (is_split((char *)s + str_index))
			++str_index;
		ptr = (char *)s + str_index;
		while (s[++str_index] && !is_split((char *)s + str_index))
			;
		output[split_i] = ft_substr_mask(ptr, s + str_index - ptr, hidden);
		if (!output[split_i])
			return (ft_free_split(output), NULL);
		++split_i;
	}
	return (output);
}
