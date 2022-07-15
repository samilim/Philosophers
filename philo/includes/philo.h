/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:20:36 by salimon           #+#    #+#             */
/*   Updated: 2022/07/15 02:28:00 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct	s_philosopher
{
	pthread_t		id;
	int				position;
	int				left_fork;
	int				right_fork;
	pthread_mutex_t meal;
	struct s_datas	*datas;
}				t_philosopher;

typedef struct s_datas
{
	int				philo_nb;
	int				t_t_sleep;
	int				t_t_eat;
	int				t_t_die;
	int				is_eating; //mutex?
	int				meal_nb;
	int				death;
	long int		timestamp;
	pthread_mutex_t	*forks;
	pthread_mutex_t	logs;
	t_philosopher	*philos;
}				t_datas;

int error_management(t_datas *datas, unsigned int error_code);
int	ft_atoi(const char *nb);
long int	get_time();

#endif
