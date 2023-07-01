/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:35:05 by ntardy            #+#    #+#             */
/*   Updated: 2023/06/27 14:41:17 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parsing_init(t_data *data, char **argv)
{
	if (ft_init_data(data) != 0)
		return (1);
	if (ft_parsing_arg(argv, data) != 0)
		return (1);
	if (ft_init_mutex(data) != 0)
		return (1);
	return (0);
}

void	clean(t_data *data)
{
	if (data->id_philo_dead != 0)
	{
		ft_log(data, data->id_philo_dead, "died");
		ft_mutex_destr(data);
		ft_free(data);
	}
	else
	{
		ft_mutex_destr(data);
		ft_free(data);
	}
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	check_thread;

	if (argc < 5 || argc > 6)
		return (ft_putstr("Error, wrong number of arguments\n", 2), 1);
	if (parsing_init(&data, argv) == 1)
		return (1);
	if (pthread_create(&check_thread, NULL, ft_check_philosophers
			, (void *)&data) != 0)
	{
		ft_error("failed to create thread", &data);
		return (1);
	}
	if (ft_fill_philos_and_fork(&data) == 1)
		return (1);
	if (pthread_join(check_thread, NULL) != 0)
	{
		ft_error("failed to join check thread", &data);
		return (1);
	}
	clean(&data);
	return (0);
}
