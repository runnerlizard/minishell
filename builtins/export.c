/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:55:51 by mjeanett          #+#    #+#             */
/*   Updated: 2022/03/10 12:27:42 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	delete_entry(int i, char **env)
{
	char	**arr;
	int		j;
	int		k;

	j = 0;
	k = 0;
	arr = (char **)ft_calloc(ft_strarr_size(env), sizeof(char *));
	while (j < ft_strarr_size(env))
	{
		if (j != i)
			arr[k++] = ft_strdup(env[j]);
		j++;
	}
	ft_strarr_free(env);
	env = arr;
}

void	reset_env(char **name, int equal, char **env)
{
	int	i;

	printf("reset_env");
	i = ft_strarr_index(env, name[0], "=");
	delete_entry(i, env);
	ft_setenv(name[0], "", equal, env);
}

static void	verify_name(char **argv, char **env)
{
	int		i;
	char	**name;
	int		equal;

	i = 0;
	while (argv[++i])
	{
		equal = 1;
		if (!ft_strchr(argv[i], '='))
			equal = 0;
		name = ft_split(argv[i], '=');
		if (ft_isdigit(name[0][0]) || ft_count_char(name[0], NAMESETTING) \
			!= (int)ft_strlen(name[0]))
			print_builtin_error("export", argv[i], "not a valid identifier");
		else
		{
			if (ft_getenv(name[0], env) && ft_strchr(argv[i], '=') && !name[1])
				reset_env(name, equal, env);
			else if (name[1] != NULL)
				ft_setenv(name[0], argv[i] + ft_strlen(name[0]) + 1, equal, env);
			else
				ft_setenv(name[0], "", equal, env);
		}
		ft_strarr_free(name);
	}
}

void	ft_export(char **args, char **env)
{
	char	**sort;
	int		i;

	i = -1;
	exit_status = 1;
	if (!args[1])
	{
		sort = ft_strarr_dup(env, 0);
		ft_strarr_sort(sort, ft_strarr_size(env));
		while (sort[++i])
			ft_putendl_fd(sort[i], 1);
		ft_strarr_free(sort);
	}
	else
	{
		printf("ver_name");
		verify_name(args, env);
	}
}