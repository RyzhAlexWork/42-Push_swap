/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 11:16:39 by jbowen            #+#    #+#             */
/*   Updated: 2019/06/28 09:50:48 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		fill_rem(char **rem, const int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	ret = read(fd, buf, BUFF_SIZE);
	if (ret <= 0)
		return (ret);
	buf[ret] = '\0';
	if (*rem == NULL)
		*rem = ft_strnew(ft_strlen(buf));
	*rem = ft_strjoinfree(*rem, buf);
	return (ret);
}

char	*get_line(char *rem)
{
	char	*str;
	size_t	i;

	i = 0;
	while (rem[i] != '\n' && rem[i] != '\0')
		i++;
	str = ft_strnew(i);
	if (rem[0] != '\n')
		str = ft_strncpy(str, rem, i);
	return (str);
}

int		do_all_need(char **rem, const int fd)
{
	size_t	i;
	int		ret;
	int		a;

	i = 0;
	a = 0;
	ret = 1;
	if (fd < 0 || fd > 30000)
		return (-1);
	while (a != 1 && ret > 0)
	{
		if (*rem == NULL)
			ret = fill_rem(rem, fd);
		if (ret > 0)
		{
			while (*(*(rem) + i) != '\0' && *(*(rem) + i) != '\n')
				i++;
			if (*(*(rem) + i) == '\n')
				a = 1;
			else
				ret = fill_rem(rem, fd);
		}
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*rem[30000];
	int				ret;
	size_t			i;

	i = 0;
	ret = do_all_need(&rem[fd], fd);
	if (ret < 0 || fd < 0 || BUFF_SIZE == 0)
		return (-1);
	if (ret == 0 && rem[fd] == NULL)
		return (0);
	*line = get_line(rem[fd]);
	if (ret == 0 && rem[fd][0] == '\0')
	{
		ft_strdel(&rem[fd]);
		return (0);
	}
	if (ret == 0)
		ft_strdel(&rem[fd]);
	if (ret > 0)
	{
		while (rem[fd][i] != '\n' && rem[fd][i] != '\0')
			i++;
		rem[fd] = ft_subfr(rem[fd], i + 1, ft_strlen(rem[fd]) - i - 1);
	}
	return (1);
}
