/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_split.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/17 16:06:42 by jbakker       #+#    #+#                 */
/*   Updated: 2024/08/05 11:25:48 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_split(char **split, char *name)
{
	char	*real_name;
	int		index;

	real_name = name;
	index = -1;
	if (!name)
		real_name = "split";
	if (!split)
		ft_printf("%s is NULL\n", real_name);
	else
		while (split[++index])
			ft_printf("%s[%d]: %s\n", real_name, index, split[index]);
}
