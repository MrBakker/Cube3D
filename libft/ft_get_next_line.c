/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_next_line.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 18:59:23 by jbakker       #+#    #+#                 */
/*   Updated: 2024/05/19 21:00:43 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	update_buffer(char **buff_ptr, int fd, int reset)
{
	static int	reading_done = 0;
	char		*temp_buff;
	int			chars_read;
	int			current_buff_len;

	if (reading_done && reset)
		reading_done = 0;
	while (!ft_strchr(*buff_ptr, '\n') && !reading_done && !reset)
	{
		current_buff_len = ft_strlen(*buff_ptr);
		temp_buff = (char *)malloc((current_buff_len + BUFFER_SIZE + 1));
		if (!temp_buff)
			return ;
		chars_read = read(fd, temp_buff + current_buff_len, BUFFER_SIZE);
		temp_buff[current_buff_len + ft_max(chars_read, 0)] = '\0';
		if (chars_read <= 0)
		{
			free(temp_buff);
			reading_done = 1;
			return ;
		}
		ft_memcpy(temp_buff, *buff_ptr, current_buff_len);
		free(*buff_ptr);
		*buff_ptr = temp_buff;
	}
}

static char	*fetch_next_line(char **buff)
{
	char	*line;
	int		split;
	int		split_idx;

	if (!*buff || !*buff[0])
		return (NULL);
	split = ft_strchr(*buff, '\n') - *buff;
	split_idx = (split < 0) * (ft_strlen(*buff) - 1) + (split >= 0) * split;
	line = (char *)malloc((split_idx + 2) * sizeof(char));
	if (!line)
	{
		free(*buff);
		*buff = NULL;
		return (NULL);
	}
	line[split_idx + 1] = '\0';
	ft_memmove(line, *buff, split_idx + 1);
	if (split >= 0)
		ft_memmove(*buff, *buff + split_idx + 1, ft_strlen(*buff) - split_idx);
	else
		*buff[0] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*line;

	if (fd < 0 || fd > 8192 || BUFFER_SIZE <= 0)
		return (NULL);
	update_buffer(&buff, fd, 0);
	line = fetch_next_line(&buff);
	if (!line || !line[0])
	{
		if (buff)
		{
			free(buff);
			buff = NULL;
		}
		update_buffer(&buff, fd, 1);
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}
