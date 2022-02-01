#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = s1[i];
	return (tmp);
}
