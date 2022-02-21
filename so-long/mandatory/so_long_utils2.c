/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattif <mattif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:46:53 by mattif            #+#    #+#             */
/*   Updated: 2022/02/17 22:17:21 by mattif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

static int	len_words(const char *str, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	count_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static	void	ft_free(char **p)
{
	int		i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free (p);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	char	**str;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	str = malloc(sizeof(char *) * (len_words(s, c) + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		i = count_len(s, c);
		if (*s != c && *s)
			str[j++] = ft_substr(s, 0, i);
		if ((!str[j - 1]) && *s)
			ft_free(str);
			s += i;
	}
	str[j] = NULL;
	return (str);
}
