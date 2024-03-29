#include "../../headers/major.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
		i++;
	return i;
}

char	*ft_strcopy(char *str)
{
	char	*ret;
	int		i;
	int		size;
	
	if (!str)
		return (NULL);
	size  = ft_strlen(str);
	ret = malloc((size + 1)* sizeof(char));
	if (!ret)
		return(NULL);
	i = 0;
	while(i < size)
	{
		ret[i] = str[i];
		i++;
	}
	ret[size] = '\0';
	free(str);
	return(ret);
}

char	*ft_strjoin(char *first, char *second)
{
	char	*ret;
	int		size;
	int		i;
	int		j;

	if (!first && !second)
		return (NULL);
	else if (!first)
		return (ft_strcopy(second));
	else if (!second)
		return (ft_strcopy(first));
	size = ft_strlen(first);
	ret = malloc((size + ft_strlen(second) + 1) * sizeof(char));
	i = -1;
	j = 0;
	while(++i < size)
		ret[i] = first[i];
	size = ft_strlen(second);
	while(j < size)
		ret[i++] = second[j++];
	ret[ft_strlen(first) + size] = '\0';
	free(first);
	free(second);
	return (ret);
}