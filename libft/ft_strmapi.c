/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:22:48 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/25 12:03:06 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (!s || !f)
		return (NULL);
	res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
char transform(unsigned int index, char c)
{
	// Perform some transformation on the character 'c' based on the index
	// For example, let's convert lowercase letters to uppercase at odd indices
	if (index % 2 == 1 && c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';

	return c;
}

int	main(void)
{
	char	*s = "hola mundo";
	printf("%s", ft_strmapi(s, *transform));
	return (0);
}*/
