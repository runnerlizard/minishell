/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cluco <cluco@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:13:12 by mjeanett          #+#    #+#             */
/*   Updated: 2022/02/02 13:38:04 by Cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strchr_rev(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str != (char)c)
			return (str);
		str++;
	}
	if (c == 0)
		return (str);
	return (NULL);
}

void	ft_echo_util(char **args, int i)
{
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		i++;
		if (!args[i])
			break ;
		ft_putchar_fd(' ', 1);
	}
}

void	ft_echo(char **args, int fd1, int fd2)
{
	int	i;
	int tmpfd;
	int	newline;

	tmpfd = dup(1);
	if (fd1 > 0)
		dup2(fd1, 0);
	if (fd2 > 0)
		dup2(fd2, 1);
	i = 1;
	newline = 1;
	while (args[i] && ft_strncmp("-n", args[i], 2) == 0)
	{
		if (ft_strchr_rev(args[i] + 1, 'n') != NULL)
			break ;
		newline = 0;
		i++;
	}
	ft_echo_util(args, i);
	if (newline)
		ft_putchar_fd('\n', 1);
	dup2(tmpfd, 1);
	g_global.exit_status = SUCCESS;
}
