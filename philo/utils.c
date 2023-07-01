/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:47:10 by ntardy            #+#    #+#             */
/*   Updated: 2023/06/27 14:43:31 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static inline long	__get_time(void)
{
	struct timeval	actual;
	long			time;

	gettimeofday(&actual, NULL);
	time = actual.tv_sec * 1000;
	time += actual.tv_usec / 1000;
	return (time);
}

long	ft_start_time(void)
{
	return (__get_time());
}

void	ft_log(t_data *data, int id, char *action)
{
	pthread_mutex_lock(&data->glob_mutex);
	printf("%ld %d %s\n", (__get_time() - data->start_time), id, action);
	pthread_mutex_unlock(&data->glob_mutex);
}

void	ft_chronos(int time, t_philo *philo)
{
	long const	target = __get_time() + time;

	while (__get_time() < target)
	{
		pthread_mutex_lock(&philo->mutex_dead);
		if (philo->dead == 1)
		{
			pthread_mutex_unlock(&philo->mutex_dead);
			return ;
		}
		pthread_mutex_unlock(&philo->mutex_dead);
		usleep(125);
	}
}
