/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:54:22 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/23 15:43:30 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chrstr(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	e;
	size_t	r;
	char	*ptr;

	i = 0;
	e = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && ft_chrstr(s1[i], set) == 1)
		i++;
	while (e > 0 && ft_chrstr(s1[e], set) == 1)
		e--;
	if (i > e)
		ptr = malloc(sizeof(char) * 1);
	else
		ptr = malloc(sizeof(char) * (e - i) + 2);
	if (ptr == NULL)
		return (NULL);
	r = 0;
	while (s1[i] != '\0' && i <= e)
		ptr[r++] = s1[i++];
	ptr[r] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	char	*s = "  \t \t \n   \n\n\n\t";
	char	*s2 = "";
	char	*set = " \n\t";
	char	*ptr = ft_strtrim(s, set);
	if (strcmp(ptr, s2) == 0)
	{
		printf("same");
	}
	else
	{
		printf("fail");
	}
	return(0);
}*/
/*
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/
