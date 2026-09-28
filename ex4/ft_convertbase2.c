/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalea <abalea@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:22:10 by abalea            #+#    #+#             */
/*   Updated: 2026/09/28 12:30:44 by abalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	char	*str_end;

	str_end = str;
	while (*str_end != '\0')
		str_end++;
	return (str_end - str);
}

int	has_duplicates(char *str)
{
	int	i_str_a;
	int	i_str_b;

	i_str_a = 0;
	while (str[i_str_a] != '\0')
	{
		i_str_b = i_str_a + 1;
		while (str[i_str_b])
		{
			if (str[i_str_a] == str[i_str_b])
				return (1);
			i_str_b++;
		}
		i_str_a++;
	}
	return (0);
}

int	has_bad_characters(char *str)
{
	while (*str)
	{
		if (*str == '+' || *str == '-' || *str == ' ')
			return (1);
		str++;
	}
	return (0);
}

int	is_valid_base(char *base)
{
	if ((ft_strlen(base) < 2)
		|| has_duplicates(base)
		|| has_bad_characters(base))
		return (0);
	else
		return (1);
}
