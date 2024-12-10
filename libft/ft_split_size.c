/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_size.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/14 15:49:37 by jbakker       #+#    #+#                 */
/*   Updated: 2024/07/14 16:33:00 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_split_size(char **array)
{
	int	i;

	i = 0;
	while (array && *array && array[i])
		i++;
	return (i);
}
