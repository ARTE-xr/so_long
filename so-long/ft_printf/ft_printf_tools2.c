/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 20:13:55 by mattif            #+#    #+#             */
/*   Updated: 2021/12/24 06:43:43 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_forp(unsigned long n, char a)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (n < 16)
	{
		ft_putchar(base[n]);
		i++;
	}
	else
	{
		i += x_forp(n / 16, a);
		i += x_forp(n % 16, a);
	}
	return (i);
}

int	ft_adress(unsigned long int n)
{
	int	len;

	len = ft_putstr("0x");
	len += x_forp(n, 'x');
	return (len);
}

int	ft_hexa(unsigned int n, char s)
{
	int		i;
	char	*base;

	i = 0;
	if (s == 'x')
		base = "0123456789abcdef";
	else if (s == 'X')
		base = "0123456789ABCDEF";
	if (n < 16)
	{
		ft_putchar(base[n]);
		i++;
	}
	else
	{
		i += ft_hexa(n / 16, s);
		i += ft_hexa(n % 16, s);
	}
	return (i);
}
