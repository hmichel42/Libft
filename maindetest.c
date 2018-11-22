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
