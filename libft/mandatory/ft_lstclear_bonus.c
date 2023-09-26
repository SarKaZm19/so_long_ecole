/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:14:53 by fvastena          #+#    #+#             */
/*   Updated: 2022/10/31 13:15:24 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*res;

	if (del && lst && *lst)
	{
		while (*lst)
		{
			res = (*lst)->next;
			ft_lstdelone(*lst, del);
			*(lst) = res;
		}
	}
}
