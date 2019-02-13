/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 09:52:09 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 09:52:12 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int     ft_setmap(int size, t_map **map)
{
    int     i;

    if ((*map)->map)
    {
        i = 0;
        while (i < size + 1)
        {
            free ((*map)->map[i]);
            i++;
        }
        free ((*map)->map);
    }
    if (!((*map)->map = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
        return (0);
    (*map)->size = size;
    i = 0;
    while (i < size)
    {
        if (!((*map)->map[i] = ft_strnew(size)))
            return (0);
        (*map)->map[i] = (char *)ft_memset((char *)(*map)->map[i], 46, size);
        i++;
    }
    (*map)->map[size][0] = '\0';
    return (1);
}

t_coord ft_findplace(t_map *map, t_tetri tetris, int i, int j)
{
    t_coord     coord;
    int         cmt;

    cmt = 0;
    while (map[j][i] != '.')
    {
        if (i < ft_intsqrt((*map)->size))
            i++;
        else if (j < ft_intsqrt((*map)->size))
        {
            i = 0;
            j++;
        }
        else
            return (NULL);   
    }
    while ()
}

int     ft_puttetris(t_tetri *tetris, t_map **map, char letter)
{
    int     i;
    t_coord coord;

    while (tetris->letter != letter)
        tetris = tetris->next;
    coord = ft_findplace(t_map *map, t_tetri tetris)

}

int     ft_solve(t_tetri **begin_tetris, t_map **map, t_coord *coord)
{
    if (!(*begin_tetris))
        return (1);
    while (map[j][i] != '.')
    {
        if (i < ft_intsqrt((*map)->size))
            i++;
        else if (j < ft_intsqrt((*map)->size))
        {
            i = 0;
            j++;
        }
        else
            return (0);   
    }
    while (coord->i * coord->j < (*map)->size)
    {
        coord->i = 0;
        while (coord->i < ft_intsqrt((*map)->size))
        {
            if (ft_puttetri())
            {
                
            }
            coord->i = coord->i + 1;
        }
        coord->j = coord->j + 1;
    }
}

t_map     ft_resolve(t_tetri **begin_tetris, int nb_tetri)
{
    t_map   *map;
    int     size;

    size = ft_intsqrt(nb_tetri);
    if (!(ft_setmap(size, &map)))
        return (NULL);
    while (!ft_solve(t_tetri **begin_tetris, t_map **map))
    {
        size++;
        if (!(ft_setmap(size, &map)))
            return (NULL);
    }
    return (map);
}