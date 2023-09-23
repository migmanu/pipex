/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:33:04 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/16 11:56:42 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *buf, const char *s, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (s[i])
			i++;
		return (i);
	}
	while (i < size -1 && s[i] != '\0')
	{
		buf[i] = s[i];
		i++;
	}
	if (i < size)
		buf[i] = '\0';
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
#include <bsd/string.h>
int	main(void)
{
	const char	src[] = "lorem ipsum dolor sit amet";
	const char	src2[] = "lorem ipsum dolor sit amet";
	size_t	size = 0;
	char	buf[15];
	char	buf2[15];
	char	*str;

	str = malloc(sizeof(char *) * 4);
	str[0] = '1', str[1] = '2', str[2] = '3';
	str[3] = '\0';
	printf("%s \n", str);
	printf("copy %zu\n", ft_strlcpy(str, src, size));
	printf("%s\n", buf);
	write(1, buf, 15);
	printf("\noriginal %zu\n", strlcpy(buf2, src2, size));
	printf("%s\n", buf2);
	write(1, buf2, 15);
}*/
