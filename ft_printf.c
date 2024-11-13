/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:34:01 by ahekinci          #+#    #+#             */
/*   Updated: 2024/11/13 11:39:20 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_puthexnbr(unsigned int nb, char x)
{
	int	count;

	count = 0;
	if (nb > 15)
		count += ft_puthexnbr(nb / 16, x);
	if (nb % 16 < 10)
	{
		if (ft_putnbr(nb % 16) == -1)
			return (-1);
		count++;
	}
	else
	{
		if (x == 'x')
		{
			if (ft_putchar(nb % 16 - 10 + 'a') == -1)
				return (-1);
			return (count++, count);
		}
		if (ft_putchar(nb % 16 - 10 + 'A') == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_puthexptr(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb > 15)
		count += ft_puthexptr(nb / 16);
	if (nb % 16 < 10)
	{
		if (ft_putnbr(nb % 16) == -1)
			return (-1);
		count++;
	}
	else
	{
		if (ft_putchar(nb % 16 - 10 + 'a') == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	nb;
	int				count;
	int				check;

	if (!ptr)
	{
		if (!write(1, "(nil)", 5))
			return (-1);
		return (5);
	}
	count = 0;
	check = write(1, "0x", 2);
	if (!check)
		return (-1);
	count += check;
	nb = (unsigned long)ptr;
	check = ft_puthexptr(nb);
	if (check == -1)
		return (-1);
	count += check;
	return (count);
}

int	flag(const char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == '%')
	{
		if (!write(1, "%", 1))
			return (-1);
		count++;
	}
	else if (format == 'u')
		count += ft_putsize_t(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_puthexnbr(va_arg(args, unsigned int), format);
	else if (format == 'p')
		count += ft_putptr(va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += flag(format[i], args);
		}
		else
		{
			if (!write(1, &format[i], 1))
				return (-1);
			count++;
		}
		i++;
	}
	return (va_end(args), count);
}
