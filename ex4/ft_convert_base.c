/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalea <abalea@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:04:23 by abalea            #+#    #+#             */
/*   Updated: 2026/10/01 20:40:56 by abalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

int	ft_strlen(char *str);

int	has_duplicates(char *str);

int	has_bad_characters(char *str);

int	is_valid_base(char *base);

int	base_to_decimal(char *str, char *base_from)
{
	int	i_base;
	int	decimal_nbr;

	decimal_nbr = 0;
	while (*str)
	{
		i_base = 0;
		while (*str && *str != base_from[i_base])
			i_base++;
		decimal_nbr = (decimal_nbr * ft_strlen(base_from)) + i_base;
		str++;
	}
	return (decimal_nbr);
}

int	length_of_decimal_in_base(int decimal_nbr, char *base)
{
	int		length;

	length = 0;
	while (decimal_nbr > 0)
	{
		decimal_nbr /= ft_strlen(base);
		length++;
	}
	return (length);
}

char	*convert_decimal_to_base(
	int decimal_nbr, char *base_to, int length_output
)
{
	char	*output;

	output = malloc(sizeof(char) * length_output + sizeof('\0'));
	if (!output)
		return (NULL);
	while (decimal_nbr > 0)
	{
		output[length_output - 1] = base_to[decimal_nbr % ft_strlen(base_to)];
		decimal_nbr /= ft_strlen(base_to);
		length_output--;
	}
	return (output);
}

char	*base_to_base(char *str, char *base_from, char *base_to)
{
	int		is_negative;
	int		decimal_nbr;
	char	*output;
	int		length_output;

	is_negative = 0;
	if (str[0] == '-')
		is_negative = 1;
	decimal_nbr = base_to_decimal(&(str[is_negative]), base_from);
	length_output = length_of_decimal_in_base(decimal_nbr, base_to);
	if (is_negative)
		length_output += 1;
	output = convert_decimal_to_base(decimal_nbr, base_to, length_output);
	if (is_negative)
		output[0] = '-';
	output[length_output] = '\0';
	convert_decimal_to_base(decimal_nbr, base_to, length_output);
	return (output);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*output;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	else
		output = base_to_base(nbr, base_from, base_to);
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
	char	*output;

	if (
		(ft_strlen("12345") != 5)
		|| (ft_strlen("") != 0)
	)
	{
		fail(1);
	}
	if (
		(has_duplicates("012345") != 0)
		|| (has_duplicates("012234") != 1)
	)
	{
		fail(2);
	}
	if (
		(has_bad_characters("0123456789abcdef") != 0)
		|| (has_bad_characters("+- \n") != 1)
	)
	{
		fail(3);
	}
	if (
		(is_valid_base("0123456789abcdef") != 1)
		|| (is_valid_base("1") != 0)
	)
	{
		fail(4);
	}
	if (
		(length_of_decimal_in_base(10, "01") != 4)
		|| (length_of_decimal_in_base(10, "0123456789abcdef") != 1)
	)
	{
		fail(5);
	}

	output = base_to_base("42", "0123456789", "01");
	if (
		(strcmp(output, "101010"))
	)
	{
		printf("%s\n", output);
		fail(6);
	}
	free(output);

	output = ft_convert_base("42", "0123456789", "01");
	if (strcmp(output, "101010") != 0)
	{
		printf("%s\n", output);
		fail(7);
	}
	free(output);
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
	char	mode[] = "finite_sets";
	char	*arg_names[] = {
		"nbr", "base_from", "base_to",
		NULL};
	int		i_arg_names;
	int		count_arg_names = 0;
	char	*fallback_argv[] = {argv[0],
		"42", "0123456789", "01",
		"1000000", "01", "0123456789",
		"-1023827911", "0123456789", "01",
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
		output = ft_convert_base(
			argv[i_argv], argv[i_argv+1], argv[i_argv+2]
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
