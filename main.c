/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:45:55 by sbronwyn          #+#    #+#             */
/*   Updated: 2022/01/27 19:22:27 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void) argc;
	(void) argv;
	(void) envp;
	init_global();
	while (1)
	{
		line = readline(MINISHELL_PROMPT);
		if (line != NULL)
		{
			execute_command(line);
			free(line);
		}
	}
	free_global();
	return (g_global.exit_status);
}
