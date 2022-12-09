/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:57:07 by hmeftah           #+#    #+#             */
/*   Updated: 2022/12/09 15:57:10 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	decode(int *arr)
{
	int				i;
	unsigned char	c;
	int				res;

	res = 0;
	i = 7;
	while (i >= 0)
	{
		res += (arr[i] * ft_pow(2, i));
		i--;
	}
	c = (unsigned char)res;
	return (c);
}

void	signal_handler(int signum)
{
	static int	i;
	static int	arr[8];

	if (signum == SIGUSR1)
		arr[i++] = 0;
	else if (signum == SIGUSR2)
		arr[i++] = 1;
	else
		kill(getpid(), SIGINT);
	if (i == 8)
	{
		i = 0;
		ft_printf("%c", decode(arr));
		ft_bzero(arr, 8);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Proccess ID is: %d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}
