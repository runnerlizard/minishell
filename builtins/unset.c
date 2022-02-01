/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:47:33 by mjeanett          #+#    #+#             */
/*   Updated: 2022/01/29 15:17:02 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strar_size(char **ar)
{
	int	i;

	i = 0;
	if (!ar)
		return (0);
	while (ar[i])
		i++;
	return (i);
}

int	ft_strar_index(char **ar, const char *str, const char *sep)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		if (ft_strncmp(ar[i], str, ft_strlen(str)) == 0)
		{
			if (!(ar[i][ft_strlen(str)])
				|| ft_strchr(sep, ar[i][ft_strlen(str)]))
				return (i);
		}
		i++;
	}
	if (str == NULL)
		return (i);
	return (-1);
}

void	ft_strar_free(char **ar)
{
	int	i;

	i = 0;
	if (!ar)
		return ;
	while (ar[i])
		free (ar[i++]);
	free (ar);
}

void	del_entry(int i)
{
	char	**ar;
	int		j;
	int		k;

	j = 0;
	k = 0;
	ar = (char **)ft_calloc(ft_strar_size(&g_global.env), sizeof(char *));
	while (j < ft_strar_size(&g_global.env))
	{
		if (j != i)
			ar[k++] = ft_strdup(&g_global.env[j]);
		j++;
	}
	ft_strar_free(&g_global.env);
	g_global.env = *ar;
}

void	ft_unset(char **args)
{
	int	i;
	int	j;

	i = 0;
	g_global.exit_status = SUCCESS;
	while (args[i])
	{
		if (ft_isdigit(args[i][0]) || ft_count_char(args[i], NAMESETTING) \
			!= (int)ft_strlen(args[i]))
			print_builtin_error("unset", args[i], NTV_IDENT);
		else if (ft_strar_index(&g_global.env, args[i], "=") >= 0)
		{
			j = ft_strar_index(&g_global.env, args[i], "=");
			del_entry(j);
		}
		i++;
	}
}
