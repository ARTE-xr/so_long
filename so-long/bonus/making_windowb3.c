/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_windowb3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 02:03:33 by mattif            #+#    #+#             */
/*   Updated: 2022/02/21 15:10:14 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_img(t_data *my)
{
	mlx_clear_window(my->mlx_ptr, my->win_ptr);
	print_wall1(my);
	print_c(my);
	print_p(my);
	print_e(my);
	print_f(my);
	print_0(my);
	if (my->rescoll == my->eatencoll && my->rescoll != 0)
		print_e1(my);
	else if (my->rescoll != my->eatencoll || my->rescoll == 0)
		print_e2(my);
	my->t = ft_itoa(my->mouve_count);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 10, 10, 65439, "MOVES COUNT :");
	mlx_string_put(my->mlx_ptr, my->win_ptr, 145, 10, 65439, my->t);
	free(my->t);
}

void	key2(int k, t_data *my, int i)
{
	if (k == 53)
	{
		ft_printf("You Quit !\n");
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

void	ft_path(t_data *my)
{
	my->path = "./image/wall.xpm";
	my->img_1 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/ground.xpm";
	my->img_0 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/player1.xpm";
	my->img_p1 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/player2.xpm";
	my->img_p2 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/player3.xpm";
	my->img_p3 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/player4.xpm";
	my->img_p4 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/player5.xpm";
	my->img_p5 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/player6.xpm";
	my->img_p6 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/door1.xpm";
	my->img_e2 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/door.xpm";
	my->img_e1 = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	my->path = "./image/collect.xpm";
	my->img_c = mlx_xpm_file_to_image(my->mlx_ptr, my->path, &my->w, &my->h);
	ft_path2(my);
	ft_print_img(my);
}

void	print_map(t_data *my)
{
	my->i = 0;
	my->mouve_count = 0;
	my->eatencoll = 0;
	my->img_loop = 0;
	my->mlx_ptr = mlx_init();
	my->win_ptr = mlx_new_window(my->mlx_ptr, ft_strlen(my->map[my->i]) * 64,
			ft_mapelines(my->map) * 64, "so_long");
	ft_path(my);
	mlx_hook(my->win_ptr, 2, 0, key, my);
	mlx_hook(my->win_ptr, 17, 0, sa, NULL);
	mlx_loop_hook(my->mlx_ptr, print_p, my);
	mlx_loop_hook(my->mlx_ptr, move_enemy, my);
	ft_collect_conter(my);
	mlx_loop(my->mlx_ptr);
}
