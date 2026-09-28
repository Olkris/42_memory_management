/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalea <abalea@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:04:23 by abalea            #+#    #+#             */
/*   Updated: 2026/09/28 13:26:47 by abalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	is_valid_base(char *base);

char	*base_to_base(char *str, char *base_from, char *base_to)
{
	int		ii;
	int		decimal_nbr;
	int		decimal_nbr_copy;
	char	*output;

	decimal_nbr = 0;
	while (*str)
	{
		while (*str && *str != base_from[ii])
			ii++;
		decimal_nbr += ii * ft_strlen(base_from);
		str++;
	}
	decimal_nbr_copy = decimal_nbr;
	ii = 0;
	while (decimal_nbr_copy > 0)
	{
		decimal_nbr_copy /= ft_strlen(base_to);
		ii++;
	}
	output = malloc(sizeof(char) * ii + sizeof('\0'));
	output[ii] = '\0';
	while (decimal_nbr > 0 && ii > 0)
	{
		output[ii] = decimal_nbr % 10;
		ii--;
		decimal_nbr /= 10;
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
// #include <stdio.h>
// #include <malloc.h>
// #include <string.h>

int	unit_tests()
{
	char nbr[] = "42";
	char base_from[] = "0123456789";
	char base_to[] = "01";

	if (strcmp(ft_convert_base(nbr, base_from, base_to), "101010") != 0)
	{
		printf("%s\n", ft_convert_base(nbr, base_from, base_to));
		return (1);
	}
	
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
		printf("nbr: %s | base_from: %s | base_to %s\n",
			argv[i_argv], argv[i_argv+1], argv[i_argv+2]);
		output = ft_convert_base(
			 argv[i_argv], argv[i_argv+1], argv[i_argv+2]);
		printf("\033[1;32m--- Result ---\033[0m\nOutput: %s\n\n", output);
		free(output);	
		printf("\n\n");
		i_argv += 3; // FOR REPEATING FINITE SETS ONLY
	}
	// RESET I_ARGV TO GRAB ENDLESS ARRAY FROM START, IF APPLICABLE
	i_argv = 0 + skip_func_name + skip_pre_array_arguments;
}
*/
