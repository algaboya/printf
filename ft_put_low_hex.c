/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_low_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:56:20 by algaboya          #+#    #+#             */
/*   Updated: 2024/03/04 20:44:05 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_low_hex(unsigned int nbr)
{
	char			*buff;
	unsigned int	count;

	count = 0;
	buff = "0123456789abcdef";
	if (nbr < 16)
	{
		count += ft_put_char(buff[nbr]);
		return (count);
	}
	if (nbr >= 16)
	{
		count += ft_put_low_hex(nbr / 16);
		count += ft_put_low_hex(nbr % 16);
		return (count);
	}
	return (0);
}
