/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_int_list.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/18 15:56:12 by jbakker       #+#    #+#                 */
/*   Updated: 2024/05/25 17:41:50 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	merge(int *list, int l1, int l2)
{
	int	index_sl1;
	int	index_sl2;
	int	temp;

	index_sl1 = 0;
	index_sl2 = l1;
	while (l1 > 0 || l2 > 0)
	{
		if (l1 > 0 && (!l2 || list[index_sl1] < list[index_sl2]))
		{
			index_sl1++;
			l1--;
		}
		else
		{
			temp = list[index_sl2];
			ft_memmove(list + index_sl1 + 1, list + index_sl1, \
				sizeof(int) * (index_sl2 - index_sl1));
			list[index_sl1++] = temp;
			index_sl2++;
			l2--;
		}
	}
}

int	*ft_sort_int_list(int *list, int start_index, int end_index)
{
	int	length;
	int	sub_length;
	int	start;

	length = end_index - start_index + 1;
	sub_length = 2;
	while (sub_length < length)
	{
		start = 0;
		while (start < length)
		{
			merge(list + start, ft_min(length - start, sub_length >> 1), \
		ft_max(0, ft_min(length - start - (sub_length >> 1), sub_length >> 1)));
			start += sub_length;
		}
		sub_length *= 2;
	}
	merge(list, ft_min(length, sub_length >> 1), ft_max(0, \
		ft_min(length - (sub_length >> 1), sub_length >> 1)));
	return (list);
}
