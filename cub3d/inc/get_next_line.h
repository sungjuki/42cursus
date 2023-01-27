/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:21:08 by sungjuki          #+#    #+#             */
/*   Updated: 2022/11/21 13:13:55 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

char	*get_next_line(int fd);
char	*ft_gl_strchr(const char *s, int c);
size_t	ft_gl_strlcpy(char *dst, const char *src, size_t dst_size);
size_t	ft_gl_strlen(char *s);
char	*ft_gl_strjoin(char *s1, char *s2);

#endif
