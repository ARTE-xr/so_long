/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:58:35 by mattif            #+#    #+#             */
/*   Updated: 2021/12/24 06:34:40 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_hexa(unsigned int n, char s);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
long	ft_nblen(long long x);
int		ft_uputnbr(unsigned int nb);
int		ft_adress(unsigned long int n);
int		x_forp(unsigned long n, char a);

#endif