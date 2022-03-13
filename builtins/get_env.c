/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:56:02 by mjeanett          #+#    #+#             */
/*   Updated: 2022/03/09 11:56:03 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// char	*place_env3(char *name, char **env)
// {
// 	char *tmp_env;

// 	while (env.split[++(env.i) + 1])
// 	{
// 		env.tmp = ft_strjoin_triple(env.ret, env.split[env.i], " ");
// 		free (env.ret);
// 		env.ret = ft_strdup(env.tmp);
// 		free (env.tmp);
// 	}
// 	env.tmp = ft_strjoin(env.ret, env.split[env.i]);
// 	free (env.ret);
// 	env.ret = ft_strdup(env.tmp);
// 	free (env.tmp);
// 	if (ft_strlen(env.env) > 0 && env.env[ft_strlen(env.env) - 1] == ' '
// 		&& (token->cmd[env.j] || token->over == 1))
// 	{
// 		env.tmp = ft_strjoin(env.ret, " ");
// 		free (env.ret);
// 		env.ret = ft_strdup(env.tmp);
// 		free (env.tmp);
// 	}
// 	free (env.env);
// 	ft_strarr_free(env.split);
// 	return (env.ret);
// }

// char	*place_env2(char *var, t_type type, t_token *token, int j)
// {
// 	t_env	env;

// 	env.i = -1;
// 	env.j = j;
// 	if (ft_getenv(var) == NULL)
// 		return (NULL);
// 	env.env = ft_strdup(ft_getenv(var));
// 	if (type == "")
// 		return (env.env);
// 	if (ft_strcmp(env.env, "") == 0)
// 		env.split = split_null();
// 	else
// 		env.split = ft_split(env.env, ' ');
// 	env.ret = ft_strdup("");
// 	if (env.env[0] == ' ' && env.j > 2
// 		&& ft_strlen(token->cmd) != ft_strlen(var) + 1)
// 	{
// 		env.tmp = ft_strjoin(env.ret, " ");
// 		free (env.ret);
// 		env.ret = ft_strdup(env.tmp);
// 		free (env.tmp);
// 	}
// 	return (place_env3(token, env));
// }

void	ft_addenv(const char *name, const char *value, int equal, char **env)
{
	char	*str;
	char 	**new_env;

	new_env = ft_strarr_dup(env, 1);
	ft_strarr_free(env);
	env = new_env;
	env[ft_strarr_size(env)] = ft_strdup(name);
	if (equal)
	{
		str = ft_strjoin_triple(name, "=", value);
		free (env[ft_strarr_size(env) - 1]);
		env[ft_strarr_size(env) - 1] = ft_strdup(str);
		free (str);
	}
}

int	ft_setenv(const char *name, const char *value, int equal, char **env)
{
	int		i;

	if (name == NULL || ft_strlen(name) == 0 || ft_strchr(name, '='))
		return (-1);
	if (ft_getenv(name, env) && equal == 0)
		return (0);
	if (ft_getenv(name, env) == NULL)
	{
		ft_addenv(name, value, equal, env);
		return (0);
	}
	i = ft_strarr_index(env, name, "=");
	if (equal)
	{
		free (env[i]);
		env[i] = ft_strjoin_triple(name, "=", value);
	}
	return (0);
}

char	*ft_getenv(const char *name, char **env)
{
	int		i;
	char	*str;
	size_t	size;

	i = 0;
	str = ft_strjoin(name, "=");
	size = ft_strlen(str);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], str, size) == 0)
		{
			free (str);
			return (env[i] + size);
		}
		if (ft_strncmp(env[i], name, size) == 0)
		{
			free (str);
			return (env[i] + (size - 1));
		}
		i++;
	}
	free (str);
	return (NULL);
}
