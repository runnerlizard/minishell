/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:06:17 by sbronwyn          #+#    #+#             */
/*   Updated: 2022/01/29 14:46:37 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*xmalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		strerror_n_exit(NULL);
	}
	return (ptr);
}
