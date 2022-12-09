/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:43:22 by hmeftah           #+#    #+#             */
/*   Updated: 2022/12/09 16:36:55 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data g_server_data;

static void	encoder(int pid, char *string)
{
	int				i;
	static int		j;
	char			c;

	i = 0;
	while (string[i])
	{
		j = 0;
		c = string[i];
		while (j < 8)
		{
			if (c & (1 << j))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			j++;
		}
		g_server_data.data_sent++;
		i++;
	}
}

void	handler(int signum)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
		g_server_data.data_recieved++;
}

int	main(int argc, char **argv)
{
	struct sigaction	client;

	sigemptyset(&client.sa_mask);
	client.sa_handler = &handler;
	client.sa_flags = 0;
	sigaction(SIGUSR1, &client, NULL);
	sigaction(SIGUSR2, &client, NULL);
	if (argc != 3)
	{
		ft_printf("ERROR: LACK OF ARGUMENTS");
		exit(1);
	}
	encoder(ft_atoi(argv[1]), argv[2]);
	if (g_server_data.data_recieved == g_server_data.data_sent)
		ft_printf("Message has been sent successfully");
	else
		ft_printf("Error: Something lost in transmission");
	return (0);
}
