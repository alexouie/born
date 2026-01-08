/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:53:52 by almanier          #+#    #+#             */
/*   Updated: 2025/12/19 13:30:52 by almanier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <stdlib.h>
#include <unistd.h> 


char    *get_next_line(int fd);
char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *s);
char    *ft_substr(const char *s, unsigned int start, size_t len);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strchr(const char *s, int c);

#endif
