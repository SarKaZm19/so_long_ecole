/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:43:51 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/20 19:24:33 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_add_buf_to_line(t_data *datas, char *line, char c)
{
	int		len_line;
	char	*new_line;
	int		i;

	if (c == '\0')
		return (line);
	len_line = ft_strlen(line);
	new_line = malloc(sizeof(char) * (len_line + 2));
	if (!new_line)
		ft_errors(datas, "malloc", 1);
	i = 0;
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i++] = c;
	new_line[i] = '\0';
	if (line)
		free(line);
	return (new_line);
}

char	*ft_read(t_data *datas)
{
	char	*line;
	int		ret;
	char	buf;

	buf = '\0';
	line = NULL;
	ret = 1;
	while (buf != '\n' && ret != 0)
	{
		ret = read(datas->fd, &buf, 1);
		if (ret == -1)
			ft_errors(datas, "read", 1);
		if (ret != 0)
			line = ft_add_buf_to_line(datas, line, buf);
		if (!line)
			return (NULL);
	}
	return (line);
}
