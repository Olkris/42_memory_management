/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalea <abalea@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:41:58 by abalea            #+#    #+#             */
/*   Updated: 2026/09/28 12:08:08 by abalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*result;
	int	distance;

	if (min >= max)
		return (NULL);
	distance = max - min;
	result = malloc(sizeof(int) * distance);
	if (!result)
		return (NULL);
	i = 0;
	while (i < distance)
	{
		result[i] = min + i;
		i++;
	}
	return (result);
}

/*
// #include <stdio.h>
// #include <malloc.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	**vars;
	int		size;
	char	*default_vars[] = {"FUNC_NAME",
		"1", "9", "8",
		"20", "24", "4",
		"2", "1", "err",
		"test", "hi", "err"};
	int		skip_func_name = 1;
	int		*output;
	int		i_output;

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
	printf("\033[1;33mUsage instructions:\033[0m\n");
	printf("    a.out [<range start> <range end> <expected size>]... \n\n");

	printf("\033[1;34mCount of items: %d\033[0m\n\n", size - skip_func_name);
	i = 0 + skip_func_name;
	while (i < size)
	{
		printf("\033[1;34mInput[%d]:\033[0m %s -> %s | expected size: %s\n",
			i, vars[i], vars[i+1], vars[i+2]);
		output = ft_range(atoi(vars[i]), atoi(vars[i+1]));
		printf("\033[1;32m--- Result ---\033[0m\n[");
		i_output = 0;
		while (i_output < atoi(vars[i+2]))
		{
			printf("%d", output[i_output]);
			if (i_output + 1 != atoi(vars[i+2]))
				printf(", ");
			i_output++;
		}
		free(output);
		printf("]\n\n");
		i += 3;
	}
}
*/
