/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 20:57:28 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/23 01:38:12 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	comp_dirs_simple(void *d1, void *d2)
{
	char	*d1n;
	char	*d2n;

	d1n = ((t_dir *)d1)->d_name;
	d2n = ((t_dir *)d2)->d_name;
	while (*d1n == *d2n)
	{
		++d1n;
		++d2n;
	}
	return (*d2n - *d1n);
}

static int	comp_dirs_r(void *d1, void *d2)
{
	char	*d1n;
	char	*d2n;

	d1n = ((t_dir *)d1)->d_name;
	d2n = ((t_dir *)d2)->d_name;
	while (*d1n == *d2n)
	{
		++d1n;
		++d2n;
	}
	return (*d1n - *d2n);
}

static int comp_dirs_t(void *d1, void *d2)
{
	return (0);
}

static int	print_dir(char const *fn, int flags)
{
	t_list	*root;
	t_list	*cur;
	DIR		*dirp;
	t_dir	*dir;

	if (!(dirp = opendir(fn)))
		return (-1);
	root = NULL;
	while ((dir = readdir(dirp)) != NULL)
		(!root ? root = ft_lstnew((void *)dir, sizeof(*dir)) :
			// ft_lstadd_back(&root, ft_lstnew((void *)dir, sizeof(*dir))));
			ft_lstinsert(&root, ft_lstnew((void *)dir, sizeof(*dir)), &comp_dirs));
	if ((flags & FLAG_mult || flags & FLAG_R) && ft_strcmp(fn, ".") != 0)
		print4(fn, ":\n", "", "");
	cur = root;
	while (cur)
	{
		dir = (t_dir *)cur->content;
		if (dir->d_name[0] == '.')
			(flags & FLAG_a ? print4(dir->d_name, "\t", "", "") : 0);
		else
			print4(dir->d_name, "\t", "", "");
		cur = cur->next;
	}
	write(1, "\n", 1);
	ft_lstdels(&root);
	closedir(dirp);
	return (0);
}

static int	recurse_ls(char const *fn, int flags)
{
	DIR		*dirp;
	t_dir	*dir;

	if (!(dirp = opendir(fn)))
		return (-1);
	while ((dir = readdir(dirp)) != NULL)
	{
		if (dir->d_type == 4 && ft_strcmp(dir->d_name, ".") != 0 && ft_strcmp(dir->d_name, "..") != 0)
			ft_ls(ft_strjoin(ft_strjoin(fn, "/"), dir->d_name), flags);
	}
	closedir(dirp);
	return (0);
}

int			ft_ls(char const *fn, int flags)
{
	print_dir(fn, flags);
	if (flags & FLAG_R)
		recurse_ls(fn, flags);
	return (0);
}
