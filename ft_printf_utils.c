/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:59:16 by ahekinci          #+#    #+#             */
/*   Updated: 2024/11/13 11:09:55 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(char *str)
{
	char	*s;

	s = str;
	if (!str || !*str)
		return (0);
	while (*s)
		s++;
	return (s - str);
}

int	ft_putchar(char c)
{
	if (write(1, &c, 1))
		return (1);
	return (-1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (write(1, s, len) && len)
		return (len);
	else if (!len)
		return (0);
	return (-1);
}

int	ft_putnbr(int n)
{
	char	c;
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		if (!write(1, "-2147483648", 11))
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		if (!write(1, "-", 1))
			return (-1);
		i++;
		n *= -1;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
	}
	c = n % 10 + '0';
	if (!write(1, &c, 1))
		return (-1);
	return (i++, i);
}

int	ft_putsize_t(size_t n)
{
	char	c;
	size_t	i;

	i = 0;
	if (n > 9)
		i += ft_putsize_t(n / 10);
	c = n % 10 + '0';
	if (!write(1, &c, 1))
		return (-1);
	i++;
	return (i);
}
