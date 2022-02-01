/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:34:35 by sbronwyn          #+#    #+#             */
/*   Updated: 2022/01/29 14:52:57 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_global(void)
{
	g_global.env = NULL;
	g_global.exit_status = SUCCESS;
}

void	free_global(void)
{
	if (g_global.env != NULL)
	{
		free(g_global.env);
	}
	if (g_global.exit_status != 0)
	{
		g_global.exit_status = 0;
	}
	return ;
}
