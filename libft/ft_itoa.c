/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:06:29 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/22 21:50:35 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_getstrlen(int n)
{
	unsigned int	res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		res += 1;
	while (n != 0)
	{
		res += 1;
		n = n / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	long int	len;
	long int	num;

	len = ft_getstrlen(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	num = n;
	if (num < 0)
	{
		res[0] = '-';
		num = num * -1;
	}
	if (num == 0)
		res[0] = '0';
	res[len] = '\0';
	while (num != 0 && len > 0)
	{
		res[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (res);
}
/*
int	main(void)
{
	int	n = -10;
	//printf("n: %d\nl: %d\n",n, ft_getstrlen(n));
	//printf("result:\n%s", ft_itoa(n));
	//write(1, ft_itoa(n), ft_getstrlen(n) + 1);
	char *ptr = ft_itoa(n);
	if (strcmp(ptr, "-10") != 0)
		printf("\nfail\n");
	write(1, ptr, strlen(ptr) + 1);
	return (0);
}*/
