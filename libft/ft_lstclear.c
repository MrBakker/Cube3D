/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 13:43:55 by jbakker       #+#    #+#                 */
/*   Updated: 2024/07/23 17:17:30 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	ptr = *lst;
	if (lst && *lst && del)
	{
		while (ptr)
		{
			*lst = NULL;
			*lst = ptr->next;
			ft_lstdelone(ptr, del);
			ptr = *lst;
		}
	}
}
