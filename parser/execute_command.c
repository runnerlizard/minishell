/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:21:53 by mjeanett          #+#    #+#             */
/*   Updated: 2022/01/29 14:48:32 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

void	execute_command(char *command)
{
	ft_putstr_fd(command, 1);
	ft_putstr_fd("\n", 1);
}
