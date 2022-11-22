/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:58:03 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:58:11 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_words(char **new_arr, size_t nb_of_words)
{
	size_t	i;

	i = 0;
	while (i < nb_of_words)
		free(new_arr[i++]);
	free(new_arr);
	return (0);
}

static size_t	word_count(char const *s, char *sep)
{
	size_t	i;
	size_t	nb_of_words;

	i = 0;
	nb_of_words = 0;
	while (s[i])
	{
		while (s[i] && ft_isset(s[i], sep))
			i++;
		if (s[i] != '\0')
			nb_of_words++;
		while (s[i] && !ft_isset(s[i], sep))
			i++;
	}
	return (nb_of_words);
}

static char	*word_cpy(char const **s, char *sep)
{
	char	*word;
	size_t	i;

	i = 0;
	while (**s && ft_isset((*s)[i], sep))
		(*s)++;
	while ((*s)[i] && !ft_isset((*s)[i], sep))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, *s, i + 1);
	*s = *s + i;
	return (word);
}

char	**ft_split_set(char const *s, char *set)
{
	size_t	i;
	size_t	size;
	char	**new_arr;

	if (s == NULL)
		return (NULL);
	size = word_count(s, set);
	new_arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (new_arr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_arr[i] = word_cpy(&s, set);
		if (new_arr[i] == NULL)
			return (free_words(new_arr, i));
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}
