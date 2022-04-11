#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(s);
	while (i != len + 1)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
