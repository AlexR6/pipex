/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:51:31 by arastell          #+#    #+#             */
/*   Updated: 2022/11/28 09:04:10 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "../../libft/libft.h"

int			ft_printf(const char *s, ...);
int			ft_check(const char *s);
int			ft_printf_str(const char *s);
int			ft_printf_char(char c);
int			ft_printf_dec(int n);
int			ft_printf_unsigned_dec(unsigned int n);
void		ft_printf_ptr(void *ptr, int *count);
void		ft_printf_hex(unsigned int n, int *count);
void		ft_printf_upp_hex(unsigned int n, int *count);
void		ft_putnbr_hex(unsigned int n, char *s, int *count);
void		ft_putnbr_ptr(uintptr_t n, char *s, int *count);

#endif
