/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalea <abalea@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 18:28:26 by abalea            #+#    #+#             */
/*   Updated: 2026/09/29 15:59:27 by abalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

int	ft_strlen(char *str)
{
	char	*str_end;

	str_end = str;
	while (*str_end != '\0')
		str_end++;
	return (str_end - str);
}

int	is_in_charset(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (is_in_charset(*str, charset))
			str++;
		if (!is_in_charset(*str, charset))
		{
			count++;
			while (*str && !is_in_charset(*str, charset))
				str++;
		}
	}
	return (count);
}

char	*grab_word(char *str_start, char *str_end)
{
	char	*word;
	int		i_word;

	word = malloc(sizeof(char) * (str_end - str_start) + sizeof('\0'));
	word[str_end - str_start] = '\0';
	i_word = 0;
	while (*str_start && str_start < str_end)
	{
		word[i_word] = *str_start;
		str_start++;
		i_word++;
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**output;
	int		i_output;
	char	*word;
	char	*str_offset;

	output = malloc(sizeof(char *) * count_words(str, charset) + sizeof('\0'));
	output[count_words(str, charset)] = NULL;
	i_output = 0;
	while (*str)
	{
		while (is_in_charset(*str, charset))
			str++;
		if (!is_in_charset(*str, charset))
		{
			str_offset = str;
			while (*str_offset && !is_in_charset(*str_offset, charset))
				str_offset++;
			word = grab_word(str, str_offset);
			output[i_output++] = word;
			str = str_offset;
		}
	}
	return (output);
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
		(ft_strlen("123456") != 6)
		&& (ft_strlen("") != 0)
	)
		fail(1);
	if (
		(is_in_charset(',', "-+ ,") != 1)
	)
		fail(2);
	if (
		(count_words("Hello,HI,HEY", ",") != 3)
	)
		fail(3);
}

void	print_array(char *array[], char *wrap, char *separator)
{
	int	i_array;

	i_array = 0;
	while (array[i_array] != NULL)
	{
		printf("%c%s%c", wrap[0], array[i_array], wrap[1]);
		if (array[i_array+1] != NULL)
			printf("%s", separator);
		i_array++;
	}
}

void print_usage(char *program_name, char *arg_names[], char *mode)
{
	printf("\033[1;33mUsage instructions:\033[0m\n");
	printf("    %s [", program_name);
	print_array(arg_names, "<>", " ");
	if (strcmp(mode, "finite_sets") == 0)
		printf("]...");
	else if (strcmp(mode, "dynamic_array") == 0)
		printf("...]");
	else
		printf("]");
	printf("\n\n");
}

int	main(int argc, char *argv[])
{
	char	mode[] = "finite_sets";
	char	*fallback_argv[] = {argv[0],
		"Hello, World, foo, bar", ", ",
		"DOUBLE+KILL-TRIPLE+KILL", "+-",
		NULL};
	int		i_argv;
	char	*arg_names[] = {"str", "charset", NULL};
	int		i_arg_names;
	int		arg_count = 0;
	char	**output;
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
	while (arg_names[arg_count])
		arg_count++;
	if (strcmp(mode, "dynamic_array") == 0)
	{
		skip_pre_array_args = arg_count - 1;
		size_argv_dynamic_array = argc - SKIP_PROGRAM_NAME - skip_pre_array_args;
		printf("Array size: %d\n", size_argv_dynamic_array);
	}
	i_argv = 0 + SKIP_PROGRAM_NAME;
	while (i_argv < argc && argv[i_argv] != NULL)
	{
		printf("\033[1;34mInput[%d]:\033[0m\n", i_argv);
		// POTENTIALLY IN A WHILE LOOP TO GRAB ENDLESS ARRAY
		if (strcmp(mode, "finite_sets") == 0)
		{
			i_arg_names = 0;
			while (i_arg_names < arg_count)
			{
				printf("%s: \"%s\"",
					arg_names[i_arg_names], argv[i_argv + i_arg_names]);
				if (i_arg_names + 1 != arg_count)
					printf(" | ");
				i_arg_names++;
			}
			printf("\n");
		}
		output = ft_split(argv[i_argv], argv[i_argv+1]);
		printf("\033[1;32m--- Result ---\033[0m\n");
		printf("Array: ");
		print_array(output, "[]", ", ");
		printf("\n\n");
		free(output);
		i_argv += arg_count; // FOR REPEATING FINITE SETS ONLY
	}
	// RESET I_ARGV TO GRAB ENDLESS ARRAY FROM START, IF APPLICABLE
	if (strcmp(mode, "dynamic_array") == 0)
		i_argv = 0 + SKIP_PROGRAM_NAME + skip_pre_array_args;
}
*/
