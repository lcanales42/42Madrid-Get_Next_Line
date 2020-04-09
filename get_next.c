/*int	get_next_line(int fd, char **line)
{
	char		str[BUFFER_SIZE + 1];
	char		*str_aux;
	static char *aux[4096];
	int			end;
	int			a;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0)
		return (-1);
	*line = ft_strdup("");
	if (*aux != 0)º
	{
		end = ft_strchr_post(*aux, '\n');
		if (end >= 0)
		{
			str_aux = ft_substr(*aux, 0, end);
			*line = ft_strjoin(*line, str_aux);
			*aux = ft_strdup(*aux + end + 1);
			return (1);
		}
		*line = ft_strjoin(*line, *aux);
	}
	while ((a = read(fd, str, BUFFER_SIZE)) > 0)
	{
		//if (a == 0 && str[a] == '\0')
		//	return (0);
		str[a] = '\0';
		end = ft_strchr_post(str, '\n');
		if (end >= 0)
		{
			*aux = ft_substr(str, 0, end);
			*line = ft_strjoin(*line, *aux);
			*aux = ft_strdup(str + end + 1);
			return (1);
		}
		*line = ft_strjoin(*line, str);
	}
	if (a < 0)
		return (-1);
	free(*aux);
	*aux = 0;
	return (0);
}*/
