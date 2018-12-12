/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:14:17 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/12 06:03:39 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_dlist.h"
#include "ft_reader.h"
#include "ft_util.h"
#include "ft_bmatrix.h"
#include "ft_bmtx_helper.h"
#include "ft_intarr.h"

// int    main(void)
// {
//     t_bmatrix *b = ft_bmatrix_init(5, 12);
//     ft_bmatrix_print(b);
//     ft_bmatrix_set(&b, 4, 3, 1);
//     ft_bmatrix_set(&b, 2, 3, 1);
//     ft_bmatrix_set(&b, 2, 8, 1);
//     ft_bmatrix_set(&b, 0, 8, 1);
//     ft_bmatrix_set(&b, 0, 8, 0);
//     ft_bmatrix_set(&b, 1, 5, 1);
//     ft_bmatrix_set(&b, 3, 11, 1);
//     ft_bmatrix_set(&b, 3, 4, 1);
//     ft_bmatrix_set(&b, 4, 3, 1);
//     ft_bmatrix_print(b);
//     return (0);
// }

int    main(int argc, char **argv)
{
    t_dlist    *fgs;
    int        fd;

    fgs = NULL;
    if (argc != 2)
    {
        write(1, USAGE_MSG, sizeof(USAGE_MSG));
        exit(0);
    }
    if ((fd = open(argv[1], O_RDONLY)) <= 0
        || read_figures(fd, &fgs) != 0)
        write(1, "error\n", 6);
    else
        write(1, "ok\n", 3);
    t_dlist *cur = fgs;
    t_bmatrix *b = ft_bmatrix_init(5, 12);
    ft_bmatrix_print(b);
    printf("val: %d\n", ft_bmatrix_setfg(&b, 0, 0, cur->next->next));
    printf("val: %d\n", ft_bmatrix_setfg(&b, 0, 9, cur->next->next));
    printf("val: %d\n", ft_bmatrix_setfg(&b, 0, -1, cur->next->next));
    printf("val: %d\n", ft_bmatrix_setfg(&b, 99, 9, cur->next->next));
    printf("val: %d\n", ft_bmatrix_setfg(&b, 2, 10, cur->next));
    printf("val: %d\n", ft_bmatrix_setfg(&b, 1, 9, cur->next->next));
    printf("val: %d\n", ft_bmatrix_setfg(&b, 2, 9, cur->next));
    ft_bmatrix_print(b);
    ft_bmatrix_delfg(&b, 0, 9, cur->next->next);
    ft_bmatrix_print(b);
    int *a = ft_arr_init(5);
    ft_print_arr(a, 5);
    printf("start rotate sequence\n");
    while (ft_next_sequence(a, 5))
        ft_print_arr(a, 5);
    while (cur)
    {
        printf("%d\n", cur->value);
        cur = cur->next;
    }
    return (0);
}

