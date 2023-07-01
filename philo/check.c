/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:55:05 by ntardy            #+#    #+#             */
/*   Updated: 2023/06/27 13:57:58 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_eat(t_data *data)
{
	int				i;

	i = 0;
	while (i < data->arg.nbr_philo)
	{
		pthread_mutex_lock(&data->mutex[NB_EAT]);
		if (data->list_philos[i].nb_eat < data->arg.nbr_must_eat)
		{
			pthread_mutex_unlock(&data->mutex[NB_EAT]);
			break ;
		}
		pthread_mutex_unlock(&data->mutex[NB_EAT]);
		i++;
	}
	if (i == data->arg.nbr_philo)
	{
		pthread_mutex_lock(&data->mutex[ALL_EAT]);
		data->all_eat = 1;
		pthread_mutex_unlock(&data->mutex[ALL_EAT]);
		return (1);
	}
	return (0);
}

void	philo_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->arg.nbr_philo)
	{
		pthread_mutex_lock(&data->list_philos[i].mutex_dead);
		data->list_philos[i].dead = 1;
		pthread_mutex_unlock(&data->list_philos[i++].mutex_dead);
	}
}

int	new_time_to_die(t_data *data)
{
	int				time_to_die;

	if (data->arg.time_to_eat + data->arg.time_to_sleep
		<= data->arg.time_to_die)
		time_to_die = data->arg.time_to_die + 3;
	else
		time_to_die = data->arg.time_to_die;
	return (time_to_die);
}

int	ft_check_die(t_data *data)
{
	int				i;
	struct timeval	actual;
	int				elapsed;

	i = 0;
	while (i < data->arg.nbr_philo)
	{
		gettimeofday(&actual, NULL);
		elapsed = (actual.tv_sec
				- ft_mutex_start_time(data, i, 0).tv_sec) * 1000;
		elapsed = elapsed
			+ ((actual.tv_usec - ft_mutex_start_time(data, i, 0).tv_usec)
				/ 1000);
		if (elapsed >= new_time_to_die(data))
		{
			philo_dead(data);
			ft_mutex_id_dead(data, 1, i + 1);
			break ;
		}
		i++;
	}
	return (ft_mutex_id_dead(data, 0, 0));
}

void	*ft_check_philosophers(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		usleep(1000);
		pthread_mutex_lock(&data->glob_mutex);
		if (data->list_philos_initialised == 1)
		{
			if (data->arg.nbr_must_eat != -1 && ft_check_eat(data) != 0)
				return (pthread_mutex_unlock(&data->glob_mutex), NULL);
			if (ft_check_die(data) != 0)
				return (pthread_mutex_unlock(&data->glob_mutex), NULL);
		}
		pthread_mutex_unlock(&data->glob_mutex);
	}
	return (NULL);
}
