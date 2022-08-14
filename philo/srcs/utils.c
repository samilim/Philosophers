/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:02:24 by salimon           #+#    #+#             */
/*   Updated: 2022/08/14 09:41:26 by salimon          ###   ########.fr       */
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

long long	get_time()
{
	struct timeval current_time;
	
	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	print_log(t_philosopher *philo, long long ms, int id, char *message)
{
	(void)philo;
	pthread_mutex_lock(&philo->datas->logs);
	/*voir condition print ; ne pas print si philo mort?*/
	printf("%lldms %d %s\n", ms, id, message);
	pthread_mutex_unlock(&philo->datas->logs);
}