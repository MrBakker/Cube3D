/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:22:52 by jbakker       #+#    #+#                 */
/*   Updated: 2023/11/08 13:56:02 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*output;
	size_t		bug_numb;

	bug_numb = nmemb * size;
	output = (void *)malloc(bug_numb);
	if (!output)
		return (NULL);
	ft_bzero(output, bug_numb);
	return (output);
}
