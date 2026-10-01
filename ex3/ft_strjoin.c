/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalea <abalea@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:40:10 by abalea            #+#    #+#             */
/*   Updated: 2026/10/01 17:42:22 by abalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

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
// #include <malloc.h>
// #include <string.h>

#define SKIP_PROGRAM_NAME 1

void	fail(int error_number)
{
	printf("\033[1;31m[Unit test number %d failed]\033[0m\n", error_number);
	exit(error_number);
}

void	unit_tests()
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
		fail(1);
	}
	
	if (combined_length(3, array, ", ") != 14)
	{
		printf("%d\n", combined_length(3, array, ", "));
		fail(2);
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
		fail(3);
	}
	free(output);

	output = malloc(sizeof(char) * (3 + 5 + 2 + ((int) '\0') + 1));
	if (!output)
		fail(-1);
	real_strjoin(3, array, ", ", output);
	if (strcmp(output, "Hey, hi, Hello") != 0)
	{
		printf("%s\n", output);
		fail(4);
	}
}

void	print_words(char *words[], char *wrap, char *separator)
{
	int	i_words;

	i_words = 0;
	while (words[i_words] != NULL)
	{
		printf("%c%s%c", wrap[0], words[i_words], wrap[1]);
		if (words[i_words+1] != NULL)
			printf("%s", separator);
		i_words++;
	}
}

void	print_numbers(
	int *numbers, int count_numbers, char *wrap, char *separator
)
{
	int	i_numbers;

	i_numbers = 0;
	while (i_numbers < count_numbers)
	{
		printf("%c%d%c", wrap[0], numbers[i_numbers], wrap[1]);
		if (numbers[i_numbers+1] != count_numbers)
			printf("%s", separator);
		i_numbers++;
	}
}

void print_usage(char *program_name, char *arg_names[], char *mode)
{
	printf("\033[1;33mUsage instructions:\033[0m\n");
	printf("    %s [", program_name);
	print_words(arg_names, "<>", " ");
	if (strcmp(mode, "finite_sets") == 0)
		printf("]...");
	else if (strcmp(mode, "dynamic_array") == 0)
		printf("...]");
	else
		printf("]");
	printf("\n\n");
}

void	parse_argv_null(char *argv[], int i_argv, int count_arg_names)
{
	int	i_argv_offset;

	i_argv_offset = 0;
	while (i_argv_offset < count_arg_names)
	{
		if (strcmp(argv[i_argv + i_argv_offset], "NULL") == 0)
			argv[i_argv + i_argv_offset] = NULL;
		i_argv_offset++;
	}
}

char	**build_dynamic_array(
	char *argv[], int skip_pre_array_args, int size_dynamic_array
)
{
	int		i_argv = 0 + SKIP_PROGRAM_NAME + skip_pre_array_args;
	char	**output;
	int		i_output;

	output = malloc(sizeof(char *) * size_dynamic_array + sizeof(NULL));
	if (!output)
		return (NULL);
	i_output = 0;
	while (argv[i_argv + i_output])
	{
		output[i_output] = argv[i_argv + i_output];
		i_output++;
	}
	output[i_output] = NULL;
	return (output); 
}

int	main(int argc, char *argv[])
{
	char	mode[] = "dynamic_array";
	char	*arg_names[] = {
		"Separator", "Words",
		NULL};
	int		i_arg_names;
	int		count_arg_names = 0;
	char	*fallback_argv[] = {argv[0], ", ",
		"Hello", "Hi", "foo", "bar",
		NULL};
	int		i_argv;
	int		skip_pre_array_args = 0;
	char	**dynamic_array;
	int		size_dynamic_array = 0;
	char	*output;
	//int		size_output;
	//int		return_capture;

	unit_tests();
	printf("\033[1;32m[All unit tests passed]\033[0m\n\n");
	print_usage(argv[0], arg_names, mode);
	if (argc == 1)
	{
		argv = fallback_argv;
		argc = 0;
		while (argv[argc])
			argc++;
	}
	//// DEBUG
	//printf("argc: %d | sizeof(fallback_argv): %d\n",
	//	argc, (int)(sizeof(fallback_argv) / sizeof(char *)));
	while (arg_names[count_arg_names])
		count_arg_names++;
	//// DEBUG
	//printf("count_arg_names: %d | sizeof: %d\n",
	//	 count_arg_names, (int)(sizeof(arg_names) / sizeof(char *)));
	i_argv = 0 + SKIP_PROGRAM_NAME;
	while (i_argv < argc)
	{
		printf("\033[1;34mInput[%d]:\033[0m\n", i_argv);
		parse_argv_null(argv, i_argv, count_arg_names);
		// POTENTIALLY IN A WHILE LOOP TO GRAB DYNAMIC ARRAY
		i_arg_names = 0;
		while (
			i_arg_names < count_arg_names - (strcmp(mode, "dynamic_array") == 0)
		)
		{
			printf("%s: \"%s\"",
				arg_names[i_arg_names], argv[i_argv + i_arg_names]);
			if (
				i_arg_names + 1 
				!= count_arg_names - (strcmp(mode, "dynamic_array") == 0)
			)
				printf(" | ");
			i_arg_names++;
		}
		printf("\n");
		if (strcmp(mode, "dynamic_array") == 0)
		{
			skip_pre_array_args = count_arg_names - 1;
			size_dynamic_array = argc - SKIP_PROGRAM_NAME - skip_pre_array_args;
			dynamic_array = build_dynamic_array(
				argv, skip_pre_array_args, size_dynamic_array
			);
			printf("Array: ");
			print_words(dynamic_array, "[]", ", ");
			printf("\n");
			printf("Array size: %d\n", size_dynamic_array);
		}
		output = ft_strjoin(
			size_dynamic_array, dynamic_array, argv[i_argv]
		);
		printf("\033[1;32m--- Result ---\033[0m\n");
		//// ARRAY OUTPUT MODE
		//size_output = atoi(argv[i_argv+1]) - atoi(argv[i_argv]);
		//printf("Return value: %d\n", return_capture);
		//printf("Array: ");
		//print_numbers(output, size_output, "", " ");
		////
		//// SINGLE OUTPUT MODE
		printf("Output: \"%s\"", output);
		printf("\n\n");
		free(output);
		if (strcmp(mode, "finite_sets") == 0)
			i_argv += count_arg_names;
		else if (strcmp(mode, "dynamic_array") == 0)
			i_argv += skip_pre_array_args + size_dynamic_array;
	}
}
*/
