/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:43:22 by hmeftah           #+#    #+#             */
/*   Updated: 2022/12/09 15:51:03 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	*g_server_data;

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
		i++;
	}
}

void	handler(int signum)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
		usleep(1);
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
	g_server_data = malloc(sizeof(t_data) * 1);
	if (!g_server_data)
		return (1);
	g_server_data->string = (char *)malloc(sizeof(char *)
			* ft_strlen(argv[2]) + 1);
	if (!g_server_data->string)
		return (1);
	ft_strlcpy(g_server_data->string, argv[2], ft_strlen(argv[2]) + 1);
	g_server_data->server_pid = ft_atoi(argv[1]);
	encoder(g_server_data->server_pid, g_server_data->string);
	free(g_server_data->string);
	free(g_server_data);
	return (0);
}
