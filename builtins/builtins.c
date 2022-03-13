/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:22:36 by cluco             #+#    #+#             */
/*   Updated: 2022/03/11 19:01:37 by mjeanett         ###   ########.fr       */
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

void	run_builtin(char **cmd, char **env)
{
	if (ft_strcmp("exit", cmd[0]) == 0)
		ft_exit(cmd, env);
	else if (ft_strcmp("export", cmd[0]) == 0)
		ft_export(cmd, env);
	else if (ft_strcmp("echo", cmd[0]) == 0)
		ft_echo(cmd);
	else if (ft_strcmp("cd", cmd[0]) == 0)
		ft_cd(cmd, env);
	else if (ft_strcmp("unset", cmd[0]) == 0)
		ft_unset(cmd+1, env);
	else if (ft_strcmp("pwd", cmd[0]) == 0)
		ft_pwd();
	else
		ft_env(cmd, env);
	return ;
}
