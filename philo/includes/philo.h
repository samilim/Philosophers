/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:20:36 by salimon           #+#    #+#             */
/*   Updated: 2022/07/06 17:23:33 by salimon          ###   ########.fr       */
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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct	s_philosopher
{
	int				position;
	pthread_t		id;
	int				left_fork;
	int				right_fork;
	pthread_mutex_t meal;

}				t_philosopher;

typedef struct s_datas
{
	int				philo_nb;
	t_philosopher	*philos;
	pthread_mutex_t	*forks;
	int				t_t_sleep;
	int				t_t_eat;
	int				t_t_die;
	int				is_eating;
	int				meal_nb;
	int				death;
	long			time;
}				t_datas;

int error_management(t_datas *datas, unsigned int error_code);
int	ft_atoi(const char *nb);

#endif
