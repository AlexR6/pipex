/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:04:10 by arastell          #+#    #+#             */
/*   Updated: 2022/11/11 13:18:08 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_str(const char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_printf_char(s[i]);
			i++;
		}
		return (i);
	}
	write(1, "(null)", 6);
	return (6);
}
