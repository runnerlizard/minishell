/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:34:31 by sbronwyn          #+#    #+#             */
/*   Updated: 2022/01/29 15:12:39 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtin(char **args)
{
	if (ft_strcmp(args[0], "echo") == 0
		|| ft_strcmp(args[0], "pwd") == 0
		|| ft_strcmp(args[0], "cd") == 0
		|| ft_strcmp(args[0], "export") == 0
		|| ft_strcmp(args[0], "unset") == 0
		|| ft_strcmp(args[0], "unset") == 0
		|| ft_strcmp(args[0], "env") == 0
		|| ft_strcmp(args[0], "exit") == 0)
		return (1);
	return (0);
}

void	run_builtin(char **args)
{
	if (ft_strcmp(args[0], "echo") == 0)
		ft_putstr_fd("echo ...\n", 1);
	else if (ft_strcmp(args[0], "pwd") == 0)
		ft_putstr_fd("some pwd ...\n", 1);
	// else if (ft_strcmp(args[0], "cd") == 0)
	// else if (ft_strcmp(args[0], "export") == 0)
	// else if (ft_strcmp(args[0], "unset") == 0)
	// else if (ft_strcmp(args[0], "env") == 0)
	// else if (ft_strcmp(args[0], "exit") == 0)
	return ;
}
