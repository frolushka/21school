/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:21:58 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/15 22:07:09 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
/*
t_mlx	*init_conf(void *mlx, void *win)
{
	t_mlx	*res;

	if (!(res = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	res->mlx_ptr = mlx;
	res->win_ptr = win;
	res->screen_x = SCREEN_X;
	res->screen_y = SCREEN_Y;
	return (res);
}

t_info		*init_info(int param, int color, int size, void **content)
{
	//todo: sdelat videl pamyati po normalnomu
	t_info	*res;
	if (!(res = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	res->param = param;
	res->color = color;
	res->size = size;
	res->content = content;
	return (res);
}
*/
#include <stdio.h>

int		hook_keydown(int key, t_mlx *mlx)
{
	(void)mlx;
	printf("pressed button: %d\n", key);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

static void	set_hooks(t_mlx *c)
{
	// mlx_hook(c->win, 2, 0, key_press_hook, c);
	// mlx_hook(c->win, 3, 0, key_release_hook, c);
	// mlx_hook(c->win, 4, 0, mouse_press_hook, c);
	// mlx_hook(c->win, 5, 0, mouse_release_hook, c);
	// mlx_hook(c->win, 6, 0, motion_hook, c);
	// mlx_hook(c->win, 12, 0, expose_hook, c);
	mlx_key_hook(c->win, hook_keydown, c);
}

static int	draw_grid(t_mlx *c, int rs, int cs, int gs)
{
	int	x;
	int y;

	x = 0;
	while (x < cs)
	{
		y = 0;
		while (y < rs)
		{
			draw_line(c, vec2_new(x * gs, y * gs), vec2_new(x * gs, (y + 1) * gs));
			draw_line(c, vec2_new(x * gs, y * gs), vec2_new((x + 1) * gs, y * gs));

			++y;
		}
		++x;
	}
	return (0);
}

int			main(void)
{
	t_mlx		*mlx;
	//t_info		*i;
	//set_hooks(conf);
	/*void **c;
	void **c1;

	c = (void **)malloc(2);
	c[0] = (void *)init_vector2(SCREEN_X / 2, SCREEN_Y / 2);
	c[1] = (void *)init_vector2(200, 100);
	c1 = (void **)malloc(2);
	c1[0] = (void *)init_vector2(1000, 1000);
	c1[1] = (void *)init_vector2(10, 10);*/


	/*if (!(conf = init_conf(mlx, win)) || !(i = init_info(0, 0xFF0000, 0, c)))
		return (1);*/
	mlx = ddd_mlx_init(SCREEN_X, SCREEN_Y, SCREEN_NAME);
	set_hooks(mlx);
	// draw_grid(mlx, 10, 15, 10);
	t_vec2 *v1 = vec2_new(0, 0);
	t_vec2 *v2 = vec2_new(50, 25);
	t_vec2 *v3 = vec2_new(0, 25);
	t_vec2 *v4 = vec2_new(25, 38);
	t_vec2 *v5 = vec2_new(60, 144);
	t_vec2 *v6 = vec2_new(80, 30);
	t_vec2 *v7 = vec2_new(100, 10);
	t_vec2 *v8 = vec2_new(230, 50);
	draw_line(mlx, v1, v4);
	draw_line(mlx, v2, v3);
	draw_line(mlx, v5, v6);
	draw_line(mlx, v7, v8);


	mlx_loop(mlx->mlx);
	return (0);
	// t_vec2	*v1 = vec2_new(mlx->width / 2, mlx->height / 2);
	// t_vec2	*v2;
	// int ind = 0;
	// while (ind <= 360)
	// {
	// 	v2 = vec2_new(cos(ind * M_PI / 180) * 100, sin(ind * M_PI / 180) * 100);
	// 	v2 = vec2_sum(v1, v2);
	// 	printf("Drawing line from ");
	// 	vec2_print(v1);
	// 	printf(" to ");
	// 	vec2_print(v2);
	// 	printf("...\n");
	// 	draw_line(mlx, v1, v2);
	// 	ind += 30;
	// }
	// draw_line(mlx, vec2_new(0, 0), vec2_new(100, 199));
	// t_vec2	*vc = NULL;
	// t_vec2	*vp = vc;
	// while (1)
	// {
	// 	int a, b;
	// 	scanf("%d %d", &a, &b);
	// 	vc = vec2_new(a, b);
	// 	if (vp)
	// 		draw_line(mlx, vp, vc);
	// 	vp = vc;
	// }
	// return (0);

	// t_vec2	*v[100];
	// v[0] = vec2_new(40, 40);
	// v[1] = vec2_new(40, 120);
	// v[2] = vec2_new(120, 120);
	// v[3] = vec2_new(120, 100);
	// v[4] = vec2_new(60, 100);
	// v[5] = vec2_new(60, 60);
	// v[6] = vec2_new(120, 60);
	// v[7] = vec2_new(120, 40);
	// for (int i = 0; i <= 7; i++)
	// 	draw_line(mlx, v[i], v[(i + 1) % 8]);
	// v[0] = vec2_new(140, 40);
	// v[1] = vec2_new(140, 120);
	// v[2] = vec2_new(200, 120);
	// v[3] = vec2_new(200, 100);
	// v[4] = vec2_new(100, 100);
	// v[5] = vec2_new(100, 60);
	// v[6] = vec2_new(140, 60);
	// v[7] = vec2_new(140, 40);
	// for (int i = 0; i <= 7; i++)
	// 	draw_line(mlx, v[i], v[(i + 1) % 8]);

	//mlx_loop(mlx->mlx);
	/*for (int j = 0; j <= SCREEN_Y; j++)
	{	if (!(j % 40))
			for (int k = 0; k <= SCREEN_X; k++)
				if ((j == 0 || j == SCREEN_Y) && !(k % 40))
				{
					printf("%d\n", ddd_draw_line(conf, i));
					((t_vector2 *)(i->content[1]))->x = k;
					((t_vector2 *)(i->content[1]))->y = j;
					if (i->color == 0xFFFFFF)
						i->color = 0x000000;
					i->color += 0x107010;
					printf("LINE FROM X %d",((t_vector2 *)(i->content[0]))->x);
					printf(" Y %d",((t_vector2 *)(i->content[0]))->y);
					printf(" TO X %d",((t_vector2 *)(i->content[1]))->x);
					printf(" Y %d\n",((t_vector2 *)(i->content[1]))->y);
				}
				else if (k == 0 || k == SCREEN_X)
				{
					printf("%d\n", ddd_draw_line(conf, i));
					((t_vector2 *)(i->content[1]))->x = k;
					((t_vector2 *)(i->content[1]))->y = j;
					if (i->color == 0xFFFFFF)
						i->color = 0x000000;
					i->color += 0x107010;
					printf("LINE FROM X %d",((t_vector2 *)(i->content[0]))->x);
					printf(" Y %d",((t_vector2 *)(i->content[0]))->y);
					printf(" TO X %d",((t_vector2 *)(i->content[1]))->x);
					printf(" Y %d\n",((t_vector2 *)(i->content[1]))->y);
				}
	}
	i->param = 1;
	i->color = 0xAABBCC;
	i->content = c1;*/
//	printf("%d\n", ddd_draw_rect(conf, i));
}
