#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	i = 0;
	if (dst != NULL || src != NULL)
	{
		if (dst < src)
		{
			while (i < len)
			{
				((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
				i++;
			}
		}
		else
		{
			i = len;
			while (i > 0)
			{
				i--;
				((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
			}
		}
		return (dst);
	}
	return (NULL);
}
