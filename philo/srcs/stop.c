/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:10:08 by salimon           #+#    #+#             */
/*   Updated: 2022/09/04 07:59:25 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// à placer probablement avant join pour check la death en continu ou bien créer un thread dédié ?
int check_death(t_datas *datas)
{
    int i;
    long long ms;

    while (!(datas->dining_end))
    {
        i = 0;
        while (i < datas->philo_nb)
        {
            //check time to die
            if ((datas->philos[i].last_meal - get_time()) > datas->t_t_die) //mutex ?
            {
                ms = get_time() - datas->timestamp;
                print_log(datas->philos, ms, i + 1, "died");
                datas->dining_end = 1;
                break;
            }
            //check nb de meals (check ici ou dans routine ?)
            if (datas->meal_nb != -1 && datas->philos[i].meal_count >= datas->philos[i].datas->meal_nb)
            {
                datas->dining_end = 1;
                break;
            }
            i++;
        }
    }
    return (1);
}