/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_futils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeanett <mjeanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:55:21 by mjeanett          #+#    #+#             */
/*   Updated: 2022/03/09 11:55:22 by mjeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_strarr_free(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free (arr[i++]);
	free (arr);
}

char	**ft_strarr_dup(char **arr, int size_plus)
{
	char	**dup;
	int		i;

	i = 0;
	if (arr)
		while (arr[i])
			i++;
	dup = (char **)ft_calloc((i + 1 + size_plus), sizeof(char *));
	if (!dup)
		return (NULL);
	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			dup[i] = ft_strdup(arr[i]);
			i++;
		}
	}
	return (dup);
}

int	ft_strarr_size(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

char	*ft_strjoin_triple(const char *s1, const char *s2, const char *s3)
{
	size_t	size;
	char	*str;
	int		i;
	int		j;

	if (s1 && s2 && s3)
	{
		size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
		str = (char *)ft_calloc((size + 1), sizeof(char));
		if (!str)
			return (NULL);
		j = 0;
		i = 0;
		while (s1[i])
			str[j++] = s1[i++];
		i = 0;
		while (s2[i])
			str[j++] = s2[i++];
		i = 0;
		while (s3[i])
			str[j++] = s3[i++];
		return (str);
	}
	return (NULL);
}

int	ft_strarr_index(char **arr, const char *str, const char *sep)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_strncmp(arr[i], str, ft_strlen(str)) == 0)
		{
			if (!(arr[i][ft_strlen(str)])
				|| ft_strchr(sep, arr[i][ft_strlen(str)]))
				return (i);
		}
		i++;
	}
	if (str == NULL)
		return (i);
	return (-1);
}

void	ft_strarr_sort(char **arr, int size)
{
	int		i;
	int		j;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(arr[i], arr[j]) > 0)
			{
				tmp1 = ft_strdup(arr[i]);
				tmp2 = ft_strdup(arr[j]);
				free (arr[i]);
				free (arr[j]);
				arr[i] = tmp2;
				arr[j] = tmp1;
			}
			j++;
		}
		i++;
	}
}
