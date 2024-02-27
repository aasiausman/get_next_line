/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aausman <aausman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:58:13 by aausman           #+#    #+#             */
/*   Updated: 2024/02/01 20:07:34 by aausman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *store);
char	*ft_new_line(char *buffer);
char	*ft_remaining(char *buffer);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char	*s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
#endif