/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:46:40 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/11 15:29:46 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)malloc((sizeof(char) * ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	char	*orig = "hola mundo";
	char	*ptr1;
	char	*ptr2;

	ptr1 = strdup(orig);
	ptr2 = ft_strdup(orig);

	printf("o: %s\n\nc: %s\n", ptr1, ptr2);
	return (0);
}*/
