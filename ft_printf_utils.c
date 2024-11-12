/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:59:16 by ahekinci          #+#    #+#             */
/*   Updated: 2024/11/12 21:00:28 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


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