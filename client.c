#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

int	main(int argc, char **argv)
{
	int bitcount;
	int pid;
	int i;

	i = 0;
	bitcount = 7;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			while (bitcount >= 0)
		        {
                		if (argv[2][i] & 1)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				argv[2][i] = argv[2][i] >> 1;
                		bitcount--;
				usleep(20);
        		}
			bitcount = 7;
			i++;
		}
	}
}
