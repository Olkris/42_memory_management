/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalea <abalea@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:49:01 by abalea            #+#    #+#             */
/*   Updated: 2026/10/01 17:24:36 by abalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*result;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	result = malloc(sizeof(int) * (max - min));
	if (!result)
		return (-1);
	i = 0;
	while (min + i < max)
	{
		result[i] = min + i;
		i++;
	}
	*range = result;
	return (max - min);
}

/*
// #include <malloc.h>
// #include <string.h>

void	fail(int error_number)
{
	printf("\033[1;31m[Unit test number %d failed]\033[0m\n", error_number);
	exit(error_number);
}

void	unit_tests()
{
	if (
		(1 != 1)
	)
		fail(1);
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

int	main(int argc, char *argv[])
{
	char	mode[] = "finite_sets";
	char	*arg_names[] = {
		"min", "max",
		NULL};
	int		i_arg_names;
	int		count_arg_names = 0;
	char	*fallback_argv[] = {argv[0],
		"20", "24",
		"-3", "31",
		"2", "1",
		"1", "1",
		"test", "hi",
		NULL};
	int		i_argv;
	int		count_argv = 0;
	int		*output;
	int		return_capture;
	int		size_output;
	#define SKIP_PROGRAM_NAME 1
	int		skip_pre_array_args = 0;
	int		size_argv_dynamic_array = 0;

	unit_tests();
	printf("\033[1;32m[All unit tests passed]\033[0m\n\n");
	print_usage(argv[0], arg_names, mode);
	if (argc == 1)
	{
		argc = sizeof(fallback_argv) / sizeof(char *);
		argv = fallback_argv;
	}
	while (argv[count_argv])
		count_argv++;
	//printf("count_argv: %d | argc: %d\n", count_argv, argc);
	while (arg_names[count_arg_names])
		count_arg_names++;
	//printf("count_arg_names: %d | sizeof: %d\n",
	//	 count_arg_names, (int)(sizeof(arg_names) / sizeof(char *)));
	if (strcmp(mode, "dynamic_array") == 0)
	{
		skip_pre_array_args = count_arg_names - 1;
		size_argv_dynamic_array = argc - SKIP_PROGRAM_NAME - skip_pre_array_args;
		printf("Array size: %d\n", size_argv_dynamic_array);
	}
	i_argv = 0 + SKIP_PROGRAM_NAME;
	while (i_argv < count_argv)
	{
		printf("\033[1;34mInput[%d]:\033[0m\n", i_argv);
		parse_argv_null(argv, i_argv, count_arg_names);
		// POTENTIALLY IN A WHILE LOOP TO GRAB ENDLESS ARRAY
		if (strcmp(mode, "finite_sets") == 0)
		{
			i_arg_names = 0;
			while (i_arg_names < count_arg_names)
			{
				printf("%s: \"%s\"",
					arg_names[i_arg_names], argv[i_argv + i_arg_names]);
				if (i_arg_names + 1 != count_arg_names)
					printf(" | ");
				i_arg_names++;
			}
			printf("\n");
		}
		return_capture = ft_ultimate_range(
			&output, atoi(argv[i_argv]), atoi(argv[i_argv+1])
		);
		printf("\033[1;32m--- Result ---\033[0m\n");
		// ARRAY OUTPUT MODE
		size_output = atoi(argv[i_argv+1]) - atoi(argv[i_argv]);
		printf("Return value: %d\n", return_capture);
		printf("Array: ");
		print_numbers(output, size_output, "", " ");
		// SINGLE OUTPUT MODE
		//printf("Output: %d", output);
		printf("\n\n");
		free(output);
		i_argv += count_arg_names; // FOR REPEATING FINITE SETS ONLY
	}
	// RESET I_ARGV TO GRAB ENDLESS ARRAY FROM START, IF APPLICABLE
	if (strcmp(mode, "dynamic_array") == 0)
		i_argv = 0 + SKIP_PROGRAM_NAME + skip_pre_array_args;
}
*/
