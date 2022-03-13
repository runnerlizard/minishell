/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluco <cluco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:32:49 by mjeanett          #+#    #+#             */
/*   Updated: 2022/03/09 18:25:25 by cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(void)
{
	char	pwd[1024];

	exit_status = 1;
	if (getcwd(pwd, 1024) == NULL)
	{
		print_builtin_error("pwd", NULL, strerror(errno));
		return ;
	}
	ft_putendl_fd(pwd, 1);
}
