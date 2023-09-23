/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:44:59 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/16 12:48:50 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	l;

	i = 0;
	c = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		l = i;
		while (i < len && big[i] == little[c])
		{
			if (little[c + 1] == '\0')
				return ((char *)big + (i - c));
			i++;
			c++;
		}
		c = 0;
		i = l + 1;
	}
	return (NULL);
}
/*
#include <bsd/string.h>
int	main(void)
{
	const char	largestring[30] = "aaabcabcd";
    const char	smallstring[10] = "aabc";
    char		*ptr;
	char		*ptr2;
	int			len;

	len = -1;
    ptr2 = ft_strnstr(largestring, smallstring, len);
    ptr = strnstr(largestring, smallstring, len);
	printf("original:\n%s\n\ncopy:\n%s", ptr, ptr2);
	return (0);
}*/
