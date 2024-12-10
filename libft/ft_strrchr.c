/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:31:57 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/06 15:00:45 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
		++index;
	c = (unsigned char)c;
	while (index >= 0)
	{
		if (s[index] == c)
			return ((char *)(s + index));
		--index;
	}
	return (0);
}
