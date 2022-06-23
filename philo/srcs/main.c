/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:22:30 by salimon           #+#    #+#             */
/*   Updated: 2022/06/23 12:41:12 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* Add une focntion pour afficher aide ? */

int    init_datas(t_datas *datas, int argc, char **argv)
{
    datas->philo_nb = ft_atoi(argv[1]);
    datas->death_time = ft_atoi(argv[2]);
    datas->eat_time = ft_atoi(argv[3]);
    datas->sleep_time = ft_atoi(argv[4]);
    if (argc == 6)
    {
        datas->meal_nb = ft_atoi(argv[5]);
        if (datas->meal_nb <= 0)
            return (0);
    }
    else
        datas->meal_nb = -1;
    if (datas->philo_nb < 2 || datas->death_time < 0 || datas->eat_time < 0 || datas->sleep_time < 0 /*|| datas->philo_nb invalid*/)
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    t_datas datas;
    
    //memset();
    if (argc != 5 || argc != 6)
        return (error_management(&datas, 1));
    if (!(init_datas(&datas, argc, argv)))
        return (error_management(&datas, 2));
    //init philo thread and mutex on forks
    return (0);
}