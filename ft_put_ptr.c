/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:40:05 by algaboya          #+#    #+#             */
/*   Updated: 2024/03/04 20:34:24 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_hex(unsigned long long nbr)
{
	int					i;
	char				*buff;
	char				new_buff[16];
	unsigned long long	rm;

	buff = "0123456789abcdef";
	i = 16;
	if (nbr == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	while (nbr != 0 && i > 0)
	{
		i--;
		rm = nbr % 16;
		new_buff[i] = buff[rm];
		nbr /= 16;
	}
	write(1, &new_buff[i], 16 - i);
	return (16 - i);
}

int	ft_put_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	write(1, "0", 1);
	write(1, "x", 1);
	count = 2 + ft_ptr_hex(ptr);
	return (count);
}
