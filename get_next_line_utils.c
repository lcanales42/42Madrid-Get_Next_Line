/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 20:42:06 by lcanales          #+#    #+#             */
/*   Updated: 2019/12/11 20:09:33 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	rt;

	rt = 0;
	while (str[rt])
		rt++;
	return (rt);
}

int		ft_strchr_post(char *str, char c)
{
	int	rt;

	rt = 0;
	while (str[rt] != 0)
	{
		if (str[rt] == c)
			return (rt);
		rt++;
	}
	return (-1);
}

char	*ft_strdup(char *s1)
{
	unsigned int	rt;
	char			*str;

	rt = ft_strlen(s1);
	if (!(str = malloc(sizeof(char) * rt + 1)))
		return (0);
	rt = 0;
	while (s1[rt] != 0)
	{
		str[rt] = s1[rt];
		rt++;
	}
	str[rt] = 0;
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	rt;

	if (s == 0)
		return (0);
	rt = ft_strlen(s);
	if (start > rt)
		return (ft_strdup(""));
	rt = rt + start;
	if (rt < len)
		len = rt;
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (0);
	rt = 0;
	while (rt < len)
	{
		str[rt] = s[rt + start];
		rt++;
	}
	str[rt] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	rt;
	unsigned int	rt1;
	char			*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	if (!(str = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char))))
		return (0);
	rt = 0;
	rt1 = 0;
	while (s1[rt] != 0)
	{
		str[rt] = s1[rt];
		rt++;
	}
	while (s2[rt1] != 0)
	{
		str[rt] = s2[rt1];
		rt++;
		rt1++;
	}
	str[rt] = '\0';
	return (str);
}
