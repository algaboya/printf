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

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_put_char(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_str(char *ptr)
{
	while (*ptr != '\0')
	{
		ft_put_char(*ptr);
		ptr++;
	}
	return (ft_strlen(ptr));
}

static long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_put_nbr(int n)
{
	int		i;
	long	nbr;
	char	buf[10];

	if (n == 0)
	{
		write (1, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
	}
	nbr = ft_abs(n);
	i = 10;
	while (nbr != 0 && i > 0)
	{
		i--;
		buf[i] = nbr % 10 + '0';
		nbr /= 10;
	}
	write(1, &buf[i], 10 - i);
}

void	ft_put_nbr_unsigned(int n)
{
	int		i;
	char	buf[10];

	if (n == 0)
	{
		write (1, "0", 1);
		return ;
	}
	i = 10;
	while (n != 0 && i > 0)
	{
		i--;
		buf[i] = n % 10 + '0';
		n /= 10;
	}
	write(1, &buf[i], 10 - i);
}

int ft_put_low_hex(size_t nbr)
{
	int		i;
	long	rm;
	char	buff[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	char	new_buff[16];

	i = 16;
	while (nbr != 0 && i > 0)
	{
		i--;
		rm = nbr % 16;
		new_buff[i] = buff[rm];
		nbr /= 16;
	}
	write(1, &new_buff[i], 16 - i);
}

int ft_put_up_hex(size_t nbr)
{
	int		i;
	long	rm;
	char	buff[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	char	new_buff[16];

	i = 16;
	while (nbr != 0 && i > 0)
	{
		i--;
		rm = nbr % 16;
		new_buff[i] = buff[rm];
		nbr /= 16;
	}
	write(1, &new_buff[i], 16 - i);
}

int	ft_put_ptr(unsigned long long ptr)
{
	int	res;

	res = 0;
	res += ft_put_str("0x");
	res += ft_put_low_hex(ptr);
	return (res);
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
			// else if (str[i + 1] == '%')
			//   ft_put_char('%');
			i++;
		}
		else
			ft_put_char(str[i]);
		i++;
	}
	va_end(args);
	return (0);
}


int main()
{
	// char *ptr = "hell jhvo";
	// printf("sjacvh asjgccbyuv %p d %c d", ptr, 's');
	// ft_put_low_hex(5131);

	printf("\n###\n");
	int i = 45;
	int *ptr = &i;
	// printf("%p", ptr);
	// printf("\n###\n");
	ft_printf("sjacvh asjgccbyuv % d %c d", , 's');
	// ft_printf("%p", ptr);
	// printf("\n###\n");
	return (0);
}
