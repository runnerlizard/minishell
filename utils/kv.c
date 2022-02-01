/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:56:00 by sbronwyn          #+#    #+#             */
/*   Updated: 2022/01/29 14:46:50 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_kv	*create_kv(const char *name, const char *value)
{
	t_kv	*kv;

	kv = xmalloc(sizeof(*kv));
	kv->name = ft_strdup(name);
	kv->value = ft_strdup(value);
	return (kv);
}

void	free_kv(t_kv *kv)
{
	if (kv == NULL)
		return ;
	if (kv->name != NULL)
		free(kv->name);
	if (kv->value != NULL)
		free(kv->value);
	free(kv);
}
