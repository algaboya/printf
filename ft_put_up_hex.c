/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_up_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:38:28 by algaboya          #+#    #+#             */
/*   Updated: 2024/03/04 19:36:01 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_up_hex(unsigned long int nbr)
{
	char			*buff;
	unsigned int	count;

	count = 0;
	buff = "0123456789ABCDEF";
	if (nbr < 16)
	{
		count += ft_put_char(buff[nbr]);
		return (count);
	}
	if (nbr >= 16)
	{
		count += ft_put_up_hex(nbr / 16);
		count += ft_put_up_hex(nbr % 16);
		return (count);
	}
	return (0);
}
