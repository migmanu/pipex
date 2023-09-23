/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:08:51 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/23 18:00:08 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_allolen(char const *s, unsigned int start, size_t len)
{
	if (start >= ft_strlen(s))
		return (0);
	if (len > ft_strlen(s))
		return (ft_strlen(s));
	if (len == ft_strlen(s))
		return (len - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	r;
	size_t			l;
	char			*ptr;

	l = ft_allolen(s, start, len);
	ptr = (char *)malloc(sizeof(char) * l + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	r = 0;
	while (s[i])
	{
		if (i >= start && r < len)
		{
			ptr[r] = s[i];
			r++;
		}
		i++;
	}
	ptr[r] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	char	*s = "0123456789";
	char	*r;
	unsigned int start = 9;
	size_t len = 10;

	r = ft_substr(s, start, len);
	printf("%s", r);
	return (0);
}
*/
/*
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.*/
