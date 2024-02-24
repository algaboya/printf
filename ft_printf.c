/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:56:20 by algaboya          #+#    #+#             */
/*   Updated: 2024/02/24 20:48:19 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_put_char(const char c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	va_start(args, str);
	i = 0;
	while (i < ft_strlen((char *)str))
	{
		if (str[i++] == '%')
		{
			if (str[i] == 'c')
				ft_put_char(va_arg(args, unsigned int));
			// else if (str[i] == 's')
			// 	ft_put_str(va_arg(args, char *));
			// else if (str[i] == 'p' || str[i] == 'x')
			// 	ft_put_str(va_arg(args, size_t));
			// else if (str[i] == 'd' || str[i] == 'i')
			// 	ft_put_nbr(va_arg(args, int));
			// else if (str[i] == 'u')
			// 	ft_put_nbr(va_arg(args, unsigned int));
			// else if (str[i] == 'X')
			// 	ft_put_up_hex(va_arg(args, size_t));
			// else if (str[i] == '%')
			// 	ft_put_char('%');
		}
		else
			ft_put_char(str[i]);
		i++;
	}
	va_end(args);
	return (0);
}

int	ft_put_str(char *ptr)
{
	while (ptr)
	{
		ft_put_char(*ptr);
		ptr++;
	}
	return (ft_strlen(ptr));
}

int	main()
{
	// printf("sjacvh asj	gccbyuv %c d", 'l');
	// printf("###");
	ft_printf("sjacvh asjgccbyuv %c d", 'l');
	return (0);
}