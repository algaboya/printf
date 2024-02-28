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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		y;
	va_list	args;

	va_start(args, str);
	i = 0;
	y = ft_strlen((char *) str);
	while (i < y)
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				ft_put_char(va_arg(args, unsigned int));
			else if (str[i + 1] == 's')
				ft_put_str(va_arg(args, char *));
			else if (str[i + 1] == 'x')
				ft_put_low_hex(va_arg(args, size_t));
			else if (str[i + 1] == 'X')
				ft_put_up_hex(va_arg(args, size_t));
			else if (str[i + 1] == 'p')
				ft_put_ptr(va_arg(args, unsigned long long));
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				ft_put_nbr(va_arg(args, int));
			else if (str[i + 1] == 'u')
				ft_put_nbr_unsigned(va_arg(args, unsigned int));
			else if (str[i] == '%')
				ft_put_char('%');
			i++;
		}
		else
			ft_put_char(str[i]);
		i++;
	}
	va_end(args);
	return (0);
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