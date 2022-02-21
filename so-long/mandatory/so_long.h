/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:16:05 by mattif            #+#    #+#             */
/*   Updated: 2022/02/17 22:17:54 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	<stdio.h>
# include	<mlx.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	"../ft_printf/ft_printf.h"

typedef struct var
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;
}	t_game;

typedef struct s_data
{
	void	*img_1;
	void	*img_p;
	void	*img_c;
	void	*img_e;
	void	*img_0;
	int		h;
	int		w;
	int		i;
	int		x;
	int		y;
	int		n;
	int		fd;
	int		j;
	int		f;
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
}t_data;

char	*read_map(int fd, char *line);
int		ft_mapelines(char **map);
void	died(t_data *my);
void	ft_path(t_data *my);
int		checkext(char *av);
int		lines(char *line);
int		check_map(char **map, char *line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
int		ft_strlen(char *s);
char	**ft_split(const char *s, char c);
char	*ft_strdup(char *src);
void	print_wall1(t_data *my);
void	print_p(t_data *my);
void	print_e(t_data *my);
void	print_c(t_data *my);
void	print_0(t_data *my);
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
void	print_mape(t_data *my);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_strcpy(char *dst, const char *src);

#endif