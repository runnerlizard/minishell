#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (n > ft_strlen(s) && (char)c == '\0')
		return ((void *)(s + ft_strlen(s)));
	if (!s || !c || !n)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
