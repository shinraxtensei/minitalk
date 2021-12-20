/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:57:40 by ahouari           #+#    #+#             */
/*   Updated: 2021/12/20 15:58:35 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include"ft_printf/ft_printf.h"

int		ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char c);
void	send_signal(int pid, int signum);
void	signal_handler(int signum, siginfo_t *info, void *context);
void	send_bits(int pid, char *message);
int		ft_isdigit(int c);
int		str_isdigit(char *str);
void	signal_handler_c(int signum);

#endif
