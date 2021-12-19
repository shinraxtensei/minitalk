#ifndef MINITALK_H
# define MINITALK_H


# include <sys/types.h>
# include <signal.h>
#include<unistd.h>
#include"ft_printf/ft_printf.h"

int	    ft_atoi(const char *str);
char    *ft_strjoin(char *s1, char c);
void    send_signal(int pid, int signum);
void    signal_handler(int signum, siginfo_t *info, void *context);
void    send_bits(int pid,char *message);
int	    ft_isdigit(int c);
char	*ft_str_add_char(char *str, char c);
void	signal_handler_c(int signum);

#endif