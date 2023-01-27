/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:21:00 by sungjuki          #+#    #+#             */
/*   Updated: 2022/03/15 15:11:17 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_del_save_line(char *buf)
{
	char	*newline_pnt;
	char	*res_str;
	size_t	len;

	newline_pnt = ft_strchr(buf, '\n');
	if (!newline_pnt)
	{
		free(buf);
		return (0);
	}
	len = ft_strlen(buf) - (newline_pnt - buf);
	res_str = (char *)malloc(sizeof(char) * len);
	if (!res_str)
		return (0);
	ft_strlcpy(res_str, newline_pnt + 1, len);
	free(buf);
	return (res_str);
}

static char	*ft_get_line(char *buf)
{
	char	*newline_pnt;
	char	*res_str;
	size_t	len;

	newline_pnt = ft_strchr(buf, '\n');
	if (*buf == 0)
		return (0);
	if (newline_pnt == 0)
		len = ft_strlen(buf) + 1;
	else
		len = newline_pnt - buf + 2;
	if (len == 0)
		return (0);
	res_str = (char *)malloc(sizeof(char) * len);
	if (!res_str)
		return (0);
	ft_strlcpy(res_str, buf, len);
	return (res_str);
}

static char	*ft_read_fd_fill_buf(char *buf, int fd)
{
	char	*temp_buf;
	int		read_bytes;

	temp_buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp_buf)
		return (0);
	read_bytes = 1;
	while (read_bytes && !ft_strchr(buf, '\n'))
	{
		read_bytes = read(fd, temp_buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(temp_buf);
			return (0);
		}
		temp_buf[read_bytes] = 0;
		buf = ft_strjoin(buf, temp_buf);
	}
	free(temp_buf);
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*res_line;
	static char	*buf_line[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	buf_line[fd] = ft_read_fd_fill_buf(buf_line[fd], fd);
	if (!buf_line[fd])
		return (0);
	res_line = ft_get_line(buf_line[fd]);
	buf_line[fd] = ft_del_save_line(buf_line[fd]);
	return ((char *)res_line);
}
