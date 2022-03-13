/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:13:12 by mjeanett          #+#    #+#             */
/*   Updated: 2022/03/11 18:59:09 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// some comments:
// leaks has been checked - no leaks
// works with my main

void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1))
		return ;
}

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while ((ptr1[i] || ptr2[i]) && i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

void	ft_echo(char **args) 
{	
	int	i;
	int	newline;

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
	exit_status = 1;
}
