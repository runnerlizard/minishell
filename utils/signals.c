/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluco <cluco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:03:10 by mjeanett          #+#    #+#             */
/*   Updated: 2022/03/09 18:25:25 by cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ctrl_d(void)
{
	ft_putendl_fd("Exit", 2);
	free_variables();
	exit(exit_status);
}

void	ctrl_c(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	exit_status = 130;
}

void	manage_signals(int status)
{
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			ft_putendl_fd("^C", 1);
		if (WTERMSIG(status) == SIGQUIT)
			ft_putendl_fd("Quit", 1);
	}
	set_signals();
}

void	do_nothing(int sig)
{
	(void)sig;
}

void	parent_process(t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == 0)
		execute(cmd->cmd, cmd);
	waitpid(pid, &status, 0);
	manage_signals(status);
}

// void	ms_start_exec(t_cmd *cmd)
// {
// 	signal(SIGINT, do_nothing);
// 	signal(SIGQUIT, do_nothing);
// 	if (cmd->cmd == NULL)
// 	{
// 		//how works redirections??? should be initialization of redirection
// 		if (!exit_status) //check error
// 			return ;
// 		if (cmd->cmd && cmd->cmd[0])
// 			if (!is_builtin(cmd))
// 				parent_process(cmd);
// 		dup2(cmd->infile, 0);
// 		dup2(cmd->outfile, 1);
// 	}
// 	else
// 		handle_pipe(c, i);
// }