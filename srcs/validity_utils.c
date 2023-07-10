/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:49:50 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/10 17:32:10 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01_tester.h"

int	is_valid_value(int *array, char c)
{
	int	i;

	i = c - 48;
	if (array[i - 1])
	{
		// printf("This number already exists in this line BRUH\n");
		return (1);
	}
	array[i - 1]++;
	return (0);
}

