/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_push.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/14 15:48:37 by jbakker       #+#    #+#                 */
/*   Updated: 2024/08/19 10:00:08 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_push(char ***array, char *new)
{
	char	**new_array;
	int		i;

	new_array = ft_calloc(sizeof(char *), ft_split_size(*array) + 2);
	if (!new_array)
		return (NULL);
	i = 0;
	while (array && *array && (*array)[i])
	{
		new_array[i] = (*array)[i];
		i++;
	}
	new_array[i] = new;
	free(*array);
	*array = new_array;
	return (new_array);
}

char	**ft_split_push_split(char ***array, char **new)
{
	char	**new_array;
	int		i1;
	int		i2;

	new_array = ft_calloc(sizeof(char *), ft_split_size(*array) + \
				ft_split_size(new) + 1);
	if (!new_array)
		return (NULL);
	i1 = -1;
	while (array && *array && (*array)[++i1])
		new_array[i1] = (*array)[i1];
	i2 = 0;
	while (new && new[++i2])
		new_array[i1++] = new[i2];
	free(*array);
	*array = new_array;
	return (new_array);
}

char	**ft_split_insert(char ***array, char *new, int index)
{
	char	**new_array;
	int		i;
	int		j;

	new_array = ft_calloc(sizeof(char *), ft_split_size(*array) + 2);
	if (!new_array)
		return (NULL);
	i = -1;
	j = -1;
	while (array && *array && (*array)[++i])
	{
		if (i == index)
			new_array[j++] = new;
		new_array[j++] = (*array)[i];
	}
	if (i == index)
		new_array[j] = new;
	free(*array);
	*array = new_array;
	return (new_array);
}

char	**ft_split_insert_split(char ***array, char **new, int index)
{
	char	**new_array;
	int		array_len;
	int		new_len;

	array_len = ft_split_size(*array);
	new_len = ft_split_size(new);
	if (index < 0 || index > array_len)
		return (NULL);
	new_array = ft_calloc(sizeof(char **), array_len + new_len + 1);
	if (!new_array)
		return (NULL);
	ft_memmove(new_array, *array, sizeof(char *) * index);
	ft_memmove(new_array + index, new, sizeof(char *) * new_len);
	ft_memmove(new_array + index + new_len, *array + index, sizeof(char **) * \
		(array_len - index));
	free(*array);
	free(new);
	*array = new_array;
	return (new_array);
}

char	**ft_split_realloc(char **array, int new_size)
{
	char	**new_array;

	new_array = ft_calloc(sizeof(char *), new_size + 1);
	if (!new_array)
		return (NULL);
	ft_memcpy(new_array, array, sizeof(char *) * new_size);
	free(array);
	return (new_array);
}
