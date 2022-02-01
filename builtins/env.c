/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:27:40 by mjeanett          #+#    #+#             */
/*   Updated: 2022/01/29 15:14:52 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(char **args)
{
	int	i;

	g_global.exit_status = SUCCESS;
	if (args[1])
	{
		print_builtin_error("env", NULL, ARGS_ERR);
		return ;
	}
	i = -1;
	while (g_global.env[++i])
		if (ft_strchr(&g_global.env[i], '='))
			ft_putendl_fd(&g_global.env[i], 1);
}
