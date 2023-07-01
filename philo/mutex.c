/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:12:55 by ntardy            #+#    #+#             */
/*   Updated: 2023/06/27 14:43:04 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_mutex_destr(t_data *data)
{
	int	i;

	i = 0;
	while (i < MAX_MUTEX)
		pthread_mutex_destroy(&data->mutex[i++]);
}

int	ft_mutex_id_dead(t_data *data, int change, int new_id_philo_dead)
{
	int	id_dead;

	pthread_mutex_lock(&data->mutex[ID_PHILO_DEAD]);
	if (change == 1)
		data->id_philo_dead = new_id_philo_dead;
	else
		(void)new_id_philo_dead;
	id_dead = data->id_philo_dead;
	pthread_mutex_unlock(&data->mutex[ID_PHILO_DEAD]);
	return (id_dead);
}

int	ft_mutex_all_eat(t_data *data)
{
	int	all_eat;

	pthread_mutex_lock(&data->mutex[ALL_EAT]);
	all_eat = data->all_eat;
	pthread_mutex_unlock(&data->mutex[ALL_EAT]);
	return (all_eat);
}

struct timeval	ft_mutex_start_time(t_data *data, int id, int change)
{
	struct timeval	start_time;

	pthread_mutex_lock(&data->list_philos[id].mutex_time);
	if (change == 1)
		gettimeofday(&data->list_philos[id].start_time, NULL);
	start_time = data->list_philos[id].start_time;
	pthread_mutex_unlock(&data->list_philos[id].mutex_time);
	return (start_time);
}
