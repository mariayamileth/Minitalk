/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:40:01 by maricont          #+#    #+#             */
/*   Updated: 2023/07/02 21:10:33 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_put_nro(int n)
{
	if (n > 9)
	{
		ft_put_nro(n / 10);
		n = n % 10;
	}
	if (n <= 9)
		ft_putchar(n + '0');
}

void	ft_conv_bin(int senal)
{
	static char	bit;
	static int	i = 7;

	if (senal == SIGUSR1)
		bit = bit | (1 << i);
	i--;
	if (i < 0)
	{
		write (1, &bit, 1);
		bit = 0;
		i = 7;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "El PID es : ", 12);
	ft_put_nro(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_conv_bin);
	signal(SIGUSR2, ft_conv_bin);
	while (1)
		pause();
	return (0);
}
