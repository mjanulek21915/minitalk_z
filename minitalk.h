/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:11:04 by mjanulek          #+#    #+#             */
/*   Updated: 2021/10/18 15:11:04 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>

# define PID_MAX	99998

pid_t				ft_atoi(char *str);
void				ft_write_pid(pid_t nbr);
int					ft_set_signal(pid_t pid, int mode);
void				ft_send_signal(pid_t pid, int sig);
void				ft_write(char c);
void				do_exit(void);

#endif
