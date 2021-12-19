#include"minitalk.h"
#include<stdio.h>

 void    send_signal(int pid, int signum)
 {
     if(kill(pid , signum)== -1)
         exit(EXIT_FAILURE);
 }

void	signal_handler(int signum, siginfo_t *info, void *context)
{
    
	static char	c = 0xFF;
	static int	bit = 0;
	static int	pid = 0;
	static char	*message ;
	(void)context;
	if ((info)->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
    	c |= 0x80 >> bit;
    else if (signum == SIGUSR2)
        c ^= 0x80 >> bit;
    if (++bit == 9)
    {
        if (!c)
			send_signal(pid, SIGUSR1);
		write(1,&c,1);
        bit = 0;
	    c = 0xFF;
    }
}

int main (void)
{
struct sigaction sig;
int pid;

sig.sa_flags = SA_SIGINFO;
sig.sa_sigaction = signal_handler;
sigaction(SIGUSR1, &sig, NULL);
sigaction(SIGUSR2, &sig, NULL);
pid = getpid();
printf("-------  hak l PID  khoud mat7chemch : %d  ----------------\n" , pid);
while (1)
    pause();
}