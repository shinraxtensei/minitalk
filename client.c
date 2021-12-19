
#include"minitalk.h"
#include<stdio.h>


// void	signal_handler_c(int signum)
// {
// 	if (signum == SIGUSR1)
// 	{
// 		printf("->Message sent \n");
// 	}
// }

void    send_bits(int pid, char *message)
{
    int i;
    int bit;

    bit = -1;
    i = 0;
    if(!message)
        exit(EXIT_FAILURE);
    while (1)
    {
        bit = -1;
        while (++bit < 8)
        {
            if(message[i] & (128 >> bit))
            {
                if(kill(pid,SIGUSR1) == -1)
                    exit(1);
            }
            else if(kill(pid , SIGUSR2) == -1)
                exit(1);
            usleep(100);
        }
        if(!message[i])
            break;
        ++i;
    }
}


int main (int ac , char **av)
{
    int pid;
    if(ac != 3)
    {
       printf("Invalid arguments \n"); 
        exit(EXIT_FAILURE);
    }
    //signal(SIGUSR1, signal_handler_c);
	//signal(SIGUSR2, signal_handler_c);
    pid = ft_atoi(av[1]);
    send_bits(pid,av[2]);
}