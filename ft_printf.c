/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:34:01 by ahekinci          #+#    #+#             */
/*   Updated: 2024/11/11 16:01:19 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

size_t ft_strlen(char *str)
{
	char *s;

	if (!str || !*str)
		return (0);
	while (*s)
		s++;
	return (s - str);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (!s)
		ft_putstr("(null)");
	else
		while (*s)
			write(1, s++, 1);
	return (ft_strlen(s));
}

int	ft_putnbr(int n)
{
	char	c;
	int i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		i++;
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		i++;
	}
	c = n % 10 + '0';
	write(1, &c, 1);
	return (i);
}

int ft_putsize_t(size_t n)
{
	char	c;
	size_t i;

	i = 0;
	if (n > 9)
	{
		ft_putsize_t(n / 10);
		i++;
	}
	c = n % 10 + '0';
	write(1, &c, 1);
	return (i);

}

int	ft_puthexnbr(unsigned int nb, char x)
{
	int	count;

	count = 0;
	if (nb > 15)
		count += ft_puthexnbr(nb / 16, x);
	if (nb % 16 < 10)
		count += ft_putnbr(nb % 16);
	else
	{
		if (x == 'x')
			count += ft_putchar(nb % 16 - 10 + 'a');
		else if (x == 'X')
			count += ft_putchar(nb % 16 - 10 + 'A');
	}
	return (count);
}

int ft_putptr(uintptr_t nb)
{
	int count;

	count = 0;
	if (count == 0)
	{
		write(1, "0x", 2);
		count += 2;
	}
	if (nb > 15)
		count += ft_putptr(nb / 16);
	if (nb % 16 < 10)
		count += ft_putnbr(nb % 16);
	else
		count += ft_putchar(nb % 16 - 10 + 'a');
	return (count);
	
}

int	putptrnbr(uintptr_t nb)
{
	int	count;

	count = 0;
	if (nb > 15)
		count += putptrnbr(nb / 16);
	if (nb % 16 < 10)
		count += ft_putnbr(nb % 16);
	else
		count += ft_putchar('a' + (nb % 16 - 10));
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
			if (format[i] == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				count += ft_putnbr(va_arg(args, int));
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else if (format[i] == 'u')
				count += ft_putsize_t(va_arg(args, size_t));
			else if (format[i] == 'x' || format[i] == 'X')
				count += ft_puthexnbr(va_arg(args, unsigned int), format[i]);
			else if (format[i] == 'p')
			{
				if (!va_arg(args, void *))
					count += ft_putstr("(nil)");
				else
				{
					count += ft_putstr("0x");
					count += putptrnbr((uintptr_t)va_arg(args, void *)); 
				}
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int main()
{
	char *str = "Hello, World!";

	printf("%p\n", str);
	ft_printf("%p", str);
	return (0);
}