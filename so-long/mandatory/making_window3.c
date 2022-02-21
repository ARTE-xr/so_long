/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_window3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 02:03:33 by mattif            #+#    #+#             */
/*   Updated: 2022/02/17 22:28:41 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_data *my)
{
	free(my->line);
	free(my->map);
	mlx_destroy_image(my->mlx_ptr, my->img_1);
	mlx_destroy_image(my->mlx_ptr, my->img_0);
	mlx_destroy_image(my->mlx_ptr, my->img_p);
	mlx_destroy_image(my->mlx_ptr, my->img_e);
	mlx_destroy_image(my->mlx_ptr, my->img_c);
}

void	ft_print_img(t_data *my)
{
	mlx_clear_window(my->mlx_ptr, my->win_ptr);
	print_wall1(my);
	print_c(my);
	print_p(my);
	print_e(my);
	print_0(my);
}

void	key2(int k, t_data *my, int i)
{
	if (k == 53)
	{
		ft_printf("You Quit!\n");
		free_all(my);
		exit (0);
	}
	if (k == 1)
	{
		ft_movedown(my);
		ft_print_img(my);
		if (my->mouve_count != i)
			ft_printf("%d\n", my->mouve_count);
	}
	if (k == 13)
	{
		ft_move_up(my);
		ft_print_img(my);
		if (my->mouve_count != i)
			ft_printf("%d\n", my->mouve_count);
	}
}

int	key(int k, t_data *my)
{
	int	i;

	i = my->mouve_count;
	if (k == 0)
	{
		ft_moveleft(my);
		ft_print_img(my);
		if (my->mouve_count != i)
			ft_printf("%d\n", my->mouve_count);
	}
	if (k == 2)
	{
		ft_moveright(my);
		ft_print_img(my);
		if (my->mouve_count != i)
			ft_printf("%d\n", my->mouve_count);
	}
	if (k == 53 || k == 1 || k == 13)
		key2(k, my, i);
	return (0);
}

void	print_mape(t_data *my)
{
	my->i = 0;
	my->x = 0;
	my->y = 0;
	my->j = 0;
	my->f = 0;
	my->mouve_count = 0;
	my->eatencoll = 0;
	my->mlx_ptr = mlx_init();
	my->win_ptr = mlx_new_window(my->mlx_ptr, ft_strlen(my->map[my->i]) * 64,
			ft_mapelines(my->map) * 64, "so_long");
	my->path = "./image/wall.xpm";
	my->img_1 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/ground.xpm";
	my->img_0 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/player.xpm";
	my->img_p = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/door1.xpm";
	my->img_e = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/collect.xpm";
	my->img_c = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	ft_print_img(my);
	mlx_hook(my->win_ptr, 2, 0, key, my);
	mlx_hook(my->win_ptr, 17, 0, sa, NULL);
	ft_collect_conter(my);
	mlx_loop(my->mlx_ptr);
}
