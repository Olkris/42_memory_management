/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalea <abalea@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:04:23 by abalea            #+#    #+#             */
/*   Updated: 2026/09/28 18:15:17 by abalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

int	ft_strlen(char *str);

int	has_duplicates(char *str);

int	has_bad_characters(char *str);

int	is_valid_base(char *base);

int	length_of_decimal_in_base(int decimal_nbr, char *base)
{
	int	length;

	length = 0;
	while (decimal_nbr > 0)
	{
		decimal_nbr /= ft_strlen(base);
		length++;
	}
	return (length);
}

char	*base_to_base(char *str, char *base_from, char *base_to)
{
	int		ii;
	int		decimal_nbr;
	char	*output;

	decimal_nbr = 0;
	while (*str)
	{
		ii = 0;
		while (*str && *str != base_from[ii])
			ii++;
		decimal_nbr = (decimal_nbr * ft_strlen(base_from)) + ii;
		str++;
	}
	ii = length_of_decimal_in_base(decimal_nbr, base_to);
	output = malloc(sizeof(char) * ii + sizeof('\0'));
	if (!output)
		return (NULL);
	output[ii] = '\0';
	while (decimal_nbr > 0)
	{
		output[ii - 1] = base_to[decimal_nbr % ft_strlen(base_to)];
		ii--;
		decimal_nbr /= ft_strlen(base_to);
	}
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

int	unit_tests()
{
	char	*output;

	if (
		(ft_strlen("12345") != 5)
		|| (ft_strlen("") != 0)
	)
	{
		return (1);
	}
	if (
		(has_duplicates("012345") != 0)
		|| (has_duplicates("012234") != 1)
	)
	{
		return (2);
	}
	if (
		(has_bad_characters("0123456789abcdef") != 0)
		|| (has_bad_characters("+- \n") != 1)
	)
	{
		return (3);
	}
	if (
		(is_valid_base("0123456789abcdef") != 1)
		|| (is_valid_base("1") != 0)
	)
	{
		return (4);
	}
	if (
		(length_of_decimal_in_base(10, "01") != 4)
		|| (length_of_decimal_in_base(10, "0123456789abcdef") != 1)
	)
	{
		return (5);
	}
	output = base_to_base("42", "0123456789", "01");
	if (
		(strcmp(output, "101010"))
	)
	{
		printf("%s\n", output);
		return (6);
	}
	free(output);
	output = ft_convert_base("42", "0123456789", "01");
	if (strcmp(output, "101010") != 0)
	{
		printf("%s\n", output);
		return (7);
	}
	free(output);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i_argv;
	char	*output;
	char	*fallback_argv[] = {argv[0],
		 "42", "0123456789", "01",
		 "1000000", "01", "0123456789"};
	int		skip_func_name = 1;
	int		skip_pre_array_arguments = 0;
	int		size_argv_dynamic_array;
	int		error_code;

	error_code = unit_tests();
	if (error_code != 0)
	{
		printf("\033[1;31m[Unit test number %d failed]\033[0m\n", error_code);
		return (error_code);
	}
	else
		printf("\033[1;32m[All unit tests passed]\033[0m\n\n");

	printf("\033[1;33mUsage instructions:\033[0m\n");
	printf("    a.out [<nbr> <base_from> <base_to>]...\n\n");
	if (argc == 1)
	{
		argc = sizeof(fallback_argv) / sizeof(char *);
		argv = fallback_argv;
	}

	// IF ENDLESS ARRAYS
	size_argv_dynamic_array = argc - skip_func_name - skip_pre_array_arguments;
	// POTENTIAL PRINT OF ENDLESS ARRAY SIZE
	if (0)
		printf("Array size: %d\n", size_argv_dynamic_array);

	i_argv = 0 + skip_func_name;
	while (i_argv < argc)
	{
		printf("\033[1;34mInput[%d]:\033[0m\n", i_argv);
		// POTENTIALLY IN A WHILE LOOP TO GRAB ENDLESS ARRAY
		printf("nbr: %s | base_from: %s | base_to: %s\n",
			argv[i_argv], argv[i_argv+1], argv[i_argv+2]);
		output = ft_convert_base(
			argv[i_argv], argv[i_argv+1], argv[i_argv+2]);
		printf("\033[1;32m--- Result ---\033[0m\nOutput: %s\n", output);
		free(output);
		printf("\n");
		i_argv += 3; // FOR REPEATING FINITE SETS ONLY
	}
	// RESET I_ARGV TO GRAB ENDLESS ARRAY FROM START, IF APPLICABLE
	i_argv = 0 + skip_func_name + skip_pre_array_arguments;
}
*/
