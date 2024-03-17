#include "libft.h"

static int  find_position(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *c1, char const *c2)
{
	char	*str;
	size_t  i;
	size_t  start;
	size_t  end;

	if (!s1 || !c1 || !c2)
		return (0);
	start = 0;
	while (s1[start] && (find_position(s1[start], c1) || find_position(s1[start], c2)))
		start++;
	end = ft_strlen(s1);
	while (end > start && (find_position(s1[end - 1], c1) || find_position(s1[end - 1], c2)))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
