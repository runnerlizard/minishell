#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = malloc(sizeof(char) * (count * size));
	if (tmp == NULL)
		return (tmp);
	ft_bzero(tmp, size * count);
	return (tmp);
}
