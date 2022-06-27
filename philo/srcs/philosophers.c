/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:22:30 by salimon           #+#    #+#             */
/*   Updated: 2022/06/27 13:53:25 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int    takes_arguments(t_datas *datas, int argc, char **argv)
{
    datas->philo_nb = ft_atoi(argv[1]);
    datas->death_time = ft_atoi(argv[2]);
    datas->eat_time = ft_atoi(argv[3]);
    datas->sleep_time = ft_atoi(argv[4]);
    if (datas->philo_nb < 2 || datas->death_time < 0 || datas->eat_time < 0 || datas->sleep_time < 0)
        return (0);
    if (argc == 6)
    {
        datas->meal_nb = ft_atoi(argv[5]);
        if (datas->meal_nb <= 0)
            return (0);
    }
    else
        datas->meal_nb = -1;
    return (1);
}

/*
Cette fonction sera appelée pour chaque thread créé
*/
void    *routine_philo(t_datas *datas)
{
    /*mange, dors et pense*/
    pthread_mutex_lock(&datas->philosopher->left_fork);
    pthread_mutex_lock(&datas->philosopher->right_fork);
    printf("init philo\n");
    usleep(3);
    printf("ending thread\n");
    /*modification des valeurs*/
    pthread_mutex_unlock(&datas->philosopher->left_fork);
    pthread_mutex_unlock(&datas->philosopher->right_fork);
    return (NULL);
}

/*
pthread_create créé un thread pour chaque philosopher
pthread_join agit comme un wait
 sert à protéger les threads en cas d'erreur sir create pthread != 0
*/
int init_philosophers(t_datas *datas)
{
    int i;

    i = 0;
    while (i < datas->philo_nb)
    {
        if (pthread_create(&datas->philosopher[i].id, NULL, &routine_philo, NULL/*datas*//*arg de routine*/) != 0)
                return (0);
        i++;
    }
    //pthread_detach(datas->philosopher[i].id);
    i = 0;
    while (i < datas->philo_nb)
    {
        if (pthread_join(datas->philosopher[i].id, NULL) != 0)
            return (0);
        i++;
    }
    return (1);
}

int init_mutex(t_datas *datas)
{
    pthread_mutex_t mutex;
    
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_destroy(&mutex);
}

int main(int argc, char **argv)
{
    t_datas datas;
    
    //memset();
    if (argc != 5 && argc != 6)
        return (error_management(&datas, 1));
    if (!(takes_arguments(&datas, argc, argv)))
        return (error_management(&datas, 2));
    if (!(init_philosophers(&datas)))
        return (error_management(&datas, 3));
    //init philo thread and mutex on forks
    return (0);
}