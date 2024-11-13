/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:01:46 by ahekinci          #+#    #+#             */
/*   Updated: 2024/11/13 10:11:47 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

size_t	ft_strlen(char *str);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putsize_t(size_t n);

int		ft_puthexnbr(unsigned int nb, char x);
int		ft_puthexptr(unsigned long nb);
int		ft_putptr(void *ptr);
int		ft_printf(const char *format, ...);

#endif