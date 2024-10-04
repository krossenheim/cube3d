/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-lop <jose-lop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:59:43 by jose-lop          #+#    #+#             */
/*   Updated: 2023/10/16 12:22:34 by jose-lop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int n)
{
	return ((n >= 97 && n <= 122) || (n >= 65 && n <= 90));
}
