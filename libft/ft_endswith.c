/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_endswith.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/17 15:25:44 by jbakker       #+#    #+#                 */
/*   Updated: 2024/05/17 15:26:57 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_endswith(char *str, char *end)
{
	int	first_len;
	int	second_len;

	first_len = ft_strlen(str);
	second_len = ft_strlen(end);
	if (second_len > first_len)
		return (0);
	return (ft_strncmp(str + first_len - second_len, end, second_len) == 0);
}
