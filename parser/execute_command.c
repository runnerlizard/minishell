/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cluco <cluco@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:21:53 by mjeanett          #+#    #+#             */
/*   Updated: 2022/02/01 13:09:04 by Cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_command(char *command)
{
	//if (is_builtin(command) == 1)
		//run_builtin(command);
	// else
	ft_putstr_fd(command, 1);
	ft_putstr_fd("\n", 1);
}
