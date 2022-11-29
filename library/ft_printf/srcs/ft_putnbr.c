/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:58:26 by arastell          #+#    #+#             */
/*   Updated: 2022/11/11 13:18:44 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_hex(unsigned int nbr, char *base, int *count)
{
	if (nbr > 15)
	{
		ft_putnbr_hex(nbr / 16, base, count);
		ft_putnbr_hex(nbr % 16, base, count);
	}
	else
	{
		write(1, &base[nbr], 1);
		*count += 1;
	}
}

void	ft_putnbr_ptr(uintptr_t nbr, char *base, int *count)
{
	if (nbr > 15)
	{
		ft_putnbr_ptr(nbr / 16, base, count);
		ft_putnbr_ptr(nbr % 16, base, count);
	}
	else
	{
		write(1, &base[nbr], 1);
		*count += 1;
	}
}
