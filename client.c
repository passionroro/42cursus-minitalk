/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:14:28 by rohoarau          #+#    #+#             */
/*   Updated: 2021/12/21 14:33:07 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' \
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}

void	ft_itob(unsigned char nb, int pid, int d)
{
	if (d < 7)
		ft_itob(nb / 2, pid, d + 1);
	if ((int)nb % 2 == 1)
		kill(pid, SIGUSR1);
	if ((int)nb % 2 == 0)
		kill(pid, SIGUSR2);
	usleep(60);
}

void	bit_converter(char *str, int pid)
{
	int	i;
	int	d;

	i = 0;
	while (str[i])
	{
		d = 0;
		ft_itob(str[i], pid, d);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		bit_converter(argv[2], pid);
	}
	return (0);
}
