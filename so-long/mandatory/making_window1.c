/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_window1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:23:04 by mattif            #+#    #+#             */
/*   Updated: 2022/02/17 22:23:07 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect_conter(t_data *my)
{
	my->i = 0;
	my->j = 0;
	while (my->map[my->i])
	{
		while (my->map[my->i][my->j])
		{
			if (my->map[my->i][my->j] == 'C')
				my->rescoll++;
			my->j++;
		}
		my->j = 0;
		my->i++;
	}
}
