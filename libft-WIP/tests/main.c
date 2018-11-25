/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:54:55 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/23 15:13:01 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/libft.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_memset_test()
{
	int passed;
	int failed;

	passed = 0;
	failed = 0;
	printf("TEST FT_MEMSET\n==============\n");
	char	*s = (char *)malloc(6 * sizeof(*s));
	ft_assert_str(memset(s, 5, 5), ft_memset(s, 5, 5), &passed, &failed);
	ft_assert_str(memset(s, 214421, 5), ft_memset(s, 214421, 5), &passed, &failed);
	ft_assert_str(memset(s, 0, 0), ft_memset(s, 0, 0), &passed, &failed);
	ft_assert_str(memset(s, 0, 4), ft_memset(s, 0, 4), &passed, &failed);
	ft_assert_str(memset(s, 0, 6), ft_memset(s, 0, 6), &passed, &failed);
	ft_assert_str(memset(s, -1, 124), ft_memset(s, -1, 124), &passed, &failed);
	printf("\n--------------\nTOTAL:\t%d\nPASSED:\t%d\nFAILED:\t%d\n--------------\n",
		passed + failed,
		passed,
		failed);
	return (failed);
}

int	ft_bzero_test()
{
	int passed;
	int failed;

	passed = 0;
	failed = 0;
	printf("TEST FT_BZERO\n==============\n");
	char	s1[7] = "000000";
	char	s2[7] = "000000";
	bzero(s1, 5);
	ft_bzero(s2, 5);
	ft_assert_str(s1, s2, &passed, &failed);
	strcpy(s1, "111111");
	strcpy(s2, "111111");
	bzero(s1, 1);
	ft_bzero(s2, 1);
	ft_assert_str(s1, s2, &passed, &failed);
	strcpy(s1, "222222");
	strcpy(s2, "222222");
	bzero(s1, 6);
	ft_bzero(s2, 6);
	ft_assert_str(s1, s2, &passed, &failed);
	strcpy(s1, "333333");
	strcpy(s2, "333333");
	bzero(s1, 7);
	ft_bzero(s2, 7);
	ft_assert_str(s1, s2, &passed, &failed);
	strcpy(s1, "444444");
	strcpy(s2, "444444");
	bzero(s1, 0);
	ft_bzero(s2, 0);
	ft_assert_str(s1, s2, &passed, &failed);
	printf("\n--------------\nTOTAL:\t%d\nPASSED:\t%d\nFAILED:\t%d\n--------------\n",
		passed + failed,
		passed,
		failed);
	return (failed);
}

int ft_memcpy_test()
{
	int passed;
	int failed;

	passed = 0;
	failed = 0;
	printf("TEST FT_MEMCPY\n==============\n");
	char	src[7] = "abcdef";
	char	dst1[7] = "000000";
	char	dst2[7] = "000000";
	ft_assert_str(memcpy(dst1, src, 5), ft_memcpy(dst2, src, 5), &passed, &failed);
	strcpy(dst1, "111111");
	strcpy(dst2, "111111");
	ft_assert_str(memcpy(dst1, src, 6), ft_memcpy(dst2, src, 6), &passed, &failed);
	strcpy(dst1, "222222");
	strcpy(dst2, "222222");
	ft_assert_str(memcpy(dst1, src, 7), ft_memcpy(dst2, src, 7), &passed, &failed);
	strcpy(dst1, "111111");
	strcpy(dst2, "111111");
	ft_assert_str(memcpy(dst1, src, 2), ft_memcpy(dst2, src, 2), &passed, &failed);
	strcpy(dst1, "111111");
	strcpy(dst2, "111111");
	ft_assert_str(memcpy(dst1, src, 1), ft_memcpy(dst2, src, 1), &passed, &failed);
	strcpy(dst1, "111111");
	strcpy(dst2, "111111");
	ft_assert_str(memcpy(dst1, src, 0), ft_memcpy(dst2, src, 0), &passed, &failed);
	printf("\n--------------\nTOTAL:\t%d\nPASSED:\t%d\nFAILED:\t%d\n--------------\n",
		passed + failed,
		passed,
		failed);
	return (failed);
}

