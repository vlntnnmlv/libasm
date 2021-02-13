/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:41:52 by rmarguri          #+#    #+#             */
/*   Updated: 2020/12/05 14:38:04 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

ssize_t			ft_write(int fildes, const void *buf, size_t nbyte);
size_t			ft_strlen(const char *str);
char			*ft_strcpy(char * dst, const char * src);
int				ft_strcmp(const char *s1, const char *s2);
ssize_t			ft_read(int fildes, void *buf, size_t nbyte);
char			*ft_strdup(const char *s1);

static void		test_strlen(void)
{
	char	*str1 = "";
	char	*str2 = "short";
	char	*str3 = "very very very very very very very very long string";


	system("clear");
	printf("\e[1;33m");
	printf("// ------------- STRLEN -------------- //\n");
	printf("\e[0m");
	printf("\e[1;31m");
	printf("str = '%s'\n\n", str1);
	printf("\e[0m");
	printf("ft_strlen -> %zu\n", ft_strlen(str1));
	printf("   strlen -> %zu\n", strlen(str1));
	printf("\e[1;31m");
	printf("\nstr = '%s'\n\n", str2);
	printf("\e[0m");
	printf("ft_strlen -> %zu\n", ft_strlen(str2));
	printf("   strlen -> %zu\n", strlen(str2));
	printf("\e[1;31m");
	printf("\nstr = '%s'\n\n", str3);
	printf("\e[0m");
	printf("ft_strlen -> %zu\n", ft_strlen(str3));
	printf("   strlen -> %zu\n\n", strlen(str3));
}

static void		test_strcpy(void)
{
	char	*buf;
	char	*str1 = "";
	char	*str2 = "short";
	char	*str3 = "very very very very very very very very long string";

	system("clear");
	printf("\e[1;33m");
	printf("// ------------- STRCPY -------------- //\n");
	printf("\e[0m");
	buf = malloc(sizeof(char) * 100);
	printf("\e[1;31m");
	printf("'%s' <-src\n\n", str1);
	printf("\e[0m");
	printf("'%s' <- ft_strcpy\n", ft_strcpy(buf, str1));
	free(buf);
	buf = malloc(sizeof(char) * 100);
	printf("'%s' <-    strcpy\n\n", strcpy(buf, str1));
	printf("\e[1;31m");
	printf("'%s' <-src\n\n", str2);
	printf("\e[0m");
	free(buf);
	buf = malloc(sizeof(char) * 100);
	printf("'%s' <- ft_strcpy\n", ft_strcpy(buf, str2));
	free(buf);
	buf = malloc(sizeof(char) * 100);
	printf("'%s' <-    strcpy\n\n", strcpy(buf, str2));
	free(buf);
	buf = malloc(sizeof(char) * 100);
	printf("\e[1;31m");
	printf("'%s' <-src\n\n", str3);
	printf("\e[0m");
	printf("'%s' <- ft_strcpy\n", ft_strcpy(buf, str3));
	free(buf);
	buf = malloc(sizeof(char) * 100);
	printf("'%s' <-    strcpy\n\n", strcpy(buf, str3));
	free(buf);
	buf = NULL;
}

static void		test_strcmp(void)
{
	char	*str1 = "";
	char	*str2 = "short";
	char	*str3 = "very very very very very very very very long string";

	system("clear");
	printf("\e[1;33m");
	printf("// ------------- STRCMP -------------- //\n");
	printf("\e[0m");
	printf("\e[1;31m");
	printf("str1 = '%s'\nstr2 = '%s'\n\n", str1, str1);
	printf("\e[0m");
	printf("   strdup-> %d\nft_strdup-> %d\n\n", strcmp("dffds", "dffds"), ft_strcmp("dffds", "dffds"));
	printf("______________________\n");
	printf("\e[1;31m");
	printf("str1 = '%s'\nstr2 = '%s'\n\n", str1, str2);
	printf("\e[0m");
	printf("   strdup-> %d\nft_strdup-> %d\n\n", strcmp(str1, str2), ft_strcmp(str1, str2));
	printf("______________________\n");
	printf("\e[1;31m");
	printf("str1 = '%s'\nstr2 = '%s'\n\n", str2, str1);
	printf("\e[0m");
	printf("   strdup-> %d\nft_strdup-> %d\n\n", strcmp(str2, str1), ft_strcmp(str2, str1));
	printf("______________________\n");
	printf("\e[1;31m");
	printf("str1 = '%s'\nstr2 = '%s'\n\n", str2, str2);
	printf("\e[0m");
	printf("   strdup-> %d\nft_strdup-> %d\n\n", strcmp(str2, str2), ft_strcmp(str2, str2));
	printf("______________________\n");
	printf("\e[1;31m");
	printf("str1 = '%s'\nstr2 = '%s'\n\n", str3, str2);
	printf("\e[0m");
	printf("   strdup-> %d\nft_strdup-> %d\n\n", strcmp(str3, str2), ft_strcmp(str3, str2));
	printf("______________________\n");
	printf("\e[1;31m");
	printf("str1 = '%s'\nstr2 = '%s'\n\n", str2, str3);
	printf("\e[0m");
	printf("   strdup-> %d\nft_strdup-> %d\n\n", strcmp(str2, str3), ft_strcmp(str2, str3));
	printf("______________________\n");
}

static void		test_write(void)
{
	int		fd;
	char	*str2 = "CUM ONLY ***** ANIME GIRLS";
	int		len = 2;

	system("clear");
	printf("\e[1;33m");
	printf("// ------------- WRITE -------------- //\n");
	printf("\e[0m");
	printf("\e[1;31m'%s' <- str\n\n\e[0m", str2);
	printf(" <-    write: %d length\n%zd <- return\n\n", len, write (1, str2, len));
	printf(" <- ft_write: %d length\n%zd <- return\n\n", len, ft_write (1, str2, len));
	len = 0;
	printf(" <-    write: %d length\n%zd <- return\n\n", len, write (1, str2, len));
	printf(" <- ft_write: %d length\n%zd <- return\n\n", len, ft_write (1, str2, len));
	len = ft_strlen(str2);
	printf(" <-    write: %d length\n%zd <- return\n\n", len, write (1, str2, len));
	printf(" <- ft_write: %d length\n%zd <- return\n\n", len, ft_write (1, str2, len));
	printf("\e[1;37m// ---------- WRITE TO FILE ---------- //\e[0m\n\n");
	fd = open("file", O_RDWR | O_TRUNC);
	printf("\e[1;31m write \e[0m\n");
	printf("error -> %s\n", strerror(errno));
	printf("%zd <- return\n", write(fd, str2, len));
	system ("cat -e file");
	close(fd);
	fd = open("file", O_RDWR | O_TRUNC);
	printf("\n\n\e[1;31m ft_write \e[0m");
	printf("\nerror -> %s\n", strerror(errno));
	printf("%zd <- return\n", ft_write(fd, str2, len));
	system ("cat -e file");
	close(fd);
	fd = 7;
	printf("\n\n\e[1;37m// ---------- BAD FD ---------- //\e[0m\n\n");
	printf("%zd <-    write return\n", write(fd, str2, len));
	printf("error -> %s\n", strerror(errno));
	printf("%zd <- ft_write return\n", ft_write(fd, str2, len));
	printf("error -> %s\n", strerror(errno));
	printf("\n\e[1;37m// ---------- READONLY FILE ---------- //\e[0m\n");
	fd = open("donttouchme", O_TRUNC);
	printf("error -> %s\n", strerror(errno));
	printf("%zd <- return\n", write(fd, str2, len));
	close(fd);
	fd = open("donttouchme", O_TRUNC);
	printf("\nerror -> %s\n", strerror(errno));
	printf("%zd <- return\n", ft_write(fd, str2, len));
	close(fd);
}

static void		test_read(void)
{
	char	*buf;
	int		fd;

	system("clear");
	printf("\e[1;33m// ------------- READ -------------- //\e[0m\n");
	printf("\e[1;37m Чтение read из stdin строки длиной 5:\e[0m\n");
	buf = malloc(sizeof(char) * 100);
	printf("%zd <- return\n", read(0, buf, 5));
	printf("%s\n", buf);
	free(buf);
	printf("\e[1;37mЧтение ft_read:\e[0m\n");
	buf = malloc(sizeof(char) * 100);
	printf("%zd <- return\n", ft_read(0, buf, 5));
	printf("%s\n", buf);
	free(buf);
	printf("\e[1;37m// ---------- READ FORM FD ---------- //\e[0m\n\n");
	fd = open("readfile", O_RDONLY);
	buf = malloc(sizeof(char) * 100);
	printf("%zd <-    read return\n", read(fd, buf, 100));
	printf("Что он считал -> %s\n", buf);
	free(buf);
	close (fd);
	fd = open("readfile", O_RDONLY);
	buf = malloc(sizeof(char) * 100);
	printf("%zd <- ft_read return\n", ft_read(fd, buf, 100));
	printf("Что он считал -> %s\n", buf);
	free(buf);
	close (fd);
	fd = 7;
	printf("\n\n\e[1;37m// ---------- BAD FD ----------// \e[0m\n\n");
	printf("%zd <-    read return\n", read(fd, buf, 100));
	printf("error -> %s\n", strerror(errno));
	printf("%zd <- ft_read return\n", ft_read(fd, buf, 100));
	printf("error -> %s\n", strerror(errno));
}

static void		test_strdup(void)
{
	char	*str = "nevermorenevermore";
	char	*duplicated;

	system("clear");
	printf("\e[1;33m// ------------- STRDUP -------------- //\e[0m\n");
	printf("\n\e[1;37mПустая строка\e[0m\n\n");
	duplicated = strdup("");
	printf("'%s' <-    strdup\n", duplicated);
	free(duplicated);
	duplicated = ft_strdup("");
	printf("'%s' <- ft_strdup\n", duplicated);
	free(duplicated);
	printf("\n\e[1;37mНепустая строка = %s\e[0m\n\n", str);
	duplicated = strdup(str);
	printf("'%s' <-    strdup\n", duplicated);
	free(duplicated);
	duplicated = ft_strdup(str);
	printf("'%s' <- ft_strdup\n", duplicated);
	free(duplicated);
}

void			draw_kitten(void)
{
printf("⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
printf("⣿⣿⣿⣵⣿⣿⣿⠿⡟⣛⣧⣿⣯⣿⣝⡻⢿⣿⣿⣿⣿⣿⣿⣿\n");
printf("⣿⣿⣿⣿⣿⠋⠁⣴⣶⣿⣿⣿⣿⣿⣿⣿⣦⣍⢿⣿⣿⣿⣿⣿\n");
printf("⣿⣿⣿⣿⢷⠄⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢼⣿⣿⣿⣿\n");
printf("⢹⣿⣿⢻⠎⠔⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⣿⣿⣿⣿\n");
printf("⢸⣿⣿⠇⡶⠄⣿⣿⠿⠟⡛⠛⠻⣿⡿⠿⠿⣿⣗⢣⣿⣿⣿⣿\n");
printf("⠐⣿⣿⡿⣷⣾⣿⣿⣿⣾⣶⣶⣶⣿⣁⣔⣤⣀⣼⢲⣿⣿⣿⣿\n");
printf("⠄⣿⣿⣿⣿⣾⣟⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⢟⣾⣿⣿⣿⣿\n");
printf("⠄⣟⣿⣿⣿⡷⣿⣿⣿⣿⣿⣮⣽⠛⢻⣽⣿⡇⣾⣿⣿⣿⣿⣿\n");
printf("⠄⢻⣿⣿⣿⡷⠻⢻⡻⣯⣝⢿⣟⣛⣛⣛⠝⢻⣿⣿⣿⣿⣿⣿\n");
printf("⠄⠸⣿⣿⡟⣹⣦⠄⠋⠻⢿⣶⣶⣶⡾⠃⡂⢾⣿⣿⣿⣿⣿⣿\n");
printf("⠄⠄⠟⠋⠄⢻⣿⣧⣲⡀⡀⠄⠉⠱⣠⣾⡇⠄⠉⠛⢿⣿⣿⣿\n");
printf("⠄⠄⠄⠄⠄⠈⣿⣿⣿⣷⣿⣿⢾⣾⣿⣿⣇⠄⠄⠄⠄⠄⠉⠉\n");
printf("⠄⠄⠄⠄⠄⠄⠸⣿⣿⠟⠃⠄⠄⢈⣻⣿⣿⠄⠄⠄⠄⠄⠄⠄\n");
printf("⠄⠄⠄⠄⠄⠄⠄⢿⣿⣾⣷⡄⠄⢾⣿⣿⣿⡄⠄⠄⠄⠄⠄⠄\n");
printf("⠄⠄⠄⠄⠄⠄⠄⠸⣿⣿⣿⠃⠄⠈⢿⣿⣿⠄⠄⠄⠄⠄⠄⠄\n");
}

int				main(void)
{
	char	cmd[5];

	system("clear");
	printf("\e[1;34m");
	draw_kitten();
	printf("\e[0m");
	while (*cmd != 'e' && *cmd != 'E')
	{
		printf("\nВыбери функцию для тестирования:\n");
		printf("\e[4;1;37m");
		printf("	ft_strlen - 1\n");
		printf("	ft_strcpy - 2\n");
		printf("	ft_strcmp - 3\n");
		printf("	ft_write  - 4\n");
		printf("	ft_read   - 5\n");
		printf("	ft_strdup - 6\n");
		printf("\e[1;31m");
		printf("E - Выход;\n");
		printf("\e[0m");
		scanf("%s", cmd);
		if (strlen(cmd) != 1)
		{
			system("clear");
			continue ;
		}
		else if (*cmd == '1')
			test_strlen();
		else if (*cmd == '2')
			test_strcpy();
		else if (*cmd == '3')
			test_strcmp();
		else if (*cmd == '4')
			test_write();
		else if (*cmd == '5')
			test_read();
		else if (*cmd == '6')
			test_strdup();
		else
			system("clear");
	}
	return (0);
}