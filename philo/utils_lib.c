/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:46:46 by ntardy            #+#    #+#             */
/*   Updated: 2023/06/18 19:47:06 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putchar(char c, int out)
{
	write(out, &c, 1);
}

void	ft_putstr(char *str, int out)
{
	int	i;

	i = 0;
	while (str && str[i])
		ft_putchar(str[i++], out);
}

int	ft_atoi(char *nbr)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!nbr || (nbr[i] < '0' && nbr[i] > '9'))
		return (-1);
	while (nbr[i] >= '0' && nbr[i] <= '9')
		res = res * 10 + (nbr[i++] - 48);
	if (nbr[i])
		return (-1);
	return (res);
}
