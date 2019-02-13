/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_intsqrt.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 11:13:49 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 11:13:51 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

int				ft_intsqrt(int	nb)
{
    int     res;

    res = 0;
    /*
    while ((nb / res) != res)
    {
        while (res * res != nb && res < (nb / 2))
            res++;
        if (res == nb)
            nb++;
    }*/
    while (res * res < nb)
        res++;
    return (res);
}