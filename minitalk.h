/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:06:45 by hmeftah           #+#    #+#             */
/*   Updated: 2022/12/10 17:18:08 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_pow(int base, int exponent);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_printf(const char *format, ...);
int		ft_putadress(void *ptr);
int		ft_putbase_fd(unsigned int n);
int		ft_putbase_fd_lower(unsigned int n);
int		ft_putchar_fd(char c);
int		ft_putnbr_fd_unsigned(unsigned int n);
int		ft_putnbr_fd(int n);
int		ft_putstr_fd(char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);

typedef struct server_data {
	int		data_sent;
	int		data_recieved;
	int		c_pid;
}	t_data;
#endif