/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhammani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 13:41:57 by dhammani          #+#    #+#             */
/*   Updated: 2016/02/17 15:37:47 by dhammani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*get_a_line(char *str)
{
	int		i;
	char	*s1;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	s1 = ft_strndup(str, i);
	return (s1);
}

char			*delete_a_line(char *str)
{
	int		i;
	char	*l;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	l = str;
	str = ft_strsub(str, i + 1, ft_strlen(str) - i);
	free(l);
	return (str);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*s[256] = {NULL};
	char			*l;

	ret = 0;
	if (line == NULL || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		l = s[fd];
		s[fd] = ft_strjoin(s[fd], buf);
		free(l);
	}
	if (ret < 0)
		return (-1);
	*line = get_a_line(s[fd]);
	if (ft_strlen(s[fd]) == 0)
		return (0);
	s[fd] = delete_a_line(s[fd]);
	return (1);
}
