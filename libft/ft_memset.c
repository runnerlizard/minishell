#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*vrb;

	vrb = (unsigned char *)dest;
	while (len != 0)
	{
		*vrb = (unsigned char)c;
		vrb++;
		len--;
	}
	return (dest);
}
