/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:48:53 by fvastena          #+#    #+#             */
/*   Updated: 2023/10/02 21:25:38 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

unsigned long	gettime(t_data *datas)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		ft_errors(datas, "gettimeofday", 1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}