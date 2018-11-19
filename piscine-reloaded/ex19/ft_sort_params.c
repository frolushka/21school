/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:25:29 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/19 14:54:20 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	if (*s1)
		return (*s1);
	if (*s2)
		return (*s2);
	return (0);
}

void	ft_swap(char *str1, char *str2)
{
	char	**temp;

	*temp = str1;
	str1 = str2;
	str2 = *temp;
}

int		main(int argc, char **argv)
{	
	int	i;
	int	j;

	i = 0;
	while (++i < argc - 1)
	{
		j = i;
		while (++j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]))
				ft_swap(argv[i], argv[j]);
		}
	}
	while (*(++argv))
		ft_putstr(*argv);
	return (0);
}
