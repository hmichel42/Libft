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

void    ft_cleantetri(t_map **map, char letter)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while ((i + 1) * (j + 1) <= (*map)->size)
    {
        if (((*map)->map)[j][i] == letter)
            ((*map)->map)[j][i] = '.';
        if (i < ft_intsqrt((*map)->size))
            i++;
        else if (j < ft_intsqrt((*map)->size))
        {
            i = 0;
            j++;
        }
    }
}

t_coord ft_findplace(t_map *map, t_tetri tetris, int i, int j)
{
    t_coord     coord;
    int         cmt;

    while ((map->map)[j][i] != '.')
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
    while ((j + 1) * (i + 1) <= map->size)
    {
        cmt = 0;
        if ((map->map)[j][i + 1] && (tetris->tetri)[tetri->y][tetri->x + 1] &&
            (map->map)[j][i + 1] == '.' && (tetris->tetri)[tetri->y][tetri->x + 1] != '.')
            cmt++;
        if ((map->map)[j][i + 2] && (tetris->tetri)[tetri->y][tetri->x + 2] &&
            (map->map)[j][i + 2] == '.' && (tetris->tetri)[tetri->y][tetri->x + 2] != '.')
            cmt++;
        if ((map->map)[j][i + 3] && (tetris->tetri)[tetri->y][tetri->x + 3] &&
            (map->map)[j][i + 3] == '.' && (tetris->tetri)[tetri->y][tetri->x + 3] != '.')
            cmt++;
        if ((map->map)[j + 1][i - 2] && (tetris->tetri)[tetri->y + 1][tetri->x - 2] &&
            (map->map)[j + 1][i - 2] == '.' && (tetris->tetri)[tetri->y + 1][tetri->x - 2] != '.')
            cmt++;
        if ((map->map)[j + 1][i - 1] && (tetris->tetri)[tetri->y + 1][tetri->x - 1] &&
            (map->map)[j + 1][i - 1] == '.' && (tetris->tetri)[tetri->y + 1][tetri->x - 1] != '.')
            cmt++;
        if ((map->map)[j + 1][i] && (tetris->tetri)[tetri->y + 1][tetri->x] &&
            (map->map)[j + 1][i] == '.' && (tetris->tetri)[tetri->y + 1][tetri->x] != '.')
            cmt++;
        if ((map->map)[j + 1][i + 1] && (tetris->tetri)[tetri->y + 1][tetri->x + 1] &&
            (map->map)[j + 1][i + 1] == '.' && (tetris->tetri)[tetri->y + 1][tetri->x + 1] != '.')
            cmt++;
        if ((map->map)[j + 1][i + 2] && (tetris->tetri)[tetri->y + 1][tetri->x + 2] &&
            (map->map)[j + 1][i + 2] == '.' && (tetris->tetri)[tetri->y + 1][tetri->x + 2] != '.')
            cmt++;
        if ((map->map)[j + 2][i - 1] && (tetris->tetri)[tetri->y + 2][tetri->x - 1] &&
            (map->map)[j + 2][i - 1] == '.' && (tetris->tetri)[tetri->y + 2][tetri->x - 1] != '.')
            cmt++;
        if ((map->map)[j + 2][i] && (tetris->tetri)[tetri->y + 2][tetri->x] &&
            (map->map)[j + 2][i] == '.' && (tetris->tetri)[tetri->y + 2][tetri->x] != '.')
            cmt++;
        if ((map->map)[j + 2][i + 1] && (tetris->tetri)[tetri->y + 2][tetri->x + 1] &&
            (map->map)[j + 2][i + 1] == '.' && (tetris->tetri)[tetri->y + 2][tetri->x + 1] != '.')
            cmt++;
        if ((map->map)[j + 3][i] && (tetris->tetri)[tetri->y + 3][tetri->x] &&
            (map->map)[j + 3][i] == '.' && (tetris->tetri)[tetri->y + 3][tetri->x] != '.')
            cmt++;
        if (cmt == 4)
        {
            coord->i = i;
            coord->j = j;
            return (coord);
        }
        if (i < ft_intsqrt(map->size))
            i++;
        else if (j < ft_intsqrt(map->size))
        {
            i = 0;
            j++;
        }
    }
    return (NULL);
}

