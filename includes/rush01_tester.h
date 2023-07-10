/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_tester.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:40:25 by jonascim          #+#    #+#             */
/*   Updated: 2023/07/10 19:31:41 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_TESTER_H
# define RUSH01_TESTER_H

# define ERROR 1

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	char	*top_row;
	char	*bottom_row;
	char	*left_column;
	char	*right_column;
	char	**matrix;
	int		line_length;
}		t_data;

//checker functions
int		is_valid_value(int array[4], char c);
int		the_check(t_data *data);

//Auxiliar Functions
void	ft_data_struct_init(t_data *data);
void	ft_matrix_allocation(t_data *data);
void	ft_matrix_assign(t_data *data, char size[100]);
void	clues_allocation_assign(t_data *data, char **argv);
void	ft_print_matrix(t_data *data);
void	ft_print_clues(t_data *data);
void	free_all(t_data *data);
int		create_file_for_fdf(t_data *data);
#endif
