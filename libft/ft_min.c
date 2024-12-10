/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_min.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/18 17:55:24 by jbakker       #+#    #+#                 */
/*   Updated: 2024/05/19 10:06:11 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int a, int b)
{
	return ((a < b) * a + (b <= a) * b);
}

int	ft_min_item(int *list, int size)
{
	int	min;

	min = list[0];
	while (--size > 0)
		min = ft_min(min, list[size]);
	return (min);
}

int	ft_min_index(int *list, int size)
{
	int	min;
	int	index;

	min = list[0];
	index = 0;
	while (--size > 0)
	{
		if (list[size] < min)
		{
			min = list[size];
			index = size;
		}
	}
	return (index);
}
