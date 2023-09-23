/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:52:07 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/15 15:16:07 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	i = ft_strlen(s);
	while (i > 0 || s[i] == (char)c)
	{
		if (s[i] == (char)c)
		{
			ptr = (char *)&s[i];
			return (ptr);
		}
		i--;
	}
	return (NULL);
}
/*
#include <string.h>
int	main(void)
{
	char	src[] = "hola mundo!";
	char	c = 'h';
	printf("%s %p\n\n", strrchr(src, c), strrchr(src, c));
	printf("%s %p\n\n", ft_strrchr(src, c), ft_strrchr(src, c));
	return (0);
}*/
