/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 13:52:08 by jbakker       #+#    #+#                 */
/*   Updated: 2024/07/08 16:44:53 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	function_switch(char c, va_list *arguments, t_flags *flags)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*arguments, int), flags));
	if (c == 's')
		return (ft_putstr(va_arg(*arguments, char *), flags));
	if (c == 'p')
		return (ft_putvoidptr(va_arg(*arguments, void *), flags));
	if (c == 'd' || c == 'i')
		return (ft_putnum(va_arg(*arguments, int), flags));
	if (c == 'u')
		return (ft_putunum(va_arg(*arguments, unsigned int), flags));
	if (c == 'x')
		return (ft_printhex(va_arg(*arguments, int), 'a', flags));
	if (c == 'X')
		return (ft_printhex(va_arg(*arguments, int), 'A', flags));
	if (c == '%')
		return (ft_write(0, "%", 1));
	return (-1);
}

static void	print_normal_string(const char *ptr, int *index)
{
	int	length;

	length = 0;
	while (ptr[length] && ptr[length] != '%')
		length++;
	if (length)
		ft_write(0, ptr, length);
	*index += length;
}

static void	print_argument(const char *ptr, int *idx, va_list *args)
{
	t_flags	flags;
	int		chars_written;
	int		chr_to_skip;

	if (ptr[0] != '%')
		return ;
	chr_to_skip = get_flags(ptr + 1, 0, &flags);
	chars_written = function_switch(*(ptr + chr_to_skip + 1), args, &flags);
	if (chars_written == -1)
	{
		ft_print_flags(&flags);
		if (!*(ptr + chr_to_skip + 1))
			*idx -= 1;
		else if (*(ptr + chr_to_skip + 1) <= 'a'
			|| *(ptr + chr_to_skip + 1) >= 'z')
			ft_write(0, ptr + chr_to_skip + 1, 1);
	}
	*idx += chr_to_skip + 2;
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		index;

	index = 0;
	va_start(arguments, format);
	while (index >= 0 && format[index])
	{
		print_normal_string(&format[index], &index);
		print_argument(&format[index], &index, &arguments);
	}
	va_end(arguments);
	return (ft_write(1, NULL, 0));
}

int	ft_printf_fd(const char *format, int fd, ...)
{
	va_list	arguments;
	int		index;

	index = 0;
	va_start(arguments, fd);
	while (index >= 0 && format[index])
	{
		print_normal_string(&format[index], &index);
		print_argument(&format[index], &index, &arguments);
	}
	va_end(arguments);
	return (ft_write(fd, NULL, 0));
}
