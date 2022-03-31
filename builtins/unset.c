/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizard <lizard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:47:33 by mjeanett          #+#    #+#             */
/*   Updated: 2022/03/21 19:41:18 by lizard           ###   ########.fr       */
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

	(void) sep;
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

void	del_entry(int i, char **env)
{
	char	**ar;
	int		j;
	int		k;

	j = 0;
	k = 0;
	ar = (char **)calloc(ft_strar_size(env), sizeof(char *));
	while (j < ft_strar_size(env))
	{
		if (j != i)
			ar[k++] = ft_strdup(env[j]);
		j++;
	}
	// ft_strar_free(env);
	while (k >= 0)
	{
		env[k] = ar[k];
		k--;
	}
}

void	ft_unset(char **args, char **env)
{
	int	i;
	int	j;

	i = 0;
	exit_status = 1;
	while (args[i])
	{
		if (ft_isdigit(args[i][0]) || ft_count_char(args[i], NAMESETTING) \
			!= (int)ft_strlen(args[i]))
			print_builtin_error("unset", args[i], "not a valid identifier");
		else if (ft_strar_index(env, args[i], "=") >= 0)
		{
			j = ft_strar_index(env, args[i], "=");
			del_entry(j, env);
		}
		i++;
	}
}
