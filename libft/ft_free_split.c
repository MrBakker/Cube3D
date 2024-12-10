/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_split.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/14 14:39:05 by jbakker       #+#    #+#                 */
/*   Updated: 2024/08/19 09:56:05 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **split)
{
	int	index;

	index = 0;
	if (!split)
		return ;
	while (split[index])
	{
		free(split[index]);
		index++;
	}
	free(split);
}
