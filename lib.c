/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2021/10/18 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



pid_t	ft_atoi(char *str)
{
	unsigned long long	rst;
	rst = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		if ((rst == ULLONG_MAX / 10) && (*str > '5'))
			return (0);
		rst = rst * 10;
		rst = rst + *str - '0';
		str++;
		if (rst > PID_MAX)
			return (0);
	}
	return ((pid_t)rst);
}

static void	ft_write_pid_rec(pid_t nbr)
{
	char	c;

	if (nbr / 10)
	{
		ft_write_pid_rec(nbr / 10);
		c = (char)(nbr % 10) + '0';
		ft_write(c);
	}
	else if (nbr % 10)
	{
		c = ((char)(nbr) % 10) + '0';
		ft_write(c);
	}
}

void	ft_write_pid(pid_t nbr)
{
	if (nbr)
		ft_write_pid_rec(nbr);
	else
		ft_write('0');
}


