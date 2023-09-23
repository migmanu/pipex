/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:22:49 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/06/21 19:50:19 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_cinstr(const char *s, char c)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			r++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (r);
}

static char	**ft_vecinit(const char *s, char c)
{
	char	**vec;
	int		r;

	r = ft_cinstr(s, c) + 1;
	vec = (char **)malloc(sizeof(char *) * r);
	if (!vec)
		return (NULL);
	vec[r - 1] = NULL;
	return (vec);
}

static void	*ft_strfiller(char *vec, char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		vec[i] = s[i];
		i++;
	}
	vec[i] = '\0';
	return (s);
}

static char	**ft_strsplit(char **vec, char *s, char c)
{
	size_t	i;
	size_t	v;

	i = 0;
	v = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			s++;
		else
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			vec[v] = (char *)malloc(sizeof(char) * i + 1);
			if (!vec[v])
				return (NULL);
			ft_strfiller(vec[v], s, c);
			s += i;
			i = 0;
			v++;
		}
	}
	return (vec);
}

char	**ft_split(char const *s, char c)
{
	char	**vec;
	char	*cpy;

	if (!s)
		return (NULL);
	vec = ft_vecinit(s, c);
	cpy = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!vec || !cpy)
		return (NULL);
	ft_strlcpy(cpy, s, ft_strlen(s) + 1);
	if (!(ft_strsplit(vec, cpy, c)))
		return (NULL);
	free(cpy);
	return (vec);
}
/*
int main(void)
{
    char s[] = "xxxxxxxxhello!";
    char c = 'x';

    char **res = ft_split(s, c);
    if (res)
    {
        int i = 0;
        while (res[i])
        {
			write(1, res[i], ft_strlen(res[i]));
//			write(1, "|", 1);
			write(1, "\n", 1);
            i++;
        }
    }
    return 0;
}*/
