/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:30:40 by mjeanett          #+#    #+#             */
/*   Updated: 2022/01/29 14:48:41 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_count_char(const char *s, const char *set)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	if (!s || !set)
		return (0);
	while (s[i])
	{
		j = 0;
		while (set[j])
			if (s[i] == set[j++])
				count++;
		i++;
	}
	return (count);
}
