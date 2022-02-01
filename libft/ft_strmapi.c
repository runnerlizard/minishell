#include "libft.h"

char	*ft_strmapi(char const *s1, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	str = ft_strdup(s1);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = (*f)(i, str[i]);
		i++;
	}
	return (str);
}
