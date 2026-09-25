/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalea <abalea@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:40:10 by abalea            #+#    #+#             */
/*   Updated: 2026/09/25 14:05:54 by abalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	combined_length(int size, char **strs, char *sep)
{
	int	i_word;
	int	i_letter;
	int	length_output;
	int	count_words;
	int	length_word;

	length_output = 0;
	count_words = size;
	i_word = 0;
	while (i_word < count_words)
	{
		length_word = ft_strlen(strs[i_word]);
		i_letter = 0;
		while (i_letter < length_word)
			i_letter++;
		length_output += i_letter;
		i_word++;
	}
	count_words = size;
	length_output += (ft_strlen(sep) * (count_words - 1));
	return (length_output);
}

void	word_copy(char *output, int *i_output, int length_word, char *word)
{
	int	i_letter;

	i_letter = 0;
	while (i_letter < length_word)
	{
		output[*i_output + i_letter] = word[i_letter];
		i_letter++;
	}
	*i_output += i_letter;
}

void	real_strjoin(int size, char **strs, char *sep, char *output)
{
	int		i_output;
	int		i_word;
	int		count_words;

	count_words = size;
	i_output = 0;
	i_word = 0;
	while (i_word < count_words)
	{
		word_copy(output, &i_output, ft_strlen(strs[i_word]), strs[i_word]);
		if (i_word != count_words - 1)
			word_copy(output, &i_output, ft_strlen(sep), sep);
		i_word++;
	}
	output[i_output] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*output;
	int		length_output;

	if (size == 0)
	{
		output = malloc(sizeof(char) * 1);
		output[0] = '\0';
	}
	else
	{
		length_output = combined_length(size, strs, sep);
		output = malloc(sizeof(char) * (length_output + ('\0' + 1)));
		if (!output)
			return (NULL);
		real_strjoin(size, strs, sep, output);
	}
	return (output);
}

/*
// #include <stdio.h>
// #include <malloc.h>
// #include <string.h>

int	unit_tests()
{
	char	*array[] = {"Hey", "hi", "Hello"};
	char	*output = "Hi-----Hey";
	int		i_output;
	char	*expected_output = "---Hello--";
	
	output = malloc(sizeof(char) * (3 + 5 + 2 + ((int) '\0') + 1));
	output[11] = '\0';

	if (ft_strlen("Hello") != 5)
	{
		printf("%d\n", ft_strlen("Hello"));
		return (1);
	}
	
	if (combined_length(3, array, ", ") != 14)
	{
		printf("%d\n", combined_length(3, array, ", "));
		return (2);
	}

	i_output = 0;
	while (i_output < 10)
	{
		output[i_output] = '-';
		i_output++;
	}
	i_output = 3;
	word_copy(output, &i_output, 5, "Hello");
	output[11] = '\0';
	if (strcmp(output, expected_output) != 0 || i_output != 8)
	{
		printf("Text: %s\nPosition after: %d\n", output, i_output);
		return(3);
	}
	free(output);

	output = malloc(sizeof(char) * (3 + 5 + 2 + ((int) '\0') + 1));
	if (!output)
		return (-1);
	real_strjoin(3, array, ", ", output);
	if (strcmp(output, "Hey, hi, Hello") != 0)
	{
		printf("%s\n", output);
		return(4);
	}

	return (0);
}

int	main(int argc, char *argv[])
{
	int		i_argv;
	char	*output;
	char	*fallback_argv[] = {argv[0], ", ", "Hello", "Hi", "foo"};
	int		skip_func_name = 1;
	int		skip_separator = 1;
	int		count_argv_words;
	char	**array1;
	int		error_code;


	error_code = unit_tests();
	if (error_code != 0)
	{
		printf("\033[1;31m[Unit test number %d failed]\033[0m\n", error_code);
		return (error_code);
	}

	printf("\033[1;33mUsage instructions:\033[0m\n");
	printf("    a.out [<separator> <words>...]\n\n");
	if (argc == 1)
	{
		argc = sizeof(fallback_argv) / sizeof(char *);
		argv = fallback_argv;
	}

	count_argv_words = argc - skip_func_name - skip_separator;
	printf("\033[1;34mCount of items: %d\033[0m\n\n", count_argv_words);
	array1 = malloc(sizeof(char *) * argc - skip_func_name - 2);
	if (!array1)
		return (-1);

	i_argv = 0 + skip_func_name;
	while (i_argv < argc)
	{
		printf("\033[1;34mInput[%d]:\033[0m\n", i_argv);
		printf("Size: %d | Separator: \"%s\"\n", count_argv_words, argv[i_argv]);
		i_argv += 1;
		printf("Array: ");
		while (i_argv < argc)
		{
			array1[i_argv - skip_func_name - skip_separator] = argv[i_argv];
			printf("[%s]", argv[i_argv]);
			if (i_argv != argc - 1)
				printf(", ");
			i_argv++;
		}
		printf("\n\n");

		i_argv += 0; // FOR REPEATING LOOPS
	}
	// OUT OF THE LOOP FOR THIS ONE BECAUSE SINGLE RUN FUNCTION
	i_argv = 0 + skip_func_name;
	output = ft_strjoin(count_argv_words, array1, argv[i_argv]);
	printf("\033[1;32m--- Result ---\033[0m\nValue: %s\n\n", output);
	free(output);
	
}
*/
