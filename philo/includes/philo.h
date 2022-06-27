/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:20:36 by salimon           #+#    #+#             */
/*   Updated: 2022/06/27 13:45:08 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct	s_philosopher
{
	pthread_t	id;
	pthread_mutex_t	left_fork;
	pthread_mutex_t right_fork;
	pthread_mutex_t meal;

}				t_philosopher;

typedef struct s_datas
{
	int				philo_nb;
	t_philosopher	philosopher[500];
	int				sleep_time;
	int				eat_time;
	int				death_time;
	int				meal_nb;
	double			timestamp;
}				t_datas;

int error_management(t_datas *datas, unsigned int error_code);
int	ft_atoi(const char *nb);

#endif
