/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoarau <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:26:21 by rohoarau          #+#    #+#             */
/*   Updated: 2021/12/21 14:33:06 by rohoarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_recursive_power(int nb, int power)
{
	if (power == 0 && nb == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, (power - 1)));
}

void	signal_handler(int sig)
{
	static int	bit = 7;
	static char	c;

	if (sig == SIGUSR1)
		c += ft_recursive_power(2, bit);
	else if (sig == SIGUSR2)
		;
	bit--;
	if (bit == -1)
	{
		ft_printf("%c", c);
		bit = 7;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
