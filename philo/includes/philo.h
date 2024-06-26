/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:20:36 by salimon           #+#    #+#             */
/*   Updated: 2023/03/23 04:34:00 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
les int des forks correspondent aux emplacement
des fourchettes dans mon tableau de forks
*/
typedef struct s_philosopher
{
	pthread_t		id;
	int				position;
	int				left_fork;
	int				right_fork;
	int				meal_count;
	long long		meal_time;
	long long		last_meal;
	struct s_datas	*datas;
}				t_philosopher;

/*
timestamp : tmps de départ
meal_nb : fifth argument (nb max of meal)
*/
typedef struct s_datas
{
	int				philo_nb;
	int				t_t_sleep;
	int				t_t_eat;
	int				t_t_die;
	int				meal_nb;
	int				dining_end;
	int				dead;
	long long		timestamp;
	pthread_mutex_t	*forks;
	pthread_mutex_t	logs;
	pthread_mutex_t	meal;
	t_philosopher	*philos;
}				t_datas;

int			error_management(t_datas *datas, unsigned int error_code);
int			parsing(t_datas *datas, int argc, char **argv);
int			ft_atoi(const char *nb);
long long	get_time(void);
void		print_log(
				t_philosopher *philo, int id, char *message);
int			eat(t_philosopher *philo);
void		ft_clear(t_datas *datas);
int			smart_sleep(t_datas *datas, long long ms);
int			check_dining_state(t_datas *datas);
int			check_digits(int argc, char **argv);
int			one_philo_case(t_philosopher *philo);

#endif
