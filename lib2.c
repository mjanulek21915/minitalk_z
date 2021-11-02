/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2021/10/18 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_set_signal(pid_t pid, int mode)
{
	static pid_t	comm_id = 0;

	if (mode)
		comm_id = pid;
	return (comm_id);
}

void	ft_send_signal(pid_t pid, int sig)
{
	if (kill(pid, sig))
	{
		do_exit();
	}
}

void	ft_write(char c)
{
	if ((write(1, &c, 1)) < 0)
	{
		do_exit();
	}
}

void	do_exit(void)
{
	exit(0);
}
