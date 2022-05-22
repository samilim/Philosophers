/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:34:41 by salimon           #+#    #+#             */
/*   Updated: 2021/01/12 18:29:54 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd(nb % 10 + '0', fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}
