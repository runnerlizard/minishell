/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:32:49 by mjeanett          #+#    #+#             */
/*   Updated: 2022/01/29 15:13:44 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(void)
{
	char	pwd[PATH_MAX];

	g_global.exit_status = SUCCESS;
	if (getcwd(pwd, PATH_MAX) == NULL)
	{
		print_builtin_error("pwd", NULL, NULL);
		return ;
	}
	ft_putendl_fd(pwd, 1);
}
