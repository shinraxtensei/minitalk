#include"minitalk.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
size_t	ft_strlen(const char *str)
{
	int len = 0 ;
	while (str[len])
		len++;
	return(len);
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	res;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + *str - '0';
		str++;
	}
	if (res <= 2147483648)
		return (res * sign);
	if (res >= 2147483648 && sign > 0)
		return (-1);
	return (0);
}


