/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 20:41:37 by lcanales          #+#    #+#             */
/*   Updated: 2019/12/23 18:46:31 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	next_line_aux(char *str1, char **line1, char **aux1)
{
	int		end;
	char	*line_aux;
	char	*line_aux1;

	end = ft_strchr_post(str1, '\n');
	if (end >= 0)
	{
		if (*aux1)
			free(*aux1);
		*aux1 = ft_substr(str1, 0, end);
		line_aux = ft_strjoin(*line1, *aux1);
		free(*line1);
		*line1 = line_aux;
		line_aux = ft_strdup(str1 + end + 1);
		free(*aux1);
		*aux1 = line_aux;
		return (1);
	}
	line_aux1 = ft_strjoin(*line1, str1);
	free(*line1);
	*line1 = line_aux1;
	return (0);
}

int	next_line_aux1(char **str2, char **line2)
{
	int		end;
	char	*aux2;
	char	*line_aux;

	end = ft_strchr_post(*str2, '\n');
	if (end >= 0)
	{
		aux2 = ft_substr(*str2, 0, end);
		line_aux = ft_strjoin(*line2, aux2);
		free(*line2);
		*line2 = line_aux;
		free(aux2);
		aux2 = ft_strdup(*str2 + end + 1);
		if (*str2)
			free(*str2);
		*str2 = aux2;
		return (1);
	}
	line_aux = ft_strjoin(*line2, *str2);
	free(*line2);
	*line2 = line_aux;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		str[BUFFER_SIZE + 1];
	static char *aux[4096];
	int			a;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0)
		return (-1);
	*line = ft_strdup("");
	if (aux[fd] != 0)
	{
		if (next_line_aux1(&aux[fd], line) == 1)
			return (1);
	}
	while ((a = read(fd, str, BUFFER_SIZE)) > 0)
	{
		str[a] = '\0';
		if (next_line_aux(str, line, &aux[fd]) == 1)
			return (1);
	}
	if (a < 0)
		return (-1);
	free(aux[fd]);
	aux[fd] = 0;
	return (0);
}
