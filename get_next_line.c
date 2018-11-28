/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 18:29:58 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 19:44:49 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static	int		ft_findNL_rest(t_chain *to_write, char **dest)
{
	int		i;

	printf("1.1\n");
	i = ft_strchri(to_write->str, '\n');
	if (i < 0)
	{
		*dest = ft_strsub(to_write->str, 0, ft_strlen(to_write->str));
		to_write->str = NULL;
		printf("1.2\n");
		return (1);
	}
	else
	{
		*dest = ft_strsub(to_write->str, 0, i);
		to_write->str = ft_strsub(to_write->str, i + 1, ft_strlen(to_write->str) - i - 1);
		printf("1.3\n");
		return (0);
	}
}

static	int		ft_read_lines(char **dest, const int fd, t_chain **to_write)
{
	int		ret;
	int		i;
	char	buff[BUFF_SIZE];

	i = -1;
	ret = BUFF_SIZE;
	printf("2.1\n");
	while (ret == BUFF_SIZE && i < 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		printf("2.2\n");
		if (ret > 0)
			{
				*dest = *dest + ft_strlen(*dest);
				i = ft_strchri(buff, '\n');
				*dest = ft_strsub(buff, 0, ABS(i));
				printf("2.3\n");
				if (i >= 0 && i != BUFF_SIZE - 1)
				{
					if (!(*to_write))
					{
						if (!(*to_write = (t_chain*)malloc(sizeof(t_chain))))
							return (-1);
					}
					else
					{
						while (*to_write && (*to_write)->next != NULL)
							(*to_write) = (*to_write)->next;
						if (!((*to_write)->next = (t_chain*)malloc(sizeof(t_chain))))
							return (-1);
						*to_write = (*to_write)->next;
					}
					(*to_write)->str = ft_strsub(buff, i + 1, BUFF_SIZE - i - 1);
					(*to_write)->fd = fd;
					(*to_write)->next = NULL;
					printf("2.4\n");
				}
			}
	}
	printf("2.5\n");
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static t_chain 	*to_write = NULL;
	t_chain 		**begin_list;
	int				ret;
	int				need_toread;

	ret = 0;
	need_toread = 1;
	begin_list = &to_write;
	printf("commencement traitement\n");
	while (to_write != NULL && (to_write->fd != fd && to_write->str != NULL))
		to_write = to_write->next;
	printf("1\n");
	if (to_write != NULL && to_write->fd == fd)
		need_toread = ft_findNL_rest(to_write, line);
	printf("2\n");
	if (need_toread == 1)
		ret = ft_read_lines(line, fd, &to_write);
	printf("3\n");
	printf("le fd en satic est %d\n", to_write->fd);
	printf("la str en satic est %s\n", to_write->str);
	printf("len de line: %zu\n", ft_strlen(*line));
	printf("ret = %d\n", ret);
	if (ft_strlen(*line) != 0)
		return (1);
	else
	{
		printf("je retourne %d\n", ret);
		return (ret);
	}
}
