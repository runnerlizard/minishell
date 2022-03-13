/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluco <cluco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:41:55 by cluco             #+#    #+#             */
/*   Updated: 2022/03/11 18:31:04 by cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	path_to_struct(pid_t pid, t_cmd *c, char **ex)
{
	int	tmp_fd;
	
	if (waitpid(pid, NULL, 0) < 0)
		free_all(c, "198460", strerror(errno));
	c->path = xmalloc(100);
	tmp_fd = open("clucomjeanettmpfile", O_RDONLY);
	if (tmp_fd < 0)
		free_all(c, "1978460", strerror(errno));
	tmp_fd = read(tmp_fd, c->path, 100);
	if (tmp_fd < 1)
	{
		c->path = ex[0];
		unlink("clucomjeanettmpfile");
		return ;
	}
	tmp_fd = 0;
	while (c->path[tmp_fd] != '\n')
		tmp_fd++;
	c->path[tmp_fd] = 0;
	unlink("clucomjeanettmpfile");
}

static void	get_path(t_cmd *c, char **ex)
{
	int		tmp_fd;
	pid_t	pid;
	char	*args[3];
	
	pid = fork();
	if (pid == 0)
	{
		args[0] = "which";
		args[1] = ex[0];
		args[2] = NULL;
		tmp_fd = open("clucomjeanettmpfile", O_TRUNC | O_CREAT | O_RDWR, 0664);
		if (tmp_fd < 0 || dup2(tmp_fd, 1) < 0)
			free_all(c, "19840", strerror(errno));
		execve("/usr/bin/which", args, c->e);
		free_all(c, "198640", strerror(errno));
	}
	else if (pid > 0)
		path_to_struct(pid, c, ex);
	else
		free_all(c, "19840", strerror(errno));
}

void	run_execve(t_cmd *c, char **ex)
{
	int	i;

	get_path(c, ex);
	unlink("clucoheredoc");
	execve(c->path, ex, c->e);
	free_all(c, "19846", "execve");
	i = 0;
	while (ex[i] != NULL)
		free(ex[i++]);
	free(ex);
	exit (0);
}