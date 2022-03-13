/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluco <cluco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:11:57 by cluco             #+#    #+#             */
/*   Updated: 2022/03/10 14:11:44 by cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

static char **init_env(char **env)
{
	int		i;
	char	**e;

	i = 0;
	while (env[i])
		i++;
	e = xmalloc(sizeof(char *) * ++i);
	i = -1;
	while (env[++i])
		e[i] = ft_strdup(env[i]);
	e[i] = NULL;
	return (e);
}

static int	only_tabs(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == 10 || s[i] == 32 || s[i] == 11)
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	char	*line;
	char	*nl;
	char	**e;

	(void) argv;
	exit_status = 0;
	e = init_env(env);
	while (argc >= 0)
	{
		line = readline("minishell$ ");
		rl_redisplay();
		if (ft_strlen(line) > 0 && only_tabs(line) == 0)
		{
			add_history(line);
			nl = replace_var(line, env);
			free(line);
			parse_execute(nl, e);
			free(nl);
		}
		else
			free(line);
	}
	return (0);
}
