/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:20:36 by salimon           #+#    #+#             */
/*   Updated: 2022/06/23 12:40:58 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct	s_philosopher
{
	int	left_fork;
	int right_fork;

}				t_philosopher;

typedef struct s_datas
{
	t_philosopher	philosopher[200];
	int				philo_nb;
	int				sleep_time;
	int				eat_time;
	int				death_time;
	int				meal_nb;
}				t_datas;

int error_management(t_datas *datas, unsigned int error_code);

#endif
