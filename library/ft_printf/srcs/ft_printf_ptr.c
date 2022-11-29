/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:45:28 by arastell          #+#    #+#             */
/*   Updated: 2022/11/11 13:18:34 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_ptr(void *ptr, int *count)
{
	if ((uintptr_t) ptr == 0)
		*count += ft_printf_str("0x0");
	else
	{
		*count += ft_printf_str("0x");
		ft_putnbr_ptr((uintptr_t) ptr, "0123456789abcdef", count);
	}
}
