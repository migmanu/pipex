/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:17:07 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/09 11:10:39 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*dst;

	dst = (char *)s;
	i = 0;
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
}
/*
#include <strings.h>
int	main(void)
{
	char	s[] = "hola mundo";
	char	*s0;
	s0 = &s[4];
	char	s2[] = "hola mundo";
	size_t	n = 3;
	ft_bzero(s0, n);
	bzero(s2, n);
	if (s[7] == '\0')
		printf("yes\n");
	printf("copy: %s\n", s);
	printf("original: %s\n", s2);
	return (0);
}*/
