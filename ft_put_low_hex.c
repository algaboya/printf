/* ************************************************************************** */
/*                                                                          */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:56:20 by algaboya          #+#    #+#             */
/*   Updated: 2024/02/26 20:08:40 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_low_hex(size_t nbr)
{
	int		i;
	long	rm;
	char	*buff;
	char	new_buff[16];

	buff = "123456789abcdef";
	i = 16;
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
