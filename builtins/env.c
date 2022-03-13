/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluco <cluco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:27:40 by mjeanett          #+#    #+#             */
/*   Updated: 2022/03/09 18:25:25 by cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(char **cmd, char **env)
{
	int	i;

	i = -1;
	exit_status = 1;
	if (cmd[1])
	{
		print_builtin_error("env", NULL, "too many arguments");
		return ;
	}
	while (env[++i])
	{
		ft_putstr_fd(env[i], 1);
		ft_putstr_fd("\n", 1);
	}
	return ;
}
