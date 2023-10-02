/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:47:49 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/01 17:16:43 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Frees a character vector
void	ft_free_vec(char *vec[])
{
	int	i;

	if (!vec)
		return ;
	i = 0;
	while (vec[i])
	{
		free(vec[i]);
		vec[i] = NULL;
		i++;
	}
	free(vec);
}
