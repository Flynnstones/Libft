#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	ft_wordcount(char *str, char c);
static char	*ft_stralloc(char *str, char c, int *k);
static void	ft_strcpy(char *word, char *str, char c, int j);
static void	ft_freeup(char *strs);

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		pos;

	if (str == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = ft_wordcount((char *)str, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (strs == NULL)
		return (NULL);
	strs[j] = NULL;
	while (i < j)
	{
		strs[i] = ft_stralloc(((char *)str), c, &pos);
		if (strs[i] == NULL)
		{
			(ft_freeup(strs[i]));
		}
		i++;
	}
	return (strs);
}

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (word);
		}
		i++;
	}
	return (word);
}

static char	*ft_stralloc(char *str, char c, int *k)
{
	char	*word;
	int		j;

	j = *k;
	word = NULL;
	while (str[*k] != '\0')
	{
		if (str[*k] != c)
		{
			while (str[*k] != '\0' && str[*k] != c)
				*k += 1;
			word = (char *)malloc(sizeof(char) * (*k + 1));
			if (word == NULL)
				return (NULL);
			break ;
		}
		*k += 1;
	}
	ft_strcpy(word, str, c, j);
	return (word);
}

static void	ft_strcpy(char *word, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + i] != c && str[j + i] != '\0')
	{
		word[i] = str[j + i];
		i++;
	}
	word[i] = '\0';
}

static void	ft_freeup(char *strs)
{
	int	i;

	i = 0;
	while (strs[i] != '\0')
	{
		free(strs);
		i++;
	}
	free(strs);
}

int main(void)
{
    char    *str = "Hello,world,how,are,you";
    char    **strs;
    int     i;

    strs = ft_split(str, ',');
    i = 0;
    while (strs[i] != NULL)
    {
        printf("%s\n", strs[i]);
        i++;
    }
    return (0);
}