#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len_newstr;
	int		i;
	int		j;


	i = 0;
	j = 0;
	len_newstr = ft_strlen(s1)+ ft_strlen(s2);
	newstr = malloc((len_newstr + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
		newstr[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] != '\0')
		newstr[j++] = s2[i++];
	newstr[j] = '\0';
	return (newstr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

char	*get_next_line(int fd)
{
	char static space[BUFFER_SIZE];
	char		*buffer;
	int			nbytesreads;
	int			i;
	char		*temp;

	temp = "";
	nbytesreads = 1;
	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while ((strchr(buffer, '\n') == NULL) && nbytesreads != 0)
	{
		nbytesreads = read(fd, space, BUFFER_SIZE);
		// printf("%s\n\n", space);
		i = 0;
		while (i < nbytesreads)
		{
			buffer[i] = space[i];
			if (space[i] == '\n')
				break;
			i++;
		}
		buffer[nbytesreads] = '\0';
		temp = ft_strjoin(temp, buffer);
		ft_bzero(buffer, BUFFER_SIZE);
	}
	// printf("%s\n", temp);
	// printf("this is the space %s\n", space);
	// printf("***this is buffer n return %lu\n", strlen(buffer));
	return (temp);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*lines;

	i = 1;
	fd = open("file.txt", O_RDONLY);
	// printf("%i\n", fd);
	// printf("**this is get_next_lins return %s\n", get_next_line(fd));
	// printf("**this is get_next_lins return 2 %s\n", get_next_line(fd));
		// while (i <= 4)
	// {
		for (int x=0; x < 4;x++) {
		lines = get_next_line(fd);
		printf("%s\n", lines);
		}
		// free (lines);
		// i++;
	// }
	close(fd); // if open need to close
}

// str[i + 1] = "\0";
// uhuhuhuh.\0
// hello\n 
// heyheyehy.\0