int     ft_puttetris(t_tetri *tetris, t_map **map, char letter, int start)
{
    t_coord coord;

    while (tetris->letter != letter)
        tetris = tetris->next;
    coord = ft_findplace(*map, tetris, start % ft_intsqrt((*map)->size)), start / ft_intsqrt((*map)->size));
    if (coord == NULL)
        return (0);
    ((*map)->map)[coord->j][cord->i + 1] == letter;
    if ((tetris->tetri)[tetri->y][tetri->x + 1] && tetris->tetri)[tetri->y][tetri->x + 1] != '.')
        ((*map)->map)[coord->j][cord->i + 1] == letter;
    if ((tetris->tetri)[tetri->y][tetri->x + 2] && tetris->tetri)[tetri->y][tetri->x + 2] != '.')
        ((*map)->map)[coord->j][cord->i + 2] == letter;
    if ((tetris->tetri)[tetri->y][tetri->x + 3] && tetris->tetri)[tetri->y][tetri->x + 3] != '.')
        ((*map)->map)[coord->j][cord->i + 3] == letter;
    if ((tetris->tetri)[tetri->y + 1][tetri->x - 2] && tetris->tetri)[tetri->y + 1][tetri->x - 2] != '.')
        ((*map)->map)[coord->j + 1][cord->i - 2] == letter;
    if ((tetris->tetri)[tetri->y + 1][tetri->x - 1] && tetris->tetri)[tetri->y + 1][tetri->x - 1] != '.')
        ((*map)->map)[coord->j + 1][cord->i - 1] == letter;
    if ((tetris->tetri)[tetri->y + 1][tetri->x] && tetris->tetri)[tetri->y + 1][tetri->x] != '.')
        ((*map)->map)[coord->j + 1][cord->i] == letter;
    if ((tetris->tetri)[tetri->y + 1][tetri->x + 1] && tetris->tetri)[tetri->y + 1][tetri->x + 1] != '.')
        ((*map)->map)[coord->j + 1][cord->i + 1] == letter;
    if ((tetris->tetri)[tetri->y + 1][tetri->x + 2] && tetris->tetri)[tetri->y + 1][tetri->x + 2] != '.')
        ((*map)->map)[coord->j + 1][cord->i + 2] == letter;
    if ((tetris->tetri)[tetri->y + 2][tetri->x - 1] && tetris->tetri)[tetri->y + 2][tetri->x - 1] != '.')
        ((*map)->map)[coord->j + 2][cord->i - 1] == letter;
    if ((tetris->tetri)[tetri->y + 2][tetri->x] && tetris->tetri)[tetri->y + 2][tetri->x] != '.')
        ((*map)->map)[coord->j + 2][cord->i] == letter;
    if ((tetris->tetri)[tetri->y + 2][tetri->x + 1] && tetris->tetri)[tetri->y + 2][tetri->x + 1] != '.')
        ((*map)->map)[coord->j + 2][cord->i + 1] == letter;
    if ((tetris->tetri)[tetri->y + 3][tetri->x] && tetris->tetri)[tetri->y + 3][tetri->x] != '.')
        ((*map)->map)[coord->j + 3][cord->i] == letter;
    return (1);
}

int     ft_gotall(t_map *map, int nb_tetri)
{
    int     cmp;
    int     i;
    int     j;

    cmp = 0;
    while (cmp != nb_tetri)
    {
        i = 0;
        j = 0;
        while ((i + 1) * (j + 1) <= map->size)
        {
            if (map->map[i][j] == ('A' + cmp))
            {
                cmp++;
                break ;
            }
            if (i < ft_intsqrt(map->size))
                i++;
            else if (j < ft_intsqrt(map->size))
            {
                i = 0;
                j++;
            }
        }
        if ((i + 1) * (j + 1) == map->size && map->map[i][j] != ('A' + cmp))
            return (0);
    }
    return (1);
}
int     ft_solve(t_tetri **begin_tetris, t_map **map, int start, int nb_tetri)
{
    if (!(*begin_tetris) && ft_gotall(*map, nb_tetri))
        return (1);
    if (ft_puttetri(*begin_tetris, map, (*begin_tetris)->letter), start)
    {
        if (ft_solve(&((*begin_tetris)->next), map, start, ((*begin_tetris)->next)->letter)) // start++ pour opti
            return (1);
        else
            ft_cleantetri(map, (*begin_tetris)->letter);
    }
    else if (start != (*map)->size)
        if (ft_solve(begin_tetris, map, start++, (*begin_tetris)->letter))
            return (1);
    return (0);
}

/*
int     ft_solve(t_tetri **begin_tetris, t_map **map)
{
    if (!(*begin_tetris))
        return (1);
    while (coord->i * coord->j < (*map)->size)
    {
        while (coord->i < ft_intsqrt((*map)->size))
        {
            if (ft_puttetri(*begin_tetris, map, (*begin_tetris)->letter))
            {
                
            }
            coord->i = coord->i + 1;
        }
        coord->j = coord->j + 1;
    }
}
*/

t_map     ft_resolve(t_tetri **begin_tetris, int nb_tetri)
{
    t_map   *map;
    int     size;
    t_coord *coord;

    coord->i = 0;
    coord->j = 0;
    size = ft_intsqrt(nb_tetri);
    if (!(ft_setmap(size, &map)))
        return (NULL);
    while (!ft_solve(begin_tetris, &map, coord, nb_tetri))
    {
        size++;
        if (!(ft_setmap(size, &map)))
            return (NULL);
    }
    return (map);
}