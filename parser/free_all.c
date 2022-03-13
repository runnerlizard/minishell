/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluco <cluco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:37:22 by Cluco             #+#    #+#             */
/*   Updated: 2022/03/11 17:06:32 by cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*free_all(t_cmd *c, char *s, char *message)
{
	int	i;
	int	j;

	if (message != NULL)
		perror(message);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '1')
		{
			j = c->count - 1;
			while (j >= 0)
				free(c->cmd[j--]);
			free(c->cmd);
		}
		else if (s[i] == '4')
			free(c);
		else if (s[i] == '6')
		 	unlink("clucomjeanettmpfile");
		else if (s[i] == '7')
			free(c->path);
		else if (s[i] == '8')
			free(c->type);
		else if (s[i] == '9')
		{
			j = -1;
			while (c->e[++j] != NULL)
				free(c->e[j]);
			free(c->e);
		}
		else if (s[i] == '0')
		{
			unlink("clucoheredoc");
			exit(errno);
		}
	}
	return (NULL);
}