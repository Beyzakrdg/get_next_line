/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekarada <bekarada@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:30:28 by bekarada          #+#    #+#             */
/*   Updated: 2024/11/18 15:22:35 by bekarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_join(char *str1, char *str2)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	if (!str1)
	{
		str1 = malloc(1);
		str1[0] = '\0';
	}
	i = 0;
	j = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (str1[i])
		res[j++] = str1[i++];
	i = 0;
	while (str2[i])
		res[j++] = str2[i++];
	res[len] = '\0';
	free(str1);
	return (res);
}

char	*ft_new_line(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_new_string(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * ((ft_strlen(str) - i) + 1));
	if (!res)
		return (NULL);
	i++;
	while (str[i])
	{
		res[j++] = str[i++];
	}
	res[j] = '\0';
	free(str);
	return (res);
}
