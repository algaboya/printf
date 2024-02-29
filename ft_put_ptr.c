/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:40:05 by algaboya          #+#    #+#             */
/*   Updated: 2024/02/29 20:33:58 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	write(1, "0", 1);
	write(1, "x", 1);
	count = 2 + ft_put_low_hex(ptr);
	return (count);
}
