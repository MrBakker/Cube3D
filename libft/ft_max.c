/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_max.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/18 17:54:43 by jbakker       #+#    #+#                 */
/*   Updated: 2024/05/19 10:06:23 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int a, int b)
{
	return ((a > b) * a + (b >= a) * b);
}

int	ft_max_item(int *list, int size)
{
	int	max;

	max = list[0];
	while (--size > 0)
		max = ft_max(max, list[size]);
	return (max);
}

int	ft_max_index(int *list, int size)
{
	int	max;
	int	index;

	max = list[0];
	index = 0;
	while (--size > 0)
	{
		if (list[size] > max)
		{
			max = list[size];
			index = size;
		}
	}
	return (index);
}
