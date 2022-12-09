/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:16:16 by hmeftah           #+#    #+#             */
/*   Updated: 2022/12/09 13:27:54 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	decode(int *arr)
{
	int				i;
	unsigned char	c;
	int				res;

	res = 0;
	i = 0;
	while (i < 8)
	{
		res += arr[i] << i;
		i++;
	}
	c = (unsigned char)res;
	return (c);
}

void	signal_handler(int signum, siginfo_t *ptr, void *test)
{
	static int	i;
	static int	arr[8];

	(void)test;
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		if (signum == SIGUSR1)
			arr[i++] = 0;
		else if (signum == SIGUSR2)
			arr[i++] = 1;
		if (i % 8 == 0)
		{
			i = 0;
			ft_printf("%c", decode(arr));
			ft_bzero(arr, 8);
			kill(ptr->si_pid, SIGUSR1);
		}
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Proccess ID is: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
