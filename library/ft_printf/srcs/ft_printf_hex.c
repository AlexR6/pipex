/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:10:46 by arastell          #+#    #+#             */
/*   Updated: 2022/11/11 13:18:31 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_hex(unsigned int n, int *count)
{
	char	*tmp;

	tmp = ft_strdup("0123456789abcdef");
	if (tmp)
	{
		ft_putnbr_hex(n, tmp, count);
		free(tmp);
	}
}

void	ft_printf_upp_hex(unsigned int n, int *count)
{
	char	*tmp;

	tmp = ft_strdup("0123456789ABCDEF");
	if (tmp)
	{
		ft_putnbr_hex(n, tmp, count);
		free(tmp);
	}
}
