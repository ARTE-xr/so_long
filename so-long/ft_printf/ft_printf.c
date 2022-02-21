/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:58:31 by mattif            #+#    #+#             */
/*   Updated: 2021/12/24 06:29:04 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkp(char f, va_list(ap))
{
	int	i;

	i = 0;
	if (f == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (f == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (f == 'p')
		i += ft_adress(va_arg(ap, unsigned long int));
	else if (f == 'd' || f == 'i')
		i += ft_putnbr(va_arg(ap, int));
	else if (f == 'u')
		i += ft_uputnbr(va_arg(ap, int));
	else if (f == 'x' || f == 'X')
		i += ft_hexa(va_arg(ap, unsigned int), f);
	else if (f == '%')
		i += ft_putchar('%');
	else
		return (ft_putchar(f));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_checkp(format[++i], ap);
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
