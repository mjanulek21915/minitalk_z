/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2021/10/18 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_listen(int sig, siginfo_t *info, void *context)
{
	static int	pos = 0;
	static char	rst = 0;

	ft_set_signal(info->si_pid, 1);
	if (sig == SIGUSR1)
	{
		rst = rst << 1;
	}
	else if (sig == SIGUSR2)
	{
		rst = rst << 1;
		rst = rst + 1;
	}
	pos++;
	if (pos == 8)
	{
		ft_write(rst);
		pos = 0;
		rst = 0;
	}
	context = context;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_listen;
	if ((sigemptyset(&sa.sa_mask)))
		return (0);
	if ((sigaddset(&sa.sa_mask, SIGUSR1))
		|| (sigaddset(&sa.sa_mask, SIGUSR2)))
		return (0);
	if ((sigaction(SIGUSR1, &sa, NULL)) || (sigaction(SIGUSR2, &sa, NULL)))
		return (0);
	ft_write_pid(getpid());
	while (1)
	{
		pause();
		ft_send_signal(ft_set_signal(0, 0), SIGUSR1);
	}
	ac = ac;
	av = av;
}
