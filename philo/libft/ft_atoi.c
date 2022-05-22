/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:47:16 by salimon           #+#    #+#             */
/*   Updated: 2021/12/12 03:29:11 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nb)
{
	unsigned int	i;
	int				signe;
	int				nmb;

	signe = 1;
	i = 0;
	nmb = 0;
	while (nb[i] == ' ' || (nb[i] >= 8 && nb[i] <= 13))
		i++;
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			signe *= -1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
		nmb = nmb * 10 + nb[i++] - '0';
	return (nmb * signe);
}
