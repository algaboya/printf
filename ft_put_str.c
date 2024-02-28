/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:59:23 by algaboya          #+#    #+#             */
/*   Updated: 2024/02/28 21:03:46 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(char *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*ptr != '\0')
	{
		ft_put_char(*ptr);
		ptr++;
		i++;
	}
	return (i);
}
