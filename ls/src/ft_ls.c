/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 20:57:28 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/22 04:03:46 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	comp_dirs(void *d1, void *d2)
{
	char	*d1n;
	char	*d2n;

	d1n = ((t_dir *)d1)->d_name;
	d2n = ((t_dir *)d2)->d_name;
	printf("---compare %s & %s\n", d1n, d2n);
	while (d1n == d2n)
	{
		printf("------compare %c & %c\n", *d1n, *d2n);
		++d1n;
		++d2n;
	}
	printf("---found diff %c - %c = %d\n", *d1n, *d2n, *d1n - *d2n);
	return (*d1n - *d2n);
}

static int	print_simple(t_dir *dir, int flags)
{
	print4(dir->d_name, "\t", "", "");
	return (0);
}

int			ft_ls(char const *fn, int flags)
{
	t_list	*root;
	t_list	*cur;
	DIR		*dirp;
	t_dir	*dir;

	if (!(dirp = opendir(fn)))
		return (-1);
	root = NULL;
	while (dir = readdir(dirp))
		(!root ? root = ft_lstnew((void *)dir, sizeof(*dir)) :
			ft_lstadd_back(&root, ft_lstnew((void *)dir, sizeof(*dir))));
			// ft_lstinsert(&root, ft_lstnew((void *)dir, sizeof(*dir)), &comp_dirs);
	if ((flags & FLAG_mult || flags & FLAG_R) && ft_strcmp(fn, ".") != 0)
		print4(fn, ":\n", "", "");
	cur = root;
	while (cur)
	{
		dir = (t_dir *)cur->content;
		if (dir->d_name[0] == '.')
			(flags & FLAG_a ? print_simple(dir, flags) : 0);
		else
			print_simple(dir, flags);
		cur = cur->next;
	}
	write(1, "\n", 1);
	if (flags & FLAG_R)
	{
		cur = root;
		while (cur)
		{
			dir = (t_dir *)cur->content;
			if (dir->d_type == 4 && ft_strcmp(dir->d_name, ".") != 0 && ft_strcmp(dir->d_name, "..") != 0)
				ft_ls(ft_strjoin(ft_strjoin(fn, "/"), dir->d_name), flags);
			cur = cur->next;
		}
	}
	ft_lstdels(&root);
	closedir(dirp);
	return (0);
}