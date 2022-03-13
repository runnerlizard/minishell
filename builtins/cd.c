/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluco <cluco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:55:30 by mjeanett          #+#    #+#             */
/*   Updated: 2022/03/09 18:25:25 by cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//no leaks - works fine

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int	result;
// 	int	i;

// 	result = 0;
// 	i = -1;
// 	while (s1[++i] != '\0' && s2[i] != '\0')
// 	{
// 		if (s1[i] == s2[i])
// 			continue ;
// 		if (s1[i] > s2[i])
// 			return (1);
// 		if (s1[i] < s2[i])
// 			return (-1);
// 	}
// 	if (s1[i] == '\0' && s2[i] == '\0')
// 		return (result);
// 	if (s1[i] > s2[i])
// 		return (1);
// 	return (-1);
// }

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

// void	ft_strarr_free(char **arr)
// {
// 	int	i;

// 	i = 0;
// 	if (!arr)
// 		return ;
// 	while (arr[i])
// 		free (arr[i++]);
// 	free (arr);
// }

// char	**ft_strarr_dup(char **arr, int size_plus)
// {
// 	char	**dup;
// 	int		i;

// 	i = 0;
// 	if (arr)
// 		while (arr[i])
// 			i++;
// 	dup = (char **)ft_calloc((i + 1 + size_plus), sizeof(char *));
// 	if (!dup)
// 		return (NULL);
// 	i = 0;
// 	if (arr)
// 	{
// 		while (arr[i])
// 		{
// 			dup[i] = ft_strdup(arr[i]);
// 			i++;
// 		}
// 	}
// 	return (dup);
// }

// int	ft_strarr_size(char **arr)
// {
// 	int	i;

// 	i = 0;
// 	if (!arr)
// 		return (0);
// 	while (arr[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin_triple(const char *s1, const char *s2, const char *s3)
// {
// 	size_t	size;
// 	char	*str;
// 	int		i;
// 	int		j;

// 	if (s1 && s2 && s3)
// 	{
// 		size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
// 		str = (char *)ft_calloc((size + 1), sizeof(char));
// 		if (!str)
// 			return (NULL);
// 		j = 0;
// 		i = 0;
// 		while (s1[i])
// 			str[j++] = s1[i++];
// 		i = 0;
// 		while (s2[i])
// 			str[j++] = s2[i++];
// 		i = 0;
// 		while (s3[i])
// 			str[j++] = s3[i++];
// 		return (str);
// 	}
// 	return (NULL);
// }

// int	ft_strarr_index(char **arr, const char *str, const char *sep)
// {
// 	int	i;

// 	i = 0;
// 	while (arr[i])
// 	{
// 		if (ft_strncmp(arr[i], str, ft_strlen(str)) == 0)
// 		{
// 			if (!(arr[i][ft_strlen(str)])
// 				|| ft_strchr(sep, arr[i][ft_strlen(str)]))
// 				return (i);
// 		}
// 		i++;
// 	}
// 	if (str == NULL)
// 		return (i);
// 	return (-1);
// }

// void	ft_strarr_sort(char **arr, int size)
// {
// 	int		i;
// 	int		j;
// 	char	*tmp1;
// 	char	*tmp2;

// 	i = 0;
// 	while (i < size - 1)
// 	{
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			if (ft_strcmp(arr[i], arr[j]) > 0)
// 			{
// 				tmp1 = ft_strdup(arr[i]);
// 				tmp2 = ft_strdup(arr[j]);
// 				free (arr[i]);
// 				free (arr[j]);
// 				arr[i] = tmp2;
// 				arr[j] = tmp1;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	ft_putstr_fd(char *s, int fd)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (i);
// 	while (s[i] != '\0')
// 	{
// 		ft_putchar_fd(s[i], fd);
// 		i++;
// 	}
// 	return (i);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if ((char)c == '\0')
// 		return ((char *)(s + ft_strlen(s)));
// 	if (!s || !c)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)(s + i));
// 		i++;
// 	}
// 	return (NULL);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	i = 0;
// 	j = 0;
// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j] != '\0')
// 	{
// 		str[i + j] = s2[j];
// 		j++;
// 	}
// 	str[i + j] = '\0';
// 	return (str);
// }

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	unsigned char	*ptr1;
// 	unsigned char	*ptr2;
// 	size_t			i;

// 	ptr1 = (unsigned char *)s1;
// 	ptr2 = (unsigned char *)s2;
// 	i = 0;
// 	while ((ptr1[i] || ptr2[i]) && i < n)
// 	{
// 		if (ptr1[i] != ptr2[i])
// 			return (ptr1[i] - ptr2[i]);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_strdup(const char *s1)
// {
// 	char	*tmp;
// 	size_t	i;

// 	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
// 	if (!tmp)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		tmp[i] = s1[i];
// 		i++;
// 	}
// 	tmp[i] = s1[i];
// 	return (tmp);
// }

// void	ft_addenv(const char *name, const char *value, int equal, char **env)
// {
// 	char	*str;
// 	char 	**new_env;

// 	new_env = ft_strarr_dup(env, 1);
// 	ft_strarr_free(env);
// 	env = new_env;
// 	env[ft_strarr_size(env)] = ft_strdup(name);
// 	if (equal)
// 	{
// 		str = ft_strjoin_triple(name, "=", value);
// 		free (env[ft_strarr_size(env) - 1]);
// 		env[ft_strarr_size(env) - 1] = ft_strdup(str);
// 		free (str);
// 	}
// }

// char	*ft_getenv(const char *name, char **env)
// {
// 	int		i;
// 	char	*str;
// 	size_t	size;

// 	i = 0;
// 	str = ft_strjoin(name, "=");
// 	size = ft_strlen(str);
// 	while (env[i] != NULL)
// 	{
// 		if (ft_strncmp(env[i], str, size) == 0)
// 		{
// 			free (str);
// 			return (env[i] + size);
// 		}
// 		if (ft_strncmp(env[i], name, size) == 0)
// 		{
// 			free (str);
// 			return (env[i] + (size - 1));
// 		}
// 		i++;
// 	}
// 	free (str);
// 	return (NULL);
// }

// void	ft_bzero(void *dest, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		*(char *)(dest + i) = 0;
// 		i++;
// 	}
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*tmp;

// 	tmp = malloc(sizeof(char) * (count * size));
// 	if (tmp == NULL)
// 		return (tmp);
// 	ft_bzero(tmp, size * count);
// 	return (tmp);
// }


// void	print_builtin_error(char *builtin, char *prefix, char *message)
// {
// 	ft_putstr_fd("minishell: ", 2);
// 	if (builtin != NULL)
// 	{
// 		ft_putstr_fd(builtin, 2);
// 		ft_putstr_fd(": ", 2);
// 	}
// 	if (prefix != NULL)
// 	{
// 		ft_putstr_fd(prefix, 2);
// 		ft_putstr_fd(": ", 2);
// 	}
// 	ft_putstr_fd(message, 2);
// 	ft_putstr_fd("\n", 2);
// }

// int	ft_setenv(const char *name, const char *value, int equal, char **env)
// {
// 	int		i;

// 	if (name == NULL || ft_strlen(name) == 0 || ft_strchr(name, '='))
// 		return (-1);
// 	if (ft_getenv(name, env) && equal == 0)
// 		return (0);
// 	if (ft_getenv(name, env) == NULL)
// 	{
// 		ft_addenv(name, value, equal, env);
// 		return (0);
// 	}
// 	i = ft_strarr_index(env, name, "=");
// 	if (equal)
// 	{
// 		free (env[i]);
// 		env[i] = ft_strjoin_triple(name, "=", value);
// 	}
// 	return (0);
// }


void	modify_env(char **env)
{
	char	*pwd;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		print_builtin_error("cd", NULL, strerror(errno));
		return ;
	}
	pwd = ft_strdup(ft_getenv("PWD", env));
	if (pwd)
	{
		ft_setenv("OLDPWD", pwd, 1, env);
		free (pwd);
	}
	ft_setenv("PWD", cwd, 1, env);
	free (cwd);
}


void	ft_cd(char **argv, char **env)
{
	exit_status = 1;
	if (!argv[1])
	{
		if (ft_getenv("HOME", env) == NULL)
			print_builtin_error("cd", NULL, "HOME not set");
		else if (chdir(ft_getenv("HOME", env)) == -1)
			print_builtin_error("cd", ft_getenv("HOME", env), strerror(errno));
		else
			modify_env(env);
	}
	else
	{
		if (argv[1][0] == '\0')
			;
		else if (chdir(argv[1]) == -1)
			print_builtin_error("cd", argv[1], strerror(errno));
		else
			modify_env(env);
	}
}

// int main (int args, char **argv)
// {
// 	int i;
// 	char **env;

// 	env = malloc(sizeof(char *)*20);
// 	if(!env)
// 		return (0);
// 	env[0]="Henlo";
// 	env[1]="=";
// 	env[2]="color";

// 	i = 0;
// 	if (args > 2 || args == 0)
// 		printf("error arguments");
// 	ft_cd(argv, env);
// 	free(env);
// 	return (0);
// }