/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluco <cluco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:10:40 by mjeanett          #+#    #+#             */
/*   Updated: 2022/03/11 14:48:51 by cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	result;
	int	i;

	if ((s1 && !(s2)) || (!(s1) && s2))
		return (1);
	result = 0;
	i = -1;
	while (s1[++i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			continue ;
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (result);
	if (s1[i] > s2[i])
		return (1);
	return (-1);
}
