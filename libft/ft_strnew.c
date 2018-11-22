/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 01:53:43 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 02:46:14 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char		*tab;
	size_t		i;

	i = 0;
	if (!(tab = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size + 1)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}
