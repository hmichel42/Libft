/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 15:47:39 by hmichel      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 20:25:24 by hmichel     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		ft_copy_rest(char **dest, t_chain **to_write, const int fd)
{
	int		len;
	int		res;

	res = 0;
	len = 0;
	printf("entree ft_copy_rest: OK\n");
	if (!*to_write)
		return (0);
	printf("JE passe ici\n");
	while ((*to_write)->fd != fd)
	{
		printf("le fd est: %d\n", (*to_write)->fd);
		if ((*to_write)->next == NULL )  //si il n'y a pas de reste static pour notre fd			
			return (0);  //on renvoie 0 cad qu'il faut faire appel a ft_read_write
		*to_write = (*to_write)->next;	//on cherche la string qui correspond au fd correspondant
	}
	printf("Ce qu'il reste en static str; |%s|\n", (*to_write)->str);
	if ((len = ft_strchri((*to_write)->str, '\n')) > 0) //on cherche l'index du '\n'
		res = 1;	//res mit a 1 <=> il y a un '\n' dans le reste
	if (res == 0)	//res = 0 <=> on inverse la len car strchri renvoie -len
		len = -len;
	printf("len = %d\n", len);
	printf("res = %d\n", res);
	*dest = ft_strncpy(*dest, (*to_write)->str, len); //on copit les elements avant le '\n' sans le '\n'
	(*to_write)->str = ft_strsub((*to_write)->str, len + res, ft_strlen((*to_write)->str) - len - res); // on enleve de la source ce qu'on a copie, res pour le '\n'
	return (res);
}

int		ft_read_write(char **dest, t_chain **to_write, const int fd)
{
	int		ret;
	t_chain	*new;
	int		i;

	new = (t_chain *)malloc(sizeof(t_chain *));
	printf("fd: %d\n", fd);
	new->str = ft_strnew(BUFF_SIZE);	//on cree un nouveau maillon lie a notre fd (il ne reste plus rien en memoire car ft_copy_rest a deja ete appelee)
	new->fd = fd;
	if (to_write)
		new->next = *to_write;	//on ajoute a la liste le nouveau fd avec sa chaine de cara
	else
		new->next = NULL;
	*to_write = new;
	printf("on read\n");
	while ((ret = read(fd, (*to_write)->str, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);	//on s'assure que si la lecture echoue on ne cherche pas a copie quelque chose
		printf("i = %d\n", ft_strchri((*to_write)->str, '\n'));
		if ((i = ft_strchri((*to_write)->str, '\n')) >= 0)
		{
			//*dest = ft_strncpy(*dest, (*to_write)->str, i);
			*dest = ft_strsub((*to_write)->str, 0, i);
			printf("Je rentre au bon endroit\n");
			//(*to_write)->str = &(((*to_write)->str)[i + 1]); // on met en static l'adresse du premier element que l'on n'a pas copie
			(*to_write)->str = ft_strchr((*to_write)->str, '\n') + 1;
			return (1);	//on renvoie 1 signifiant que la lecture est determine
		}
		else
			*dest = ft_strcpy(*dest, (*to_write)->str);	//on copie l'integralite de la string car il n'y a pas d''\n'
	}
	printf("Lecture finie\n");
	return (0);	//on ne peut plus lire donc la lecture est terminee
}

int		get_next_line(const int fd, char **line)
{
	static t_chain	*to_write = NULL;

	printf("\nEntree dans GNL\n");
	if (to_write != NULL && ft_copy_rest(line, &to_write, fd))
		return (1);
	return (ft_read_write(line, &to_write, fd));
}

/*
   int	main(void)
   {
   int		fd;
   char	*dest;
   int		i;
   char	*dest_bis;

   fd = open("test.txt", O_RDONLY);
   dest = (char *)malloc(sizeof(char) * 500);
   i = 3;
   dest_bis = dest;
   while ((i = get_next_line(fd, &dest)))
   {
   printf("Valeur de retour: %d\n", i);
   printf("Il y a dans dest: |%s|\n", dest_bis);
   dest = dest + ft_strlen(dest);
   }
   return (0);
   }


   int	main(void) //main de test ft_copy_rest
   {
   t_chain *to_write;
   char *dest;
   t_chain **begin_list;
   int	i;

   i = 0;
   to_write->str = (char*)malloc(sizeof(char) * 500);
   to_write->str = "Je suis beau\nbb\njtm";
   to_write->fd = 454;
   (to_write->next)->str = (char*)malloc(sizeof(char) * 500);
   (to_write->next)->str = "deuxieme\nfd\ntmtc";

   (to_write->next)->fd = 38;
   (to_write->next)->next = NULL;
   dest = malloc(sizeof(char) * 500);
   begin_list = &to_write;
   while (i++ < 3)
   {
   printf("appelle fonction.\n");
   printf("sortie: %d\n", ft_copy_rest(&dest, begin_list, 38));
   printf("on remplit avec |%s|\n", dest);
   printf("il reste dans la source |%s|\n", to_write->str);
   dest = dest + ft_strlen(dest);
   }
   return (0);
   } 

   int main(void)
   {
   int		fdd;
   char	*dest;
   static	t_chain *to_write;
   int	i;
   char	*dest_bis;

   fdd = open("#test.txt#", O_RDONLY);
   dest = (char *)malloc(sizeof(char) * 500);
   i = 0;
   printf("OK.\n");
//to_write->str = (char *)malloc(sizeof(char) * 500);
//to_write->str = "Je suis beau\nbb\njtm";
//to_write->fd = 454;
printf("OK.\n");
//(to_write->next)->str = (char*)malloc(sizeof(char) * 500);
printf("OK.\n");
//(to_write->next)->str = "deuxieme\nfd\ntmtc";
//(to_write->next)->fd = 38;
//(to_write->next)->next = NULL;
dest_bis = dest;
while (i++ < 4)
{
	printf("\nappelle fonction.\n");
	printf("Valeur de retour: %d\n", ft_read_write(&dest_bis, &to_write, fdd));
	printf("Il y a dans dest: |%s|\n", dest_bis);
	dest = dest + ft_strlen(dest);
}
return (0);
}	*/
