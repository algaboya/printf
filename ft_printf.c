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

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		z;

	va_start(args, str);
	i = 0;
	z = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				z += ft_put_char(va_arg(args, unsigned int));
			else if (str[i + 1] == 's')
				z += ft_put_str(va_arg(args, char *));
			else if (str[i + 1] == 'x')
				z += ft_put_low_hex(va_arg(args, unsigned long long));
			else if (str[i + 1] == 'X')
				z += ft_put_up_hex(va_arg(args, unsigned long long));
			else if (str[i + 1] == 'p')
				z += ft_put_ptr(va_arg(args, unsigned long long));
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				z += ft_put_nbr(va_arg(args, int));
			else if (str[i + 1] == 'u')
				z += ft_put_nbr_unsigned(va_arg(args, unsigned long));
			else if (str[i] == '%')
				z += ft_put_char('%');
			i++;
		}
		else
			z += ft_put_char(str[i]);
		i++;
	}
	va_end(args);
	return (z);
}


// int main()
// {
// 	// char *ptr = "hell jhvo";
// 	// printf("sjacvh asjgccbyuv %p d %c d", ptr, 's');
// 	// ft_put_low_hex(5131);

// 	printf("\n###\n");
// 	int i = 45;
// 	int *ptr = &i;
// 	printf("%p   %    c", ptr, 'h');
// 	printf("\n###\n");
// 	ft_printf("sjacvh asjg% byuv %p %c d", ptr, 's');
// 	// ft_printf("%p", ptr);
// 	// printf("\n###\n");
// 	return (0);
// }