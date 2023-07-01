/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:42:02 by ntardy            #+#    #+#             */
/*   Updated: 2023/06/03 19:05:36 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(char *error, t_data *data)
{
	ft_putstr("Error, ", 2);
	ft_putstr(error, 2);
	ft_putchar('\n', 2);
	ft_free(data);
	return (1);
}
