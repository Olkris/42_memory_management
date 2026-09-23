/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalea <abalea@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:20:08 by abalea            #+#    #+#             */
/*   Updated: 2026/09/23 16:48:06 by abalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	copy = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!copy)
		return (NULL);
	copy[ft_strlen(src)] = '\0';
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}

/*
// #include <stdio.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	**vars;
	int		size;
	char	*default_vars[] = {"FUNC_NAME", "Hello", "World", "foo", "bar"};
	int		func_itself = 1;

	if (argc > 1)
	{
		size = argc;
		vars = argv;
	}
	else
	{
		size = sizeof(default_vars) / sizeof(char *);
		vars = default_vars;
	}
	printf("Count of items: %d\n", size - func_itself);
	i = 0 + func_itself;
	while (i < size)
	{
		printf("%d\t%s\tCopy: %s\n", i, vars[i], ft_strdup(vars[i]));
		i++;
	}
}
*/
