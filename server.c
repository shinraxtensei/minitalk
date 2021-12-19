#include"minitalk.h"
#include<stdio.h>




void    send_signal(int pid, int signum)
{
    if(kill(pid , signum)== -1)
        exit(EXIT_FAILURE);
}

/*void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xff;
	static int	bit = 0;
	int	pid ;
	//static char	*message = 0;

	(void)context;
	if ((info)->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
    {
		c |= 0x80 >> bit;
        printf("sigusr1");
    }
    else if (signum == SIGUSR2)
    {
		c ^= 0x80 >> bit;
        printf("sigusr2");
    }
    if(++bit == 8)
        printf("%d",c);
	bit = 0;
	c = 0xff;
	send_signal(pid, SIGUSR1);
}*/

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bit = 0;
	static int	pid = 0;
	static char	*message = 0;

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
	     {
		 	printf("%s\n",message);
		 	send_signal(pid, SIGUSR2);
		 }
		 else
		message = ft_str_add_char(message, c);
		printf ("%c",c);
        bit = 0;
		c = 0xFF;
	}
	send_signal(pid, SIGUSR1);
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