/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:15:15 by amerlon-          #+#    #+#             */
/*   Updated: 2018/11/29 19:09:13 by amerlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/* COLORS */
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

void	f_striter_func(char *c)
{
	*c = 'A';
}


void	f_striteri_func(unsigned int index, char *c)
{
	*c = index % 10 + 48;
}

char	f_strmapi_func(unsigned int index, char c)
{
	return index % 10 + 48;
}

int main(void)
{
	
	/* FT_MEMALLOC */
	printf("\n");
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_MEMALLOC\n\n");
	char *res0 = ft_memalloc(4);
	if (res0[0] == '\0' || res0[1] == '\0' || res0[2] == '\0' || res0[3] == '\0')
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
	}

	/* FT_MEMDEL */
	printf("\n");
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_MEMDEL\n\n");
	ft_memdel(&res0);
	if (!res0)
		printf(GRN "OK BUT CHECK CODE FOR MEM FREE!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	else
	{
		printf(RED "FAIL\n");
	}
	free(res0);

	printf(CYN "\nTesting seg fault 1");
	ft_memdel(NULL);

	printf(CYN "\nTesting seg fault 2");
	char f_memdel = NULL;
	ft_memdel(&f_memdel);

	/* FT_STRNEW */
	printf("\n");
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRNEW\n\n");
	char *f_strnew = ft_strnew(4);
	if (f_strnew[0] == '\0' || f_strnew[1] == '\0' || f_strnew[2] == '\0' || f_strnew[3] == '\0' || f_strnew[3] == '\0')
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
	}

	/* FT_STRDEL */
	printf("\n");
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRDEL\n\n");
	ft_memdel(&f_strnew);
	if (!f_strnew)
		printf(GRN "OK BUT CHECK CODE FOR MEM FREE!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	else
	{
		printf(RED "FAIL\n");
	}
	free(res0);

	printf(CYN "\nTesting seg fault 1");
	ft_strdel(NULL);

	printf(CYN "\nTesting seg fault 2");
	char f_strdel = NULL;
	ft_strdel(&f_strdel);

	/* FT_STRCLR */
	printf("\n");
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRCLR\n\n");
	char f_strclr[] = "asdf";
	ft_strclr(f_strclr);
	if (f_strclr[0] == '\0' || f_strclr[1] == '\0' || f_strclr[2] == '\0' || f_strclr[3] == '\0' || f_strclr[3] == '\0')
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
	}
	free(res0);

	printf(CYN "\nTesting seg fault 1");
	ft_strclr(NULL);

	/* FT_STRITER */
	printf("\n");
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRITER\n\n");
	char f_striter[] = "asdf";
	ft_striter(f_striter, &f_striter_func);
	if (strcmp("AAAA", f_striter) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "AAAA");
		printf(RED "Received: %s\n", f_striter);
	}

	printf(CYN "\nTesting seg fault 1");
	ft_striter(NULL, &f_striter_func);

	printf(CYN "\nTesting seg fault 2");
	ft_striter(f_striter, NULL);

	printf(CYN "\nTesting seg fault 3");
	ft_striter(NULL, NULL);

	/* FT_STRITERI */
	printf("\n");
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRITERI\n\n");
	char f_striteri[] = "asdf";
	ft_striteri(f_striteri, &f_striteri_func);
	if (strcmp("0123", f_striteri) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "0123");
		printf(RED "Received: %s\n", f_striteri);
	}

	printf(CYN "\nTesting seg fault 1");
	ft_striteri(NULL, &f_striteri_func);

	printf(CYN "\nTesting seg fault 2");
	ft_striteri(f_striteri, NULL);

	printf(CYN "\nTesting seg fault 3");
	ft_striteri(NULL, NULL);

	/* FT_STRMAP */
	printf("\n");
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRMAP\n\n");
	char *f_strmap = ft_strmap("asdf", &ft_toupper);
	if (strcmp("ASDF", f_strmap) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "ASDF");
		printf(RED "Received: %s\n", f_strmap);
	}
	free(f_strmap);

	printf(CYN "\nTesting seg fault 1");
	ft_striteri(NULL, &ft_toupper);

	printf(CYN "\nTesting seg fault 2");
	ft_striteri("asdf", NULL);

	printf(CYN "\nTesting seg fault 3");
	ft_striteri(NULL, NULL);

	/* FT_STRMAPI */
	printf("\n");
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRMAPI\n\n");
	char *f_strmapi = ft_strmapi("asdf", &f_strmapi_func);
	if (strcmp("0123", f_strmapi) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "0123");
		printf(RED "Received: %s\n", f_strmapi);
	}
	free(f_strmapi);

	printf(CYN "\nTesting seg fault 1");
	ft_striteri(NULL, &f_strmapi_func);

	printf(CYN "\nTesting seg fault 2");
	ft_striteri("asdf", NULL);

	printf(CYN "\nTesting seg fault 3");
	ft_striteri(NULL, NULL);

	/* FT_STREQU */
	printf("\n");
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STREQU\n\n");
	printf(CYN "%s - %s\n", "yasgdiy", "ya");
	int res1 = 0;
	int res2 = ft_strequ("yasgdiy", "ya");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "", "");
	res1 = 1;
	res2 = ft_strequ("", "");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "a", "");
	res1 = 0;
	res2 = ft_strequ("a", "");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "dfghjkasfhb", "dfghjkasfhb");
	res1 = 1;
	res2 = ft_strequ("dfghjkasfhb", "dfghjkasfhb");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "dfghjkasfha", "dfghjkasfhb");
	res1 = 0;
	res2 = ft_strequ("dfghjkasfha", "dfghjkasfhb");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "dfghjkasfh", "dfghjkasfhb");
	res1 = 0;
	res2 = ft_strequ("dfghjkasfh", "dfghjkasfhb");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(CYN "\nTesting seg fault 1");
	ft_strequ(NULL, "asd");

	printf(CYN "\nTesting seg fault 2");
	ft_strequ("asd", NULL);

	printf(CYN "\nTesting seg fault 3");
	ft_strequ(NULL, NULL);

	/* FT_STRNEQU*/
	printf("\n");
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRNEQU\n\n");
	printf(WHT "String: ");
	printf(CYN "%s - %s\n", "yasgdiy", "ya");
	res1 = 0;
	res2 = ft_strnequ("yasgdiy", "ya", 3);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "", "");
	res1 = 1;
	res2 = ft_strnequ("", "", 0);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "a", "");
	res1 = 0;
	res2 = ft_strnequ("a", "", 1);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "dfghjkasfhb", "dfghjkasfhb");
	res1 = 1;
	res2 = ft_strnequ("dfghjkasfhb", "dfghjkasfhb", 11);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "dfghjkasfha", "dfghjkasfhb");
	res1 = 1;
	res2 = ft_strnequ("dfghjkasfha", "dfghjkasfhb", 10);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "dfghjkasfh", "dfghjkasfhb");
	res1 = 1;
	res2 = ft_strnequ("dfghjkasfh", "dfghjkasfhb", 3);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(CYN "\nTesting seg fault 1");
	ft_strnequ(NULL, "asd", 1);

	printf(CYN "\nTesting seg fault 2");
	ft_strnequ("asd", NULL, 1);

	printf(CYN "\nTesting seg fault 3");
	ft_strnequ(NULL, NULL, 1);


	/* FT_STRJOIN*/
	printf("\n");
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRJOIN\n\n");
	printf(WHT "String: ");
	printf(CYN "%s - %s\n", "yasgdiy", "ya");
	res0 = ft_strjoin("yasgdiy", "ya");
	if (strcmp(res0, "yasgdiyya") == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "yasgdiyya");
		printf(RED "Received: %s\n", res0);
	}
	free(res0);

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "", "ya");
	res0 = ft_strjoin("", "ya");
	if (strcmp(res0, "ya") == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "ya");
		printf(RED "Received: %s\n", res0);
	}
	free(res0);

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "as", "");
	res0 = ft_strjoin("as", "");
	if (strcmp(res0, "as") == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "as");
		printf(RED "Received: %s\n", res0);
	}
	free(res0);

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "", "");
	res0 = ft_strjoin("", "");
	if (strcmp(res0, "") == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "");
		printf(RED "Received: %s\n", res0);
	}
	free(res0);

	printf(CYN "\nTesting seg fault 1");
	ft_strjoin(NULL, "asd");

	printf(CYN "\nTesting seg fault 2");
	ft_strjoin("asd", NULL);

	printf(CYN "\nTesting seg fault 3");
	ft_strjoin(NULL, NULL);

	/* FT_STRTRIM*/
	printf("\n");
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRTRIM\n\n");
	printf(WHT "String: ");
	printf(CYN "%s\n", " \n\t  yasgdiy \n   ");
	res0 = ft_strtrim( "yasgdiy");
	if (strcmp(res0, "yasgdiy") == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "yasgdiy");
		printf(RED "Received: %s\n", res0);
	}
	free(res0);

	printf(WHT "\nString: ");
	printf(CYN "%s\n", "yasgdiy");
	res0 = ft_strtrim( "yasgdiy");
	if (strcmp(res0, "yasgdiy") == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "yasgdiy");
		printf(RED "Received: %s\n", res0);
	}
	free(res0);

	printf(WHT "\nString: ");
	printf(CYN "%s\n", "   yasgdiy");
	res0 = ft_strtrim( "   yasgdiy");
	if (strcmp(res0, "yasgdiy") == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "yasgdiy");
		printf(RED "Received: %s\n", res0);
	}
	free(res0);

	printf(WHT "\nString: ");
	printf(CYN "%s\n", "yasgdiy   ");
	res0 = ft_strtrim( "yasgdiy   ");
	if (strcmp(res0, "yasgdiy") == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "yasgdiy");
		printf(RED "Received: %s\n", res0);
	}
	free(res0);

	printf(WHT "\nString: ");
	printf(CYN "%s\n", "");
	res0 = ft_strtrim( "");
	if (strcmp(res0, "") == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "");
		printf(RED "Received: %s\n", res0);
	}
	free(res0);

	printf(WHT "\nString: ");
	printf(CYN "%s\n", "   ");
	res0 = ft_strtrim( "   ");
	if (strcmp(res0, "") == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "");
		printf(RED "Received: %s\n", res0);
	}
	free(res0);

	printf(WHT "\nString: ");
	printf(CYN "%s\n", " a   s  ");
	res0 = ft_strtrim( " a   s  ");
	if (strcmp(res0, "a   s") == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", "a   s");
		printf(RED "Received: %s\n", res0);
	}
	free(res0);
}