/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxFunctions->c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:39:57 by jonascim          #+#    #+#             */
/*   Updated: 2023/07/10 15:31:49 by jonascim         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01_tester.h"

void	ft_data_struct_init(t_data *data)
{
	data->line_length = 0;
	data->top_row = NULL;
	data->bottom_row = NULL;
	data->left_column = NULL;
	data->right_column = NULL;
	data->matrix = NULL;
	return ;
}

void	ft_matrix_allocation(t_data *data)
{
	int	i;

	i = 0;
	data->matrix = (char **)malloc(sizeof(char *) * data->line_length);
	if (!data->matrix)
		return ;
	while (i < data->line_length)
	{
		data->matrix[i] = (char *)malloc(sizeof(char) * data->line_length);
		if (!data->matrix[i])
		{
			while (i)
			{
				i--;
				free(data->matrix[i]);
			}
			free(data->matrix);
			return ;
		}
		i++;
	}
	return ;
}

// Matrix (result from their program) assign
// void	ft_matrix_assign(t_data *data)
// {
// 	int	i, j;

// 	i = 0;
// 	j = 0;
// 	while (i < data->line_length)
// 	{
// 		j = 0;
// 		while (j < data->line_length)
// 		{
// 			data->matrix[i][j] = getchar();
// 			getchar();
// 			j++;
// 		}
// 		i++;
// 	}
// 	return ;
// }

void    ft_matrix_assign(t_data *data, char size[100])
{
    int    i, j;

    i = 0;
    j = 0;
    while (i < data->line_length)
    {
        j = 0;
        while (j < data->line_length)
        {
            data->matrix[i][j] = size[i * data->line_length+j];
            j++;
        }
        i++;
    }
}

// memory allocation for the input lines and rows
void	clues_allocation_assign(t_data *data, char **argv)
{
	int	i, j;

	i = 0;
	j = 0;
	data->top_row = (char *)malloc(sizeof(char) * data->line_length + 1);
	data->bottom_row = (char *)malloc(sizeof(char) * data->line_length + 1);
	data->left_column = (char *)malloc(sizeof(char) * data->line_length + 1);
	data->right_column = (char *)malloc(sizeof(char) * data->line_length + 1);
	if (!data->top_row || !data->bottom_row || !data->left_column || !data->right_column)
		return (free_all(data));
	while (argv[1][i])
	{
		if (j == data->line_length)
			j = 0;
		if (argv[1][i] == ' ')
			i++;
		else
		{
			if (i < 2 * data->line_length)
				data->top_row[i - j] = argv[1][i];
			else if (i >= data->line_length * 2 && i < 4 * data->line_length)
				data->bottom_row[j] = argv[1][i];
			else if (i >= 4 * data->line_length && i < 6 * data->line_length)
				data->left_column[j] = argv[1][i];
			else if (i >= 6 * data->line_length && i < 8 * data->line_length)
				data->right_column[j] = argv[1][i];
			j++;
			i++;
		}
	}
	data->top_row[data->line_length] = '\0';
	data->bottom_row[data->line_length] = '\0';
	data->left_column[data->line_length] = '\0';
	data->right_column[data->line_length] = '\0';
	return ;
}

// Freeing allocated memory
void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->line_length)
	{
		free(data->matrix[i]);
		i++;
	}
	if (data->matrix)
		free(data->matrix);
	if (data->top_row)
		free(data->top_row);
	if (data->bottom_row)
		free(data->bottom_row);
	if (data->right_column)
		free(data->right_column);
	if (data->left_column)
		free(data->left_column);
}

// print the matrix
void	ft_print_matrix(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->line_length)
	{
		j = 0;
		while (j < data->line_length)
		{
			printf("%c ", data->matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_print_clues(t_data *data)
{
	printf("\n");
	printf("Top Row     : %s\n", data->top_row);
	printf("Bottom Row  : %s\n", data->bottom_row);
	printf("Left Column : %s\n", data->left_column);
	printf("Right Column: %s\n", data->right_column);
	printf("\n");
	return ;
}

int create_file_for_fdf(t_data *data)
{
	FILE *file;

    file = fopen("output", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return (1);
    }
	int i = 0;
	int j = 0;
	while (i++ < data->line_length * 2 + 2)
	{
		fprintf(file, "%c", '0');
		if (i < (data->line_length * 2) + 2)
				fprintf(file, " ");
	}
	fprintf(file, "\n");
	i = 0;
	while (i < data->line_length)
	{
		// double numbers, first line
		j = 0;
		fprintf(file, "%c", '0');
		fprintf(file, " ");
		while (j < data->line_length)
		{
			fprintf(file, "%c", data->matrix[i][j]);
			fprintf(file, " ");
			fprintf(file, "%c", data->matrix[i][j]);
			if (j < data->line_length * 2)
				fprintf(file, " ");
			j++;
		}
		fprintf(file, "%c", '0');
		fprintf(file, "\n");
		// same numbers, second line
		j = 0;
		fprintf(file, "%c", '0');
		fprintf(file, " ");
		while (j < data->line_length)
		{
			fprintf(file, "%c", data->matrix[i][j]);
			fprintf(file, " ");
			fprintf(file, "%c", data->matrix[i][j]);
			if (j < data->line_length * 2)
				fprintf(file, " ");
			j++;
		}
		fprintf(file, "%c", '0');
		fprintf(file, "\n");
		i++;
	}
	i = 0;
	while (i++ < data->line_length * 2 + 2)
	{
		fprintf(file, "%c", '0');
		if (i < (data->line_length * 2 + 2))
				fprintf(file, " ");
	}
	fprintf(file, "\n");
    fclose(file);
	return (0);
}
