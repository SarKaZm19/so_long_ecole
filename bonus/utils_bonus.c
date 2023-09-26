/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:27:09 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/26 12:32:09 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strdup2(t_data *datas, const char *s)
{
	char	*dup;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		ft_errors(datas, "malloc", 1);
	i = -1;
	while (++i < len)
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin2(t_data *datas, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(sizeof(char) * (len + 1));
	if (!joined)
		ft_errors(datas, "malloc", 1);
	i = 0;
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}

static int	ft_nb_len(int n)
{
	int	count;

	count = 1;
	while (n / 10)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa2(t_data *datas, int n)
{
	int		len;
	char	*nb;
	int		sign;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup2(datas, "-2147483648"));
	else if (n < 0)
	{
		n *= -1;
		sign = -1;
	}
	len = ft_nb_len(n) - sign;
	nb = malloc(sizeof(char) * (len + 1));
	if (!nb)
		ft_errors(datas, "malloc", 1);
	nb[len] = '\0';
	while (--len >= 0)
	{
		nb[len] = n % 10 + 48;
		n = n / 10;
	}
	if (sign == -1)
		nb[0] = '-';
	return (nb);
}

char	*create_str(t_data *datas, char *total, char *dup_str, int nb)
{
	char	*nb_to_str;
	char	*tmp;
	char	*str;

	nb_to_str = ft_itoa2(datas, nb);
	tmp = ft_strjoin2(datas, dup_str, nb_to_str);
	if (nb_to_str)
		free(nb_to_str);
	str = ft_strjoin2(datas, total, tmp);
	if (tmp)
		free(tmp);
	if (total)
		free(total);
	return (str);
}
