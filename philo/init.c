/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:06:53 by ntardy            #+#    #+#             */
/*   Updated: 2023/06/27 11:58:41 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_arg(t_arguments *arg)
{
	arg->nbr_must_eat = -1;
	arg->nbr_philo = 0;
	arg->time_to_die = 0;
	arg->time_to_eat = 0;
	arg->time_to_sleep = 0;
}

int	ft_init_data(t_data *data)
{
	ft_init_arg(&data->arg);
	data->list_fork = NULL;
	data->list_philos = NULL;
	data->threads_philos = NULL;
	data->list_philos_initialised = 0;
	data->id_philo_dead = 0;
	data->all_eat = 0;
	if (pthread_mutex_init(&data->glob_mutex, NULL) != 0)
		return (ft_error("mutex_init KO !", data));
	return (0);
}

int	ft_init_mutex(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < MAX_MUTEX)
	{
		if (pthread_mutex_init(&data->mutex[i], NULL) != 0)
		{
			while (j < i)
				pthread_mutex_destroy(&data->mutex[j++]);
			return (ft_error("mutex_init KO !", data));
		}
		i++;
	}
	return (0);
}
