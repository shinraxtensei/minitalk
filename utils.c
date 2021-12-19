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

char	*ft_strjoin(char *s1, char c)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	i = -1;
	j = 0;
	s1_len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (s1_len + 1 + 1));
	if (dest == NULL)
		return (NULL);
	while (++i < s1_len)
		dest[i] = s1[i];
	while (j <= s2_len)
		dest[i++] = c;
	free(s1);
	return (dest);
}


char	*ft_str_add_char(char *str, char c)
{
	char	*add;
	int		i;

	if (!c)
		return (NULL);
	if (!str)
		return (NULL);
	add = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!add)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		add[i] = str[i];
	free(str);
	add[i++] = c;
	add[i] = '\0';
	return (add);
}