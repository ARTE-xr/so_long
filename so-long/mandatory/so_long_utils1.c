/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:46:25 by mattif            #+#    #+#             */
/*   Updated: 2022/02/13 03:00:48 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (s1[j])
	{
		p[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		p[i++] = s2[j++];
	}
	p[i] = '\0';
	free (s1);
	s1 = NULL;
	return (p);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (*(char *)(s + i))
	{
		if (*(char *)(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *str)
{
	unsigned int	k;
	unsigned int	i;
	char			*p;

	i = 0;
	k = ft_strlen((char *)str) + 1;
	p = (char *)malloc(k * sizeof(char));
	if (!p)
		return (NULL);
	if (!str)
	{
		str[i] = '\0';
		return (str);
	}
	while (str && k-- > 0)
	{
		p[i] = str[i];
		i++;
	}
	return (p);
}
