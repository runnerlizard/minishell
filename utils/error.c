/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:09:46 by sbronwyn          #+#    #+#             */
/*   Updated: 2022/01/29 14:46:22 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_builtin_error(char *builtin, char *prefix, char *message)
{
	ft_putstr_fd(MINISHELL_ERROR_PREFIX, 2);
	if (builtin != NULL)
	{
		ft_putstr_fd(builtin, 2);
		ft_putstr_fd(": ", 2);
	}
	if (prefix != NULL)
	{
		ft_putstr_fd(prefix, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}

void	print_error(char *prefix, char *message)
{
	print_builtin_error(NULL, prefix, message);
}

void	print_n_exit(char *message)
{
	print_error(NULL, message);
	free_global();
	exit(g_global.exit_status);
}

void	strerror_n_exit(char *prefix)
{
	print_error(prefix, strerror(errno));
	free_global();
	exit(g_global.exit_status);
}
