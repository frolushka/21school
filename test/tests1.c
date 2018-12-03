/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:36:29 by amerlon-          #+#    #+#             */
/*   Updated: 2018/11/29 19:25:21 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "../libft/libft.h"

/* COLORS */
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

static char *rand_string(size_t size)
{
	char *str = malloc(size);
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK";
	if (size)
	{
		--size;
		for (size_t n = 0; n < size; n++)
		{
			int key = rand() % (int)(sizeof charset - 1);
			str[n] = charset[key];
		}
		str[size] = '\0';
	}
	return str;
}

/* Random string generator */
static char *gen_string(int lower, int upper)
{
	srand(time(NULL));
	return rand_string((rand() % (upper - lower)) + lower);
}

int main(void)
{
	char *str;
	char *str2;
	int res1;
	int res2;
	char *cres1;
	char *cres2;

	// cres1 = gen_string(5, 15);
	// cres2 = gen_string(5, 15);

	/* FT_STRLEN */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRLEN\n\n");
	printf(MAG "Random string tests\n");
	str = gen_string(5, 15);
	printf(WHT "String: ");
	printf(CYN "%s\n", str);
	res1 = strlen(str);
	res2 = ft_strlen(str);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}
	free(str);

	printf(WHT "\nString: ");
	str = gen_string(5, 15);
	printf(CYN "%s\n", str);
	res1 = strlen(str);
	res2 = ft_strlen(str);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}
	free(str);

	printf(MAG "\nEmpty string test\n");
	res1 = strlen("");
	res2 = ft_strlen("");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	/* FT_ISALPHA */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_ISALPHA\n\n");
	printf(WHT "Number: ");
	printf(CYN "%d\n", 65);
	res1 = isalpha(65);
	res2 = ft_isalpha(65);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 122);
	res1 = isalpha(122);
	res2 = ft_isalpha(122);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 123);
	res1 = isalpha(123);
	res2 = ft_isalpha(123);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	/* FT_ISDIGIT */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_ISDIGIT\n\n");
	printf(WHT "Number: ");
	printf(CYN "%d\n", 48);
	res1 = isdigit(48);
	res2 = ft_isdigit(48);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 47);
	res1 = isdigit(47);
	res2 = ft_isdigit(47);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 57);
	res1 = isdigit(57);
	res2 = ft_isdigit(57);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	/* FT_ISALNUM */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_ISALNUM\n\n");
	printf(WHT "Number: ");
	printf(CYN "%d\n", 50);
	res1 = isalnum(50);
	res2 = ft_isalnum(50);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 47);
	res1 = isalnum(47);
	res2 = ft_isalnum(47);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 75);
	res1 = isalnum(75);
	res2 = ft_isalnum(75);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 99);
	res1 = isalnum(99);
	res2 = ft_isalnum(99);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	/* FT_ISASCII */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_ISASCII\n\n");
	printf(WHT "Number: ");
	printf(CYN "%d\n", 48);
	res1 = isascii(48);
	res2 = ft_isascii(48);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 127);
	res1 = isascii(127);
	res2 = ft_isascii(127);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 128);
	res1 = isascii(128);
	res2 = ft_isascii(128);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", -3);
	res1 = isascii(-3);
	res2 = ft_isascii(-3);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	/* FT_ISPRINT */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_ISPRINT\n\n");
	printf(WHT "Number: ");
	printf(CYN "%d\n", 31);
	res1 = isprint(31);
	res2 = ft_isprint(31);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 32);
	res1 = isprint(32);
	res2 = ft_isprint(32);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 126);
	res1 = isprint(126);
	res2 = ft_isprint(126);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	/* FT_TOUPPER */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_TOUPPER\n\n");
	printf(WHT "Number: ");
	printf(CYN "%d\n", 64);
	res1 = toupper(64);
	res2 = ft_toupper(64);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 67);
	res1 = toupper(67);
	res2 = ft_toupper(67);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 100);
	res1 = toupper(100);
	res2 = ft_toupper(100);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 126);
	res1 = toupper(126);
	res2 = ft_toupper(126);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	/* FT_TOLOWER */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_TOLOWER\n\n");
	printf(WHT "Number: ");
	printf(CYN "%d\n", 64);
	res1 = tolower(64);
	res2 = ft_tolower(64);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 67);
	res1 = tolower(67);
	res2 = ft_tolower(67);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 100);
	res1 = tolower(100);
	res2 = ft_tolower(100);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nNumber: ");
	printf(CYN "%d\n", 126);
	res1 = tolower(126);
	res2 = ft_tolower(126);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	/* FT_ATOI */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_ATOI\n\n");
	printf(WHT "String: ");
	printf(CYN "%s\n", "");
	res1 = atoi("");
	res2 = ft_atoi("");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s\n", "  \n\t\v\f\r42");
	res1 = atoi("  \n\t\v\f\r42");
	res2 = ft_atoi("  \n\t\v\f\r42");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s\n", "  \n\t\v\f\r-42");
	res1 = atoi("  \n\t\v\f\r-42");
	res2 = ft_atoi("  \n\t\v\f\r-42");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s\n", "2147483647");
	res1 = atoi("2147483647");
	res2 = ft_atoi("2147483647");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s\n", "-2147483648");
	res1 = atoi("-2147483648");
	res2 = ft_atoi("-2147483648");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s\n", "asd42");
	res1 = atoi("asd42");
	res2 = ft_atoi("asd42");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s\n", "2142");
	res1 = atoi("2142");
	res2 = ft_atoi("2142");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s\n", "2142 123");
	res1 = atoi("2142 123");
	res2 = ft_atoi("2142 123");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s\n", "+12312");
	res1 = atoi("+12312");
	res2 = ft_atoi("+12312");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s\n", "-+12312");
	res1 = atoi("-+12312");
	res2 = ft_atoi("-+12312");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	/* FT_STRDUP*/
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRDUP\n\n");
	printf(MAG "Random string tests\n");
	char *str1 = gen_string(5, 15);
	printf(WHT "String: ");
	printf(CYN "%s\n", str1);
	cres1 = strdup(str1);
	cres2 = ft_strdup(str1);
	if (strcmp(cres1, cres2) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", cres1);
		printf(RED "Received: %s\n", cres2);
	}
	free(str1);
	free(cres1);
	free(cres2);

	printf(WHT "\nString: ");
	str = "asd";
	printf(CYN "%s\n", str);
	cres1 = strdup(str);
	cres2 = ft_strdup(str);
	if (!strcmp(cres1, cres2))
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", cres1);
		printf(RED "Received: %s\n", cres2);
	}
	free(cres1);
	free(cres2);

	printf(WHT "\nString: ");
	str = "";
	printf(CYN "%s\n", str);
	cres1 = strdup(str);
	cres2 = ft_strdup(str);
	if (!strcmp(cres1, cres2))
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", cres1);
		printf(RED "Received: %s\n", cres2);
	}
	free(cres1);
	free(cres2);

	/* FT_STRCPY*/
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRCPY\n\n");
	printf(WHT "String: ");
	char str3[] = "isasdas";
	char str4[] = "afysa";
	printf(CYN "%s - %s\n", str3, str4);
	if (strcmp(strcpy(str3, str4), ft_strcpy(str3, str4)) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", strcpy(str3, str4));
		printf(RED "Received: %s\n", ft_strcpy(str3, str4));
	}

	printf(WHT "\nString: ");
	char str5[] = "isasdas";
	char str6[] = "asdffff";
	printf(CYN "%s - %s\n", str5, str6);
	if (strcmp(strcpy(str5, str6), ft_strcpy(str5, str6)) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", strcpy(str5, str6));
		printf(RED "Received: %s\n", ft_strcpy(str5, str6));
	}

	printf(WHT "\nString: ");
	char str7[100] = "";
	char str8[100] = "";
	printf(CYN "%s - %s\n", str7, str8);
	if (strcmp(strcpy(str7, str8), ft_strcpy(str7, str8)) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", strcpy(str7, str8));
		printf(RED "Received: %s\n", ft_strcpy(str7, str8));
	}

	/* FT_STRNCPY*/
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRNCPY\n\n");
	printf(WHT "String: ");
	printf(CYN "%s - %s\n", str3, str4);
	if (strcmp(strncpy(str3, str4, 2), ft_strncpy(str3, str4, 2)) == 0 && ft_strncpy(str3, str4, 2)[strlen(str3)] == '\0')
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s|\n", strncpy(str3, str4, 2));
		printf(RED "Received: %s|\n", ft_strncpy(str3, str4, 2));
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", str5, str6);
	if (strcmp(strncpy(str5, str6, 3), ft_strncpy(str5, str6, 3)) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", strncpy(str5, str6, 3));
		printf(RED "Received: %s\n", ft_strncpy(str5, str6, 3));
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", str7, str8);
	if (strcmp(strncpy(str7, str8, 1), ft_strncpy(str7, str8, 1)) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", strncpy(str7, str8, 1));
		printf(RED "Received: %s\n", ft_strncpy(str7, str8, 1));
	}

	/* FT_STRCAT*/
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRCAT\n\n");
	printf(WHT "String: ");
	char t1[30] = "123";
	printf(CYN "%s - %s\n", t1, "asda");
	if (strcmp(strcat(t1, "asda"), ft_strcat(t1, "asda")) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", strcat(t1, "asda"));
		printf(RED "Received: %s\n", ft_strcat(t1, "asda"));
	}

	printf(WHT "\nString: ");
	char t2[10] = "";
	printf(CYN "%s - %s\n", t2, "");
	if (strcmp(strcat(t2, ""), ft_strcat(t2, "")) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", strcat(t2, ""));
		printf(RED "Received: %s\n", ft_strcat(t2, ""));
	}

	/* FT_STRNCAT*/
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRNCAT\n\n");
	printf(WHT "String: ");
	printf(CYN "%s - %s\n", t1, "asda");
	if (strcmp(strncat(t1, "asda", 2), ft_strncat(t1, "asda", 2)) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", strncat(t1, "asda", 2));
		printf(RED "Received: %s\n", ft_strncat(t1, "asda", 2));
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", t2, "");
	if (strcmp(strncat(t2, "", 0), ft_strncat(t2, "", 0)) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s\n", strncat(t2, "", 0));
		printf(RED "Received: %s\n", ft_strncat(t2, "", 0));
	}

	/* FT_STRLCAT*/
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRLCAT\n\n");
	printf(WHT "String: ");
	printf(CYN "%s - %s\n", t1, "asda");
	char strlcat1[10] = "asd";
	size_t res3 = strlcat(strlcat1, "asda", 10);
	char strlcat2[10] = "asd";
	size_t res4 = ft_strlcat(strlcat2, "asda", 10);
	if (res3 = res4)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d - %s|\n", (int)res3, strlcat1);
		printf(RED "Received: %d - %s|\n", (int)res4, strlcat2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strlcat1, "");
	res3 = strlcat(strlcat1, "", 10);
	res4 = ft_strlcat(strlcat2, "", 10);
	if (res3 == res4)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d - %s|\n", (int)res3, strlcat1);
		printf(RED "Received: %d - %s|\n", (int)res4, strlcat2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strlcat1, "a");
	res3 = strlcat(strlcat1, "a", 10);
	res4 = ft_strlcat(strlcat2, "a", 10);
	if (res3 == res4)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d - %s|\n", (int)res3, strlcat1);
		printf(RED "Received: %d - %s|\n", (int)res4, strlcat2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "there is no stars in the sky", "the cake is a lie !\0I'm hidden lol\r\n");
	char *f_strlcat = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
	res3 = strlcat(buff1, f_strlcat, max);
	res4 = ft_strlcat(buff2, f_strlcat, max);
	if (res3 == res4)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d - %s|\n", (int)res3, buff1);
		printf(RED "Received: %d - %s|\n", (int)res4, buff2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "\0AAAAAAA", "n\0AA");
	char *f_strlcat1 = "n\0AAA";
	char buff3[0xF00] = "\0AAAAAA";
	char buff4[0xF00] = "\0AAAAAA";
	res3 = strlcat(buff3, f_strlcat1, 10);
	res4 = ft_strlcat(buff4, f_strlcat1, 10);
	if (res3 == res4)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d - %s|\n", (int)res3, buff3);
		printf(RED "Received: %d - %s|\n", (int)res4, buff4);
	}

	/* FT_STRCHR*/
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRCHR\n\n");
	printf(WHT "String: ");
	char *strchr_test = "asdas";
	printf(CYN "%s - %s\n", strchr_test, "a");
	char *strchr1 = strchr(strchr_test, 'a');
	char *strchr2 = ft_strchr(strchr_test, 'a');
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "s");
	strchr1 = strchr(strchr_test, 's');
	strchr2 = ft_strchr(strchr_test, 's');
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "b");
	strchr1 = strchr(strchr_test, 'b');
	strchr2 = ft_strchr(strchr_test, 'b');
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "\0");
	strchr1 = strchr(strchr_test, '\0');
	strchr2 = ft_strchr(strchr_test, '\0');
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	/* FT_STRRCHR*/
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRRCHR\n\n");
	printf(WHT "String: ");
	printf(CYN "%s - %s\n", strchr_test, "a");
	strchr1 = strrchr(strchr_test, 'a');
	strchr2 = ft_strrchr(strchr_test, 'a');
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p - %s\n", strchr1, strchr1);
		printf(RED "Received: %p - %s\n", strchr2, strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "s");
	strchr1 = strrchr(strchr_test, 's');
	strchr2 = ft_strrchr(strchr_test, 's');
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "b");
	strchr1 = strrchr(strchr_test, 'b');
	strchr2 = ft_strrchr(strchr_test, 'b');
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p - %s\n", strchr1, strchr1);
		printf(RED "Received: %p - %s\n", strchr2, strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "\0");
	strchr1 = strrchr(strchr_test, '\0');
	strchr2 = ft_strrchr(strchr_test, '\0');
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "s");
	strchr1 = strrchr(strchr_test, 's');
	strchr2 = ft_strrchr(strchr_test, 's');
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	/* FT_STRSTR*/
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRSTR\n\n");
	printf(WHT "String: ");
	printf(CYN "%s - %s\n", strchr_test, "a");
	strchr1 = strstr(strchr_test, "a");
	strchr2 = ft_strstr(strchr_test, "a");
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "as");
	strchr1 = strstr(strchr_test, "as");
	strchr2 = ft_strstr(strchr_test, "as");
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "asd");
	strchr1 = strstr(strchr_test, "asd");
	strchr2 = ft_strstr(strchr_test, "asd");
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "asdas");
	strchr1 = strstr(strchr_test, "asdas");
	strchr2 = ft_strstr(strchr_test, "asdas");
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "ds");
	strchr1 = strstr(strchr_test, "ds");
	strchr2 = ft_strstr(strchr_test, "ds");
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "asdasd", "");
	strchr1 = strstr("asdasd", "");
	strchr2 = ft_strstr("asdasd", "");
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "", "");
	strchr1 = strstr("", "");
	strchr2 = ft_strstr("", "");
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "abc", "ac");
	strchr1 = strstr("abc", "ac");
	strchr2 = ft_strstr("abc", "ac");
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}


	/* FT_STRNSTR*/
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRNSTR\n\n");
	printf(WHT "String: ");
	printf(CYN "%s - %s\n", strchr_test, "a");
	strchr1 = strnstr(strchr_test, "a", 1);
	strchr2 = ft_strnstr(strchr_test, "a", 1);
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "as");
	strchr1 = strnstr(strchr_test, "ad", 2);
	strchr2 = ft_strnstr(strchr_test, "ad", 2);
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "asd");
	strchr1 = strnstr(strchr_test, "asd", 4);
	strchr2 = ft_strnstr(strchr_test, "asd", 4);
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", strchr1);
		printf(RED "Received: %p\n", strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "asdas");
	strchr1 = strnstr(strchr_test, "asdas", 5);
	strchr2 = ft_strnstr(strchr_test, "asdas", 5);
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p - %s\n", strchr1, strchr1);
		printf(RED "Received: %p - %s\n", strchr2, strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", strchr_test, "ds");
	strchr1 = strnstr(strchr_test, "ds", 1);
	strchr2 = ft_strnstr(strchr_test, "ds", 1);
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p - %s\n", strchr1, strchr1);
		printf(RED "Received: %p - %s\n", strchr2, strchr2);
	}

	// MZIRIBMZIRIBMZE123
	// 		 MZIRIBMZE
	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "MZIRIBMZIRIBMZE123", "MZIRIBMZE");
	strchr1 = strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 9);
	strchr2 = ft_strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 9);
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p - %s\n", strchr1, strchr1);
		printf(RED "Received: %p - %s\n", strchr2, strchr2);
	}

	printf(WHT "\nString: ");
	printf(CYN "%s - %s\n", "asasas", "sasd");
	strchr1 = strnstr("asasas", "sasd", 3);
	strchr2 = ft_strnstr("asasas", "sasd", 3);
	if (strchr1 == strchr2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p - %s\n", strchr1, strchr1);
		printf(RED "Received: %p - %s\n", strchr2, strchr2);
	}


	/* FT_STRCMP*/
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRCMP\n\n");
	printf(WHT "String: ");
	printf(CYN "%s - %s\n", "yasgdiy", "ya");
	res1 = strcmp("yasgdiy", "ya");
	res2 = ft_strcmp("yasgdiy", "ya");
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
	res1 = strcmp("", "");
	res2 = ft_strcmp("", "");
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
	res1 = strcmp("a", "");
	res2 = ft_strcmp("a", "");
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
	res1 = strcmp("dfghjkasfhb", "dfghjkasfhb");
	res2 = ft_strcmp("dfghjkasfhb", "dfghjkasfhb");
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
	res1 = strcmp("dfghjkasfha", "dfghjkasfhb");
	res2 = ft_strcmp("dfghjkasfha", "dfghjkasfhb");
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
	res1 = strcmp("dfghjkasfh", "dfghjkasfhb");
	res2 = ft_strcmp("dfghjkasfh", "dfghjkasfhb");
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	/* FT_STRNCMP*/
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_STRNCMP\n\n");
	printf(WHT "String: ");
	printf(CYN "%s - %s\n", "yasgdiy", "ya");
	res1 = strncmp("yasgdiy", "ya", 3);
	res2 = ft_strncmp("yasgdiy", "ya", 3);
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
	res1 = strncmp("", "", 0);
	res2 = ft_strncmp("", "", 0);
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
	res1 = strncmp("a", "", 1);
	res2 = ft_strncmp("a", "", 1);
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
	res1 = strncmp("dfghjkasfhb", "dfghjkasfhb", 11);
	res2 = ft_strncmp("dfghjkasfhb", "dfghjkasfhb", 11);
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
	res1 = strncmp("dfghjkasfha", "dfghjkasfhb", 10);
	res2 = ft_strncmp("dfghjkasfha", "dfghjkasfhb", 10);
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
	res1 = strncmp("dfghjkasfh", "dfghjkasfhb", 3);
	res2 = ft_strncmp("dfghjkasfh", "dfghjkasfhb", 3);
	if (res1 == res2)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", res1);
		printf(RED "Received: %d\n", res2);
	}

	/* FT_BZERO */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_BZERO\n\n");
	char bzero1[4] = "asda";
	ft_bzero(bzero1, 5);
	if (bzero1[0] == '\0' && bzero1[1] == '\0' && bzero1[2] == '\0' && bzero1[3] == '\0' && bzero1[4] == '\0')
		printf(GRN "OK\n");
	else
		printf(RED "FAIL\n");

	/* FT_MEMSET */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_MEMSET\n\n");
	char bzero2[4] = "asda";
	ft_memset(bzero2, '\0', 5);
	if (bzero2[0] == '\0' && bzero2[1] == '\0' && bzero2[2] == '\0' && bzero2[3] == '\0' && bzero2[4] == '\0')
		printf(GRN "OK\n");
	else
		printf(RED "FAIL\n");

	char bzero3[4] = "asda";
	ft_memset(bzero3, '\0', 5);
	if (bzero3[0] == '\0' && bzero3[1] == '\0' && bzero3[2] == '\0' && bzero3[3] == '\0' && bzero3[4] == '\0')
		printf(GRN "OK\n");
	else
		printf(RED "FAIL\n");

	/* FT_MEMCMP */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_MEMCMP\n\n");
	char *f_memcmp1 = "asfgg";
	char *f_memcmp2 = "asfga";
	if (memcmp(f_memcmp1, f_memcmp2, 5) == ft_memcmp(f_memcmp1, f_memcmp2, 5))
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", memcmp(f_memcmp1, f_memcmp2, 5));
		printf(RED "Received: %d\n", ft_memcmp(f_memcmp1, f_memcmp2, 5));
	}

	char *f_memcmp3 = "";
	char *f_memcmp4 = "";
	if (memcmp(f_memcmp3, f_memcmp4, 5) == ft_memcmp(f_memcmp3, f_memcmp4, 5))
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", memcmp(f_memcmp3, f_memcmp4, 5));
		printf(RED "Received: %d\n", ft_memcmp(f_memcmp3, f_memcmp4, 5));
	}

	char *f_memcmp5 = "asd";
	char *f_memcmp6 = "asd";
	if (memcmp(f_memcmp5, f_memcmp6, 5) == ft_memcmp(f_memcmp5, f_memcmp6, 5))
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", memcmp(f_memcmp5, f_memcmp6, 5));
		printf(RED "Received: %d\n", ft_memcmp(f_memcmp5, f_memcmp6, 5));
	}

	char *f_memcmp7 = "asd\0";
	char *f_memcmp8 = "asdd";
	if (memcmp(f_memcmp7, f_memcmp8, 4) == ft_memcmp(f_memcmp7, f_memcmp8, 4))
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", memcmp(f_memcmp7, f_memcmp8, 4));
		printf(RED "Received: %d\n", ft_memcmp(f_memcmp7, f_memcmp8, 4));
	}

	/* FT_MEMCHR */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_MEMCHR\n\n");
	char *f_memchr1 = "asdfgh";
	if (ft_memchr(f_memchr1, 'f', 4) == memchr(f_memchr1, 'f', 4))
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", memchr(f_memchr1, 'f', 4));
		printf(RED "Received: %p\n", ft_memchr(f_memchr1, 'f', 4));
	}

	if (ft_memchr(f_memchr1, 'g', 4) == memchr(f_memchr1, 'g', 4))
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", memchr(f_memchr1, 'g', 4));
		printf(RED "Received: %p\n", ft_memchr(f_memchr1, 'g', 4));
	}

	/* FT_MEMMOVE */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_MEMMOVE\n\n");
	char f_memmove1[] = "asdfgh";
	char f_memmove2[] = "qwes";
	char f_memmove3[] = "asdfgh";
	char f_memmove4[] = "qwes";
	memmove(f_memmove2, f_memmove1, 3);
	ft_memmove(f_memmove4, f_memmove3, 3);
	if (memcmp(f_memmove2, f_memmove4, 3) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", f_memmove2);
		printf(RED "Received: %p\n", f_memmove4);
	}

	char f_memmove5[] = "asdfgh";
	char f_memmove6[] = "asdfgh";
	memmove(f_memmove5 + 2, f_memmove5, 3);
	ft_memmove(f_memmove6 + 2, f_memmove6, 3);
	if (memcmp(f_memmove5, f_memmove6, 3) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", f_memmove5);
		printf(RED "Received: %p\n", f_memmove6);
	}

	char f_memmove7[] = "";
	char f_memmove8[] = "";
	memmove(f_memmove7, f_memmove8, 1);
	ft_memmove(f_memmove7, f_memmove8, 1);
	if (memcmp(f_memmove7, f_memmove8, 1) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", f_memmove7);
		printf(RED "Received: %p\n", f_memmove8);
	}

	char f_memmove9[] = "";
	memmove(f_memmove9, f_memmove9, 1);
	ft_memmove(f_memmove9, f_memmove9, 1);
	if (memcmp(f_memmove9, f_memmove9, 1) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %p\n", f_memmove9);
		printf(RED "Received: %p\n", f_memmove9);
	}

	printf(CYN "\nTesting seg fault 2\n");
	memmove(NULL, NULL, 1);
	ft_memmove(NULL, NULL, 1);


	/* FT_MEMCPY */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_MEMCPY\n\n");
	char memcp1[] = "asd\0";
	char memcp2[] = "asd\0";
	char memcp3[] = "qwe\0";
	char memcp4[] = "qwe\0";
	memcpy(memcp1, memcp3, 4);
	ft_memcpy(memcp2, memcp4, 4);
	if (memcmp(memcp1, memcp2, 4) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", memcp1);
		printf(RED "Received: %d\n", memcp2);
	}

	char memcp5[] = "";
	char memcp6[] = "";
	char memcp7[] = "";
	char memcp8[] = "";
	memcpy(memcp5, memcp7, 1);
	ft_memcpy(memcp6, memcp8, 1);
	if (memcmp(memcp5, memcp6, 1) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %d\n", memcp5);
		printf(RED "Received: %d\n", memcp6);
	}

	/* FT_MEMCCPY */
	printf(WHT "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
	printf(YEL "FT_MEMCCPY\n\n");
	char memccp1[] = "asd\0";
	char memccp2[] = "asd\0";
	char memccp3[] = "qwe\0";
	char memccp4[] = "qwe\0";
	memccpy(memccp1, memccp3, 'a', 4);
	char *r_memcpp1 = ft_memccpy(memccp2, memccp4, 'a', 4);
	if (memcmp(memccp1, memccp2, 4) == 0 && r_memcpp1 == NULL)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s - (null)\n", memccp1);
		printf(RED "Received: %s - %p\n", memccp2, r_memcpp1);
	}

	char memccp5[] = "asd\0";
	char memccp6[] = "asd\0";
	char memccp7[] = "qwe\0";
	char memccp8[] = "qwe\0";
	char *r_memcpp2 = memccpy(memccp5, memccp7, 'w', 3);
	char *r_memcpp3 = ft_memccpy(memccp6, memccp8, 'w', 3);
	if (memcmp(memccp5, memccp6, 3) == 0 && memcmp(r_memcpp2, r_memcpp3, 1) == 0)
		printf(GRN "OK\n");
	else
	{
		printf(RED "FAIL\n");
		printf(GRN "Expected: %s - %s\n", memccp5, r_memcpp2);
		printf(RED "Received: %s - %s\n", memccp6, r_memcpp3);
	}


	return (0);
}
