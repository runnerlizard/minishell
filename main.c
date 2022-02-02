/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cluco <cluco@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:45:55 by sbronwyn          #+#    #+#             */
/*   Updated: 2022/02/02 13:25:03 by Cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	*tmp[2];
	
	tmp[0] = "echo";
	tmp[1] = "dsfhksdf";

	(void) argc;
	(void) argv;
	(void) envp;
	int fd2 = open("ardfkldf", O_TRUNC | O_CREAT | O_WRONLY, 0664);
	ft_echo(tmp, -1, fd2);
	init_global();
	while (1)
	{
		line = readline(MINISHELL_PROMPT);
		rl_redisplay();
		if (line != NULL)
		{
			execute_command(line);
			free(line);
		}
	}
	free_global();
	return (g_global.exit_status);
}
