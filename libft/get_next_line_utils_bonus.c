/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 12:35:39 by jbakker       #+#    #+#                 */
/*   Updated: 2024/04/26 13:50:08 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_new_line(const char *buff, int include_0)
{
	int	index;

	index = 0;
	if (!buff)
		return (-1);
	while (buff[index] && buff[index] != '\n')
		++index;
	if (buff[index] == '\n' || include_0)
		return (index);
	return (-1);
}

void	c_memcpy(const char *dest, const char *src, size_t len)
{
	size_t	index;
	char	*ptr;

	index = 0;
	if (len == 0 || !dest || !src)
		return ;
	ptr = (char *)dest;
	while (index + 1 < len)
	{
		ptr[index] = src[index];
		++index;
	}
	ptr[index] = '\0';
}
