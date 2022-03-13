/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluco <cluco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:52:38 by cluco             #+#    #+#             */
/*   Updated: 2022/03/11 18:22:56 by cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_built(t_cmd *c, char **ex)
{
	int	i;
	
	run_builtin(ex, c->e);
	i = 0;
	while (ex[i] != NULL)
		free(ex[i++]);
	free(ex);
	// free_all(c, "19846", NULL);
}

static void	launch_single_cmd(t_cmd *c)
{
	char	**ex;
	pid_t	pid;

	ex = redirects_cut_off(c->cmd[0], c);
	if (is_builtin(ex) == 0)
	{
		pid = fork();
		if (pid < 0)
			return ;
		else if (pid == 0)
			run_execve(c, ex);
		else
			if (waitpid(pid, &exit_status, 0) < 0)
				return ;
	}
	else
		run_built(c, ex);
}

static void	launch_multiple(t_cmd *c)
{
	int	i;

	i = -1;
	while (c->count > ++i)
	{
		if (c->count > 1 && i < c->count - 1 && c->type[i] == '|')
		{
			if (i % 2 == 0 && (pipe(c->fd1)))
				free_all(c, "19840", "pipe 1");
			if (i % 2 == 1 && (pipe(c->fd2)))
				free_all(c, "19840", "pipe 2");
		}
		run_cmd(c, i);
	}
}

void	launcher(t_cmd *c)
{
	if (c->count == 1)
		launch_single_cmd(c);
	else
		launch_multiple(c);
	unlink("clucoheredoc");
}
