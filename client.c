/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:43:22 by hmeftah           #+#    #+#             */
/*   Updated: 2022/12/10 11:25:50 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	encoder(int pid, char *argv)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (argv[i])
	{
		j = 0;
		c = argv[i];
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

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("ERROR: LACK OF ARGUMENTS");
		exit(1);
	}
	encoder(ft_atoi(argv[1]), argv[2]);
	return (0);
}