int ft_memccpy_test()
{
	int passed;
	int failed;

	passed = 0;
	failed = 0;
	printf("TEST FT_MEMCCPY\n==============\n");
	char	src[7] = "abcdef";
	char	dst1[7] = "000000";
	char	dst2[7] = "000000";

	ft_assert_str(memccpy(dst1, src, 'a', 5), ft_memccpy(dst2, src, 'a', 5), &passed, &failed);
	ft_assert_str(dst1, dst2, &passed, &failed);
	strcpy(dst1, "111111");
	strcpy(dst2, "111111");
	ft_assert_str(memccpy(dst1, src, 'a', 6), ft_memccpy(dst2, src, 'a', 6), &passed, &failed);
	ft_assert_str(dst1, dst2, &passed, &failed);
	strcpy(dst1, "22222a");
	strcpy(dst2, "22222a");
	ft_assert_str(memccpy(dst1, src, 'a', 7), ft_memccpy(dst2, src, 'a', 7), &passed, &failed);
	ft_assert_str(dst1, dst2, &passed, &failed);
	strcpy(dst1, "11111a");
	strcpy(dst2, "11111a");
	ft_assert_str(memccpy(dst1, src, 'a', 2), ft_memccpy(dst2, src, 'a', 2), &passed, &failed);
	ft_assert_str(dst1, dst2, &passed, &failed);
	strcpy(dst1, "11a111");
	strcpy(dst2, "11a111");
	ft_assert_str(memccpy(dst1, src, 'a', 1), ft_memccpy(dst2, src, 'a', 1), &passed, &failed);
	ft_assert_str(dst1, dst2, &passed, &failed);
	strcpy(dst1, "111111");
	strcpy(dst2, "111111");
	ft_assert_str(memccpy(dst1, src, 'a', 0), ft_memccpy(dst2, src, 'a', 0), &passed, &failed);
	ft_assert_str(dst1, dst2, &passed, &failed);
	strcpy(dst1, "11a111");
	strcpy(dst2, "11a111");
	ft_assert_str(memccpy(dst1, src, 'a', 5), ft_memccpy(dst2, src, 'a', 5), &passed, &failed);
	ft_assert_str(dst1, dst2, &passed, &failed);
	printf("\n--------------\nTOTAL:\t%d\nPASSED:\t%d\nFAILED:\t%d\n--------------\n",
		passed + failed,
		passed,
		failed);
	return (failed);
}

int ft_memchr_test()
{
	int passed;
	int failed;

	passed = 0;
	failed = 0;
	printf("TEST FT_MEMCHR\n==============\n");
	char	src[8] = "ab\n\tcdef";
	ft_assert_str(memchr(src, 'a', 5), ft_memchr(src, 'a', 5), &passed, &failed);
	ft_assert_str(memchr(src, '\n', 5), ft_memchr(src, '\n', 5), &passed, &failed);
	ft_assert_str(memchr(src, '\t', 5), ft_memchr(src, '\t', 5), &passed, &failed);
	ft_assert_str(memchr(src, '\0', 5), ft_memchr(src, '\0', 5), &passed, &failed);
	ft_assert_str(memchr(src, 'd', 2), ft_memchr(src, 'd', 2), &passed, &failed);
	printf("\n--------------\nTOTAL:\t%d\nPASSED:\t%d\nFAILED:\t%d\n--------------\n",
		passed + failed,
		passed,
		failed);
	return (failed);
}

int ft_memcmp_test()
{
	int passed;
	int failed;

	passed = 0;
	failed = 0;
	printf("TEST FT_MEMCMP\n==============\n");
	char	s1[8] = "ab\n\tcdef";
	char	s2[8] = "ab\n\tcdgf";
	ft_assert_int(memcmp(s1, s2, 5), ft_memcmp(s1, s2, 5), &passed, &failed);
	ft_assert_int(memcmp(s1, s2, 6), ft_memcmp(s1, s2, 6), &passed, &failed);
	ft_assert_int(memcmp(s1, s2, 7), ft_memcmp(s1, s2, 7), &passed, &failed);
	ft_assert_int(memcmp(s1, s2, 8), ft_memcmp(s1, s2, 8), &passed, &failed);
	printf("\n--------------\nTOTAL:\t%d\nPASSED:\t%d\nFAILED:\t%d\n--------------\n",
		passed + failed,
		passed,
		failed);
	return (failed);
}

