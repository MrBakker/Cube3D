/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgoedhar <jgoedhar@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 15:13:27 by jbakker       #+#    #+#                 */
/*   Updated: 2024/08/19 00:31:17 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	int		str_index;
	int		out_index;

	str_index = 0;
	out_index = 0;
	output = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!output)
		return (NULL);
	while (s1 && s1[str_index])
		output[out_index++] = s1[str_index++];
	str_index = 0;
	while (s2 && s2[str_index])
		output[out_index++] = s2[str_index++];
	output[out_index] = '\0';
	return (output);
}

char	*ft_multijoin(char **strs, char const *sep)
{
	char	*output;
	int		substring_count;
	int		length;
	int		index;

	length = 0;
	substring_count = 0;
	while (strs[substring_count])
		length += ft_strlen(strs[substring_count++]);
	length += (substring_count - 1) * ft_strlen(sep);
	output = ft_calloc(length + 1, sizeof(char));
	if (!output)
		return (NULL);
	length = -1;
	index = 0;
	while (strs[++length])
	{
		ft_memcpy(output + index, strs[length], ft_strlen(strs[length]));
		index += ft_strlen(strs[length]);
		if (strs[length + 1])
			ft_memcpy(output + index, sep, ft_strlen(sep));
		if (strs[length + 1])
			index += ft_strlen(sep);
	}
	return (output);
}

char	*ft_strjoin_duo(char const *s1, char const *sep, char const *s2)
{
	char	*strs[3];

	strs[0] = (char *)s1;
	strs[1] = (char *)s2;
	strs[2] = NULL;
	return (ft_multijoin(strs, sep));
}
