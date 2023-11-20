/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:39:17 by maricont          #+#    #+#             */
/*   Updated: 2023/07/02 21:11:11 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_itoa(char *str)
{
	int	i;
	int	n;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = str[i] - '0' + (n * 10);
		i++;
	}
	return (n);
}

int	ft_bin(int pid_server, char *str)
{
	int		i;
	int		j;
	char	bit;
	char	c;

	i = 0;
	bit = 0;
	while (str[i])
	{
		c = str[i];
		j = 7;
		while (j >= 0)
		{
			if (c & (1 << j))
				kill(pid_server, SIGUSR1);
			else
				kill(pid_server, SIGUSR2);
			usleep(100);
			j--;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	pid_server;

	if (argc == 3)
	{
		pid_server = ft_itoa(argv[1]);
		ft_bin(pid_server, argv[2]);
	}
	else
	{
		write (1, "Error - Colocar PID y Mensaje", 29);
		return (-1);
	}
	return (0);
}
