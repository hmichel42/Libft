/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 17:23:59 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 18:08:44 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_readmap(char **av, t_tetri **tetri)
{
	int		fd;
	char	buf[BUFF_SIZE + 1]
	int		ret;

	fd = open (av[1], O_RDONLY);
	if ((ret = read (fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[BUFF_SIZE] = '\0';
	if ((ret % 21) != 20 || read (fd, buf, 1) != 0 || ft_checkmap(buf, ret / 20))
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (1);
}


int		main(int ac, char **av)
{
	t_tetri		*piece;

	
	ft_readmap(av, &piece);
	
}