int ft_strlen_test()
{
	int passed;
	int failed;

	passed = 0;
	failed = 0;
	printf("TEST FT_STRLEN\n==============\n");
	char	s1[8] = "ab\n\tcdef";
	ft_assert_int(strlen(s1), ft_strlen(s1), &passed, &failed);
	char	s2[8] = "ab\0\tcdef";
	ft_assert_int(strlen(s2), ft_strlen(s2), &passed, &failed);
	char	s3[0] = "";
	ft_assert_int(strlen(s3), ft_strlen(s3), &passed, &failed);
	char	s4[13] = "ab\n\t     cdef";
	ft_assert_int(strlen(s4), ft_strlen(s4), &passed, &failed);
	printf("\n--------------\nTOTAL:\t%d\nPASSED:\t%d\nFAILED:\t%d\n--------------\n",
		passed + failed,
		passed,
		failed);
	return (failed);
}

int ft_strdup_test()
{
	int passed;
	int failed;

	passed = 0;
	failed = 0;
	printf("TEST FT_STRDUP\n==============\n");
	char	s1[8] = "ab\n\tcdef";
	ft_assert_str(strdup(s1), ft_strdup(s1), &passed, &failed);
	char	s2[0] = "";
	ft_assert_str(strdup(s2), ft_strdup(s2), &passed, &failed);
	char	s3[8] = "faf\0fafs";
	ft_assert_str(strdup(s3), ft_strdup(s3), &passed, &failed);
	char	s4[8] = "";
	ft_assert_str(strdup(s4), ft_strdup(s4), &passed, &failed);
	char	s5[4] = " \t\n\r";
	ft_assert_str(strdup(s5), ft_strdup(s5), &passed, &failed);
	printf("\n--------------\nTOTAL:\t%d\nPASSED:\t%d\nFAILED:\t%d\n--------------\n",
		passed + failed,
		passed,
		failed);
	return (failed);
}

int ft_stpcpy_test()
{
	int passed;
	int failed;

	passed = 0;
	failed = 0;
	printf("TEST FT_STPCPY\n==============\n");
	char	s1[8] = "ab\n\tcdef";
	char 	*dst = (char *)malloc(8);
	ft_assert_str(stpcpy(dst, s1), ft_stpcpy(dst, s1), &passed, &failed);
	free(dst);
	char	s2[0] = "";
	dst = (char *)malloc(0);
	ft_assert_str(stpcpy(dst, s2), ft_stpcpy(dst, s2), &passed, &failed);
	free(dst);
	char	s3[8] = "faf\0fafs";
	dst = (char *)malloc(8);
	ft_assert_str(stpcpy(dst, s3), ft_stpcpy(dst, s3), &passed, &failed);
	free(dst);
	char	s4[8] = "";
	dst = (char *)malloc(8);
	ft_assert_str(stpcpy(dst, s4), ft_stpcpy(dst, s4), &passed, &failed);
	free(dst);
	char	s5[4] = " \t\n\r";
	dst = (char *)malloc(4);
	ft_assert_str(stpcpy(dst, s5), ft_stpcpy(dst, s5), &passed, &failed);
	printf("\n--------------\nTOTAL:\t%d\nPASSED:\t%d\nFAILED:\t%d\n--------------\n",
		passed + failed,
		passed,
		failed);
	return (failed);
}

int main(void)
{
	int	failed = 0;
	failed += ft_memset_test();
	failed += ft_bzero_test();
	failed += ft_memcpy_test();
	failed += ft_memccpy_test();
	//failed += ft_memmove_test();
	failed += ft_memchr_test();
	failed += ft_memcmp_test();
	failed += ft_strlen_test();
	failed += ft_strdup_test();
	failed += ft_stpcpy_test();
	printf("TOTAL FAILED TESTS: %d\n", failed);
	return (EXIT_SUCCESS);
}
