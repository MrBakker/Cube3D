/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 12:18:45 by jbakker       #+#    #+#                 */
/*   Updated: 2024/07/02 14:32:38 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	grow_buff(t_buff *buff, int min_len)
{
	char	*temp_buff;
	int		new_capacity;

	new_capacity = ft_max((buff->capacity + 20) * 2, min_len);
	temp_buff = (char *)malloc((new_capacity + 1) * sizeof(char));
	if (!temp_buff)
		return (0);
	ft_memcpy(temp_buff, buff->buff, buff->index + 1);
	free(buff->buff);
	buff->buff = temp_buff;
	buff->capacity = new_capacity;
	return (new_capacity);
}

int	ft_write(int force, const char *str, int len)
{
	static t_buff	buff;
	int				return_val;

	if (buff.capacity < buff.index + len || force)
	{
		if (force || !grow_buff(&buff, buff.index + len))
		{
			force = (!!force * force + !force);
			buff.written += write(force, buff.buff, buff.index);
			buff.written += write(force, str, len);
			return_val = buff.written;
			buff.capacity = 0;
			buff.index = 0;
			free(buff.buff);
			buff.buff = NULL;
			if (force)
				ft_bzero(&buff, sizeof(t_buff));
			return (return_val);
		}
	}
	ft_memcpy(buff.buff + buff.index, str, len);
	buff.index += len;
	return (buff.written + buff.index);
}
