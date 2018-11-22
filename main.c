/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 19:22:20 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 20:12:43 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int  main(void)
{
	char  *line = NULL;
	int   fd = open("gnl01.txt", O_RDONLY);

	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free (line);
	}
	close(fd);
	sleep(15);
	printf("\n%s\n", line);
	return (0);
}
