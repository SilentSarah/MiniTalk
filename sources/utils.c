/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:08:09 by hmeftah           #+#    #+#             */
/*   Updated: 2022/12/07 11:35:58 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_pow(int base, int exponent)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (i < exponent)
	{
		res *= base;
		i++;
	}
	return (res);
}
