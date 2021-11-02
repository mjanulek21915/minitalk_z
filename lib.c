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

void	do_exit(void)
{
	exit(0);
}

unsigned int	ft_atoi(char *str)
{
	unsigned long int	rst;

	rst = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		rst = rst * 10;
		rst = rst + *str - '0';
		str++;
		if (rst > UINT_MAX)
			return (0);
	}
	return ((unsigned int)rst);
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

void	ft_send_signal(pid_t pid, int sig)
{
	if (kill(pid, sig))
	{
		do_exit();
	}
}
