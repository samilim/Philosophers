/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:02:24 by salimon           #+#    #+#             */
/*   Updated: 2022/07/15 02:27:53 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

long int	get_time()
{
	struct timeval current_time;
	
	gettimeofday(&current_time, NULL);
	printf("seconds : %ld\nmicroseconds : %ld\n", current_time.tv_sec, current_time.tv_usec);
	return (0);
}

void	print_logs(t_datas *datas, int philo, char *message)
{
	pthread_mutex_lock(&datas->logs);
	/*voir condition print ; ne pas print si philo mort?*/
	printf("%lld %d %s\n", datas->timestamp, philo, message);
	pthread_mutex_unlock(&datas->logs);
}