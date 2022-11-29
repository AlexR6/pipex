/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:18:52 by arastell          #+#    #+#             */
/*   Updated: 2022/11/11 13:18:47 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_strcpy_dup(char *dst, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(const char *s)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!tmp)
		return (0);
	ft_strcpy_dup(tmp, s);
	return (tmp);
}
