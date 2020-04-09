/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:14:57 by lcanales          #+#    #+#             */
/*   Updated: 2019/12/23 18:25:03 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strchr_post(char *str, char c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
#endif
