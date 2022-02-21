/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:16:05 by mattif            #+#    #+#             */
/*   Updated: 2022/02/21 15:09:30 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include	<stdio.h>
# include	<mlx.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	"../ft_printf/ft_printf.h"

typedef struct s_var
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;
	int	f;
}	t_game;

typedef struct s_data
{
	void	*img_1;
	void	*img_f;
	void	*img_f2;
	void	*img_f3;
	void	*img_f4;
	void	*img_p1;
	void	*img_p2;
	void	*img_p3;
	void	*img_p4;
	void	*img_p5;
	void	*img_p6;
	void	*img_c;
	void	*img_e1;
	void	*img_e2;
	void	*img_0;
	int		img_loop;
	int		h;
	int		w;
	int		i;
	int		x;
	int		y;
	int		n;
	int		fd;
	int		j;
	int		f;
	char	*t;
	int		rescoll;
	int		eatencoll;
	int		mouve_count;
	char	*addr;
	char	*path;
	void	*img;
	char	*line;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*imgb;
}	t_data;

char	*read_map(int fd, char *line);
int		ft_mapelines(char **map);
int		checkext(char *av);
int		lines(char *line);
int		check_map(char **map, char *line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
int		ft_strlen(char *s);
char	**ft_split(const char *s, char c);
char	*ft_strdup(char *src);
char	*ft_itoa(int n);
void	print_wall1(t_data *my);
int		print_p(t_data *my);
void	print_e(t_data *my);
void	print_c(t_data *my);
void	print_0(t_data *my);
int		print_f(t_data *my);
void	ft_collect_conter(t_data *my);
char	*ft_strstr(const char *s, const char *tofind);
int		ft_locat_p(t_data *my);
int		ft_moveleft(t_data *my);
int		ft_moveright(t_data *my);
int		ft_movedown(t_data *my);
int		ft_move_up(t_data *my);
int		check_map2(char *line);
int		valid_map(int fd, int i);
int		sa(void);
void	free_all(t_data *my);
void	ft_print_img(t_data *my);
void	key2(int k, t_data *my, int i);
int		key(int k, t_data *my);
void	print_map(t_data *my);
void	died(t_data *my);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_strcpy(char *dst, const char *src);
void	player_animation(t_data *pl);
void	print_e1(t_data *my);
void	print_e2(t_data *my);
int		ft_locat_f(t_data *my);
int		move_left(t_data *my);
int		move_right(t_data *my);
int		move_up(t_data *my);
int		move_down(t_data *my);
int		move_enemy(t_data *m);
void	enemy_animation(t_data *pl);
void	ft_path2(t_data *my);

#endif