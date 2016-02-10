/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhammani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 13:28:00 by dhammani          #+#    #+#             */
/*   Updated: 2016/02/10 11:45:34 by dhammani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 99

# include "libft/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

int				get_next_line(int const fd, char **line);

#endif
