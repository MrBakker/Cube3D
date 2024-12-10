/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strreplace.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/17 19:46:12 by jbakker       #+#    #+#                 */
/*   Updated: 2024/06/19 12:36:25 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sstrcnt(char *str, char *substr)
{
	int	count;
	int	index;
	int	sub_index;

	count = 0;
	index = 0;
	while (str[index])
	{
		sub_index = 0;
		while (str[index + sub_index] == substr[sub_index] && \
			substr[sub_index] && str[index + sub_index])
			sub_index++;
		if (!substr[sub_index])
		{
			count++;
			index += sub_index;
		}
		else
			index++;
	}
	return (count);
}

char	*ft_strreplace(char *str, char *old, char *new)
{
	char	*output;
	int		new_index;
	int		old_index;
	int		ol;
	int		nl;

	old_index = 0;
	new_index = 0;
	ol = ft_strlen(old);
	nl = ft_strlen(new);
	output = ft_calloc((ft_strlen(str) + (nl - ol) * sstrcnt(str, old) + 1), 1);
	if (ol == 0 || !str || !output)
		return (free(output), NULL);
	while (str[old_index])
	{
		if (!ft_strncmp(str + old_index, old, ol))
		{
			ft_strlcpy(output + new_index, new, nl + 1);
			new_index += nl;
			old_index += ol;
		}
		else
			output[new_index++] = str[old_index++];
	}
	return (output);
}
