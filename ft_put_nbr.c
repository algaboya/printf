/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:55:44 by algaboya          #+#    #+#             */
/*   Updated: 2024/02/26 20:57:57 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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