/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 15:46:16 by jbakker       #+#    #+#                 */
/*   Updated: 2024/06/26 14:01:14 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_length(int n)
{
	int	length;

	length = 1;
	if (n > 0)
	{
		n *= -1;
		length--;
	}
	while (n < 0)
	{
		n /= 10;
		++length;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*output;
	int		count;

	count = get_int_length(n) + 1;
	output = (char *)malloc(count * sizeof(char));
	if (!output)
		return (0);
	output[--count] = '\0';
	output[0] = '0';
	if (n < 0)
		output[0] = '-';
	else
		n *= -1;
	while (--count >= 0)
	{
		if (count != 0 || output[0] != '-')
			output[count] = '0' - n % 10;
		n /= 10;
	}
	return (output);
}
