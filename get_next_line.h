/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 17:03:16 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 17:17:00 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/includes/libft.h"
# define BUFF_SIZE 4096

typedef	struct	s_chain
{
	void			*str;
	int				fd;
	struct s_chain	*next;
}				t_chain;

int				get_next_line(const int fd, char **line);
int				ft_copy_rest(char **dest, t_chain **to_write, const int fd);
int				ft_read_write(char **dest, t_chain **to_write, const int fd);

#endif
