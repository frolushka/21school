/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:54:55 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/23 00:21:16 by sbednar          ###   ########.fr       */
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

int main(void)
{
	int	failed = 0;
	failed += ft_memset_test();
	failed += ft_bzero_test();
	failed += ft_memcpy_test();
	failed += ft_memccpy_test();
	printf("TOTAL FAILED TESTS: %d\n", failed);
	return (EXIT_SUCCESS);
}
