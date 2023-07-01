/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:06:50 by ntardy            #+#    #+#             */
/*   Updated: 2023/06/27 14:42:06 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_parsing_arg(char **args, t_data *data)
{
	int	i;
	int	atoi_arg;

	i = 0;
	while (args[++i])
	{
		atoi_arg = ft_atoi(args[i]);
		if (atoi_arg == -1 || atoi_arg == 0)
			return (ft_error("enter valid arguments (positive integers)"
					, data));
		ft_fill_arg(i, &data->arg, atoi_arg);
	}
	if (data->arg.nbr_philo > 200)
		return (ft_error("use less than 201 philosophers", data));
	if (data->arg.time_to_die < 60 || data->arg.time_to_eat < 60
		|| data->arg.time_to_sleep < 60)
		return (ft_error("use more than 60 ms for time_to_die/eat/sleep"
				, data));
	return (0);
}
