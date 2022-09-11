/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:20:36 by salimon           #+#    #+#             */
/*   Updated: 2022/09/10 15:47:58 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

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

typedef struct	s_philosopher
{
	pthread_t		id;
	int				position;
	int				left_fork;
	int				right_fork;
	int				meal_count;
	long long		last_meal;
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
	/*flags*/
	int				death;
	int				dining_end;
	
	long long		timestamp; /*temps de départ*/
	/*mutexes*/
	pthread_mutex_t	*forks;
	pthread_mutex_t	logs;
	pthread_mutex_t meal;
	t_philosopher	*philos;
}				t_datas;

int 		error_management(t_datas *datas, unsigned int error_code);
int			ft_atoi(const char *nb);
long long	get_time();
void		print_log(t_philosopher *philo, long long ms, int id, char *message);
void   		eat(t_philosopher *philo);
int			check_death(t_datas *datas);
void		ft_clear(t_datas *datas);

#endif
