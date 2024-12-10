/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:02:13 by jbakker       #+#    #+#                 */
/*   Updated: 2024/08/19 12:54:38 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*trim;
	int		output;
	int		factor;

	output = 0;
	factor = 1;
	trim = (char *)nptr;
	while ((*trim >= 9 && *trim <= 13) || *trim == ' ')
		trim++;
	if (*trim == '-' && ft_isdigit(*(trim + 1)))
	{
		++trim;
		factor = -1;
	}
	if (*trim == '+')
		++trim;
	while (*trim && ft_isdigit(*trim))
	{
		output = output * 10 + (*trim - '0') * factor;
		++trim;
	}
	return (output);
}

static int	translate_base(char c)
{
	static const char	*base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	char				*result;

	result = ft_strchr(base_str, ft_tolower(c));
	if (!result)
		return (INT_MAX);
	return (result - base_str);
}

int	ft_atoi_base(const char *nptr, int base)
{
	int	index;
	int	output;
	int	factor;

	index = 0;
	output = 0;
	factor = 1;
	while ((nptr[index] >= 9 && nptr[index] <= 13) || nptr[index] == ' ')
		index++;
	if (nptr[index] == '-' && ft_isdigit(nptr[index + 1]))
	{
		++index;
		factor = -1;
	}
	if (nptr[index] == '+')
		++index;
	if (ft_strncmp(nptr + index, "0x", 2) == 0)
	{
		index += 2;
		base = 16;
	}
	while (nptr[index] && base > translate_base(nptr[index]))
		output = output * base + translate_base(nptr[index++]) * factor;
	return (output);
}

int	ft_safe_atoi(const char *nptr, int *output)
{
	int	index;

	index = 0;
	if ((nptr[index] == '-' || nptr[index] == '+') && \
		ft_isdigit(nptr[index + 1]))
		++index;
	while (ft_isdigit(nptr[index]))
		++index;
	if (nptr[index] != '\0')
	{
		*output = 0;
		return (0);
	}
	*output = ft_atoi(nptr);
	return (1);
}
