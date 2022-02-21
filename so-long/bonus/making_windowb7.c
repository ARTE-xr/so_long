/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_windowb7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:51:47 by mattif            #+#    #+#             */
/*   Updated: 2022/02/21 15:46:12 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_enemy(t_data *m)
{
	int	r;

	ft_locat_f(m);
	r = arc4random() % 80;
	if (r == 1)
		move_left(m);
	else if (r == 2)
		move_right(m);
	else if (r == 3)
		move_down(m);
	else if (r == 4)
		move_up(m);
	ft_print_img(m);
	return (0);
}

void	enemy_animation(t_data *pl)
{
	if (pl->img_loop <= 10)
		mlx_put_image_to_window(pl->mlx_ptr, pl->win_ptr,
			pl->img_f, pl->x, pl->y);
	else if (pl->img_loop >= 11 && pl->img_loop <= 20)
		mlx_put_image_to_window(pl->mlx_ptr, pl->win_ptr,
			pl->img_f2, pl->x, pl->y);
	else if (pl->img_loop >= 21 && pl->img_loop <= 30)
		mlx_put_image_to_window(pl->mlx_ptr, pl->win_ptr,
			pl->img_f3, pl->x, pl->y);
	else if (pl->img_loop >= 31 && pl->img_loop <= 40)
		mlx_put_image_to_window(pl->mlx_ptr, pl->win_ptr,
			pl->img_f4, pl->x, pl->y);
	if (pl->img_loop == 40)
		pl->img_loop = 0;
}

void	ft_path2(t_data *my)
{
	my->path = "./image/enemy.xpm";
	my->img_f = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/enemy1.xpm";
	my->img_f2 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/enemy2.xpm";
	my->img_f3 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/enemy3.xpm";
	my->img_f4 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
}
