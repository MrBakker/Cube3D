/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:36:06 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/04 12:38:28 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		length;

	length = 0;
	current = (t_list *)lst;
	while (current)
	{
		current = current->next;
		++length;
	}
	return (length);
}
