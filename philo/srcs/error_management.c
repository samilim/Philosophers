/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:14:22 by salimon           #+#    #+#             */
/*   Updated: 2022/06/27 10:33:05 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int error_management(t_datas *datas, unsigned int error_code)
{
	if (error_code == 1)
		write(STDERR_FILENO, "Invalid number of argument\n", 28);
	if (error_code == 2)
		write(STDERR_FILENO, "Invalid argument(s)\n", 18);
	if (error_code == 3)
		write (STDERR_FILENO, "Error during thread processing\n", 32);
		
	datas->philosopher->left_fork = 1;
	return (0);
}