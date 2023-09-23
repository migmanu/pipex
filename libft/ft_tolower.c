/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:28:05 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/11 10:41:15 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((char)c >= 65 && (char)c <= 90)
		return (c + 32);
	return (c);
}
/*
#include <ctype.h>
int	main(void)
{
	char	c = 'Z';
	printf("\n%c\n", tolower(c));
	printf("\n%c\n", ft_tolower(c));
	return (0);
}*/
