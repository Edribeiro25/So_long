/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:12:48 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/08 13:12:52 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s + i != NULL && s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar_fd('-', fd);
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + 48, fd);
	}
	else
		ft_putchar_fd(((nb % 10) + 48), fd);
}
