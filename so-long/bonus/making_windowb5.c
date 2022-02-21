/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_windowb5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:21:34 by mattif            #+#    #+#             */
/*   Updated: 2022/02/21 15:07:33 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_animation(t_data *pl)
{
	if (pl->img_loop <= 10)
		mlx_put_image_to_window(pl->mlx_ptr, pl->win_ptr,
			pl->img_p1, pl->x, pl->y);
	else if (pl->img_loop >= 11 && pl->img_loop <= 20)
		mlx_put_image_to_window(pl->mlx_ptr, pl->win_ptr,
			pl->img_p2, pl->x, pl->y);
	else if (pl->img_loop >= 21 && pl->img_loop <= 30)
		mlx_put_image_to_window(pl->mlx_ptr, pl->win_ptr,
			pl->img_p3, pl->x, pl->y);
	else if (pl->img_loop >= 31 && pl->img_loop <= 40)
		mlx_put_image_to_window(pl->mlx_ptr, pl->win_ptr,
			pl->img_p4, pl->x, pl->y);
	else if (pl->img_loop >= 41 && pl->img_loop <= 50)
		mlx_put_image_to_window(pl->mlx_ptr, pl->win_ptr,
			pl->img_p5, pl->x, pl->y);
	else if (pl->img_loop >= 51 && pl->img_loop <= 60)
		mlx_put_image_to_window(pl->mlx_ptr, pl->win_ptr,
			pl->img_p6, pl->x, pl->y);
	pl->img_loop++;
	if (pl->img_loop == 60)
		pl->img_loop = 0;
}

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

void	free_all(t_data *my)
{
	free(my->line);
	free(my->map);
	mlx_destroy_image(my->mlx_ptr, my->img_1);
	mlx_destroy_image(my->mlx_ptr, my->img_0);
	mlx_destroy_image(my->mlx_ptr, my->img_e1);
	mlx_destroy_image(my->mlx_ptr, my->img_e2);
	mlx_destroy_image(my->mlx_ptr, my->img_c);
	mlx_destroy_image(my->mlx_ptr, my->img_f);
	mlx_destroy_image(my->mlx_ptr, my->img_f2);
	mlx_destroy_image(my->mlx_ptr, my->img_f3);
	mlx_destroy_image(my->mlx_ptr, my->img_f4);
	mlx_destroy_image(my->mlx_ptr, my->img_p1);
	mlx_destroy_image(my->mlx_ptr, my->img_p2);
	mlx_destroy_image(my->mlx_ptr, my->img_p3);
	mlx_destroy_image(my->mlx_ptr, my->img_p4);
	mlx_destroy_image(my->mlx_ptr, my->img_p5);
	mlx_destroy_image(my->mlx_ptr, my->img_p6);
}

void	died(t_data *my)
{
	ft_printf("%s", "YOU DIED !\n");
	free_all(my);
	exit (0);
}
