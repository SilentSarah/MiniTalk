/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:57:07 by hmeftah           #+#    #+#             */
/*   Updated: 2022/12/10 20:15:59 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_server_data;

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

static void	check_client(int *bit_index, int *arr, siginfo_t *ptr)
{
	if (g_server_data.c_pid == 0)
		g_server_data.c_pid = ptr->si_pid;
	else if (g_server_data.c_pid != ptr->si_pid)
	{	
		*bit_index = 0;
		ft_bzero(arr, 8);
		g_server_data.c_pid = ptr->si_pid;
	}
	return ;
}

void	signal_handler(int signum, siginfo_t *ptr, void *context)
{
	static int	i;
	static int	arr[8];

	(void)context;
	check_client(&i, arr, ptr);
	if (signum == SIGUSR1)
		arr[i++] = 0;
	else if (signum == SIGUSR2)
		arr[i++] = 1;
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

	sa.sa_sigaction = &signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Proccess ID is: %d\n", getpid());
	g_server_data.c_pid = 0;
	while (1)
		pause();
	return (0);
}
