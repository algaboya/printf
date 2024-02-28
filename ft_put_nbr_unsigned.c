/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:21:12 by algaboya          #+#    #+#             */
/*   Updated: 2024/02/28 21:03:33 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr_unsigned(int n)
{
	int		i;
	char	buf[10];

	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	i = 10;
	while (n != 0 && i > 0)
	{
		i--;
		buf[i] = n % 10 + '0';
		n /= 10;
	}
	write(1, &buf[i], 10 - i);
	return (16 - i);
}
