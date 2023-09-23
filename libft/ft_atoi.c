/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:31:23 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/05/16 13:01:14 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	type_check(char c)
{
	int	a;

	a = c;
	if ((a >= 9 && a <= 13) || a == 32)
		return (3);
	if (a == 45)
		return (2);
	if (a >= 48 && a <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (type_check(str[i]) == 3)
		i++;
	if (str[i] == '+' && type_check(str[i + 1]) == 1)
		i++;
	if (type_check(str[i]) == 2)
	{
		sign *= -1;
		i++;
	}
	while (type_check(str[i]) == 1)
		result = (result * 10) + (str[i++] - '0');
	return (result * sign);
}
/*
int	main(void)
{
	char	*nptr = "\t\n\r\v\f  469 \n";
	printf("original:%d\n\n", atoi(nptr));
	printf("copy:%d", ft_atoi(nptr));

	return (0);
}*/
