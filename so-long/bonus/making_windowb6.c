/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_windowb6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:33:52 by mattif            #+#    #+#             */
/*   Updated: 2022/02/21 15:36:58 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_locat_f(t_data *my)
{
	my->i = 0;
	my->j = 0;
	while (my->map[my->i])
	{
		while (my->map[my->i][my->j])
		{
			if (my->map[my->i][my->j] == 'F')
				return (0);
			my->j++;
		}
		my->j = 0;
		my->i++;
	}
	return (0);
}

int	move_left(t_data *my)
{
	ft_locat_f(my);
	if (my->map[my->i][my->j - 1] == '1')
	{
		return (0);
	}
	else if (my->map[my->i][my->j - 1] == '0')
	{
		my->map[my->i][my->j - 1] = 'F';
		my->map[my->i][my->j] = '0';
		my->j--;
	}
	else if (my->map[my->i][my->j - 1] == 'C')
		return (0);
	else if (my->map[my->i][my->j - 1] == 'F')
		return (0);
	else if (my->map[my->i][my->j - 1] == 'E')
		return (0);
	else if (my->map[my->i][my->j - 1] == 'P')
		died(my);
	return (0);
}

int	move_right(t_data *my)
{
	ft_locat_f(my);
	if (my->map[my->i][my->j + 1] == '1')
	{
		return (0);
	}
	else if (my->map[my->i][my->j + 1] == '0')
	{
		my->map[my->i][my->j + 1] = 'F';
		my->map[my->i][my->j] = '0';
		my->j++;
	}
	else if (my->map[my->i][my->j + 1] == 'C')
		return (0);
	else if (my->map[my->i][my->j + 1] == 'F')
		return (0);
	else if (my->map[my->i][my->j + 1] == 'E')
		return (0);
	else if (my->map[my->i][my->j + 1] == 'P')
		died(my);
	return (0);
}

int	move_up(t_data *my)
{
	ft_locat_f(my);
	if (my->map[my->i - 1][my->j] == '1')
	{
		return (0);
	}
	else if (my->map[my->i - 1][my->j] == '0')
	{
		my->map[my->i - 1][my->j] = 'F';
		my->map[my->i][my->j] = '0';
		my->i--;
	}
	else if (my->map[my->i - 1][my->j] == 'C')
		return (0);
	else if (my->map[my->i - 1][my->j] == 'F')
		return (0);
	else if (my->map[my->i - 1][my->j] == 'E')
		return (0);
	else if (my->map[my->i - 1][my->j] == 'P')
		died(my);
	return (0);
}

int	move_down(t_data *my)
{
	ft_locat_f(my);
	if (my->map[my->i + 1][my->j] == '1')
	{
		return (0);
	}
	else if (my->map[my->i + 1][my->j] == '0')
	{
		my->map[my->i + 1][my->j] = 'F';
		my->map[my->i][my->j] = '0';
		my->i++;
	}
	else if (my->map[my->i + 1][my->j] == 'C')
		return (0);
	else if (my->map[my->i + 1][my->j] == 'F')
		return (0);
	else if (my->map[my->i + 1][my->j] == 'E')
		return (0);
	else if (my->map[my->i + 1][my->j] == 'P')
		died(my);
	return (0);
}
