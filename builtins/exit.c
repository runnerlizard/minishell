/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:55:43 by mjeanett          #+#    #+#             */
/*   Updated: 2022/03/09 20:15:01 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//no leaks - works fine
// int	ft_isdigit(int c)
// {
// 	return (c >= '0' && c <= '9');
// }

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

// int	ft_putstr_fd(char *s, int fd)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (i);
// 	while (s[i] != '\0')
// 	{
// 		ft_putchar_fd(s[i], fd);
// 		i++;
// 	}
// 	return (i);
// }

// void	ft_putendl_fd(char *s, int fd)
// {
// 	if (!s)
// 		return ;
// 	ft_putstr_fd(s, fd);
// 	ft_putchar_fd('\n', fd);
// }

// void	print_builtin_error(char *builtin, char *prefix, char *message)
// {
// 	ft_putstr_fd("minishell: ", 2);
// 	if (builtin != NULL)
// 	{
// 		ft_putstr_fd(builtin, 2);
// 		ft_putstr_fd(": ", 2);
// 	}
// 	if (prefix != NULL)
// 	{
// 		ft_putstr_fd(prefix, 2);
// 		ft_putstr_fd(": ", 2);
// 	}
// 	ft_putstr_fd(message, 2);
// 	ft_putstr_fd("\n", 2);
// }

long int	ft_atoi_64(const char *str)
{
	long int	res;
	long int	sign;

	res = 0;
	sign = 1;
	while ((str[0] >= 9 && str[0] <= 13) || str[0] == 32)
		str++;
	if (str[0] == '-')
		sign = sign * -1;
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (str[0] >= '0' && str[0] <= '9')
	{
		res = (res * 10) + str[0] - '0';
		str++;
	}
	return (res * sign);
}

int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_limits(char *str)
{
	int			sign;
	long int	num;

	sign = 1;
	if (str[0] == '-')
		sign = -1;
	num = ft_atoi_64(str);
	if ((num < 0 && sign == 1) || (num >= 0 && sign == -1))
		return (1);
	return (0);
}

void	ft_exit(char **cmd, char **env)
{
	ft_putendl_fd("exit", 1);
	if (!cmd[1])
		exit_status = 1;
	else if (!is_number(cmd[1]) || check_limits(cmd[1]))
	{
		exit_status = 255;
		print_builtin_error("exit", cmd[1], "numeric argument is requiered");
	}
	else if (cmd[2])
	{
		print_builtin_error("exit", NULL, "too many arguments");
		return ;
	}
	// else if (check_limits(cmd[1]))
	// 	print_n_exit("exit");
	else
		exit_status = ft_atoi_64(cmd[1]) % 256;
	ft_strarr_free(env);
	ft_strarr_free(cmd);
	clear_history();
	exit(exit_status);
}