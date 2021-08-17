#include "minitalk.h"

int	g_count;
int	g_binary[8];

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int	powertwo(int bin)
{
	int result;

	result = 1;
	while (bin-- > 0)
		result = result * 2;
	return (result);
}

void	todecimal()
{
	int i;
	int decimal;

	i = 0;
	decimal = 0;
	while (i < 8)
	{
		if (g_binary[i])
			decimal += powertwo(7 - i);
		i++;
	}
	ft_putchar(decimal);
}

void	handler(int sig)
{
	if (sig == 10)
		g_binary[g_count] = 1;
	else
		g_binary[g_count] = 0;
	if (g_count == 0)
	{
		todecimal();
		g_count = 7;
	}
	else
		g_count--;
}

int main()
{
	g_count = 7;
	ft_putchar('P');
	ft_putchar('I');
	ft_putchar('D');
	ft_putchar(':');
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
}
