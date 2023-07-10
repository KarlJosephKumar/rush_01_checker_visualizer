/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:49:43 by kakumar           #+#    #+#             */
/*   Updated: 2023/07/10 19:40:05 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01_tester.h"

static int check_map_validity_rows(t_data *data)
{
	int i, j;
	int *array;

	i = 0;
	j = 0;
	while (i < data->line_length)
	{
		array = calloc(data->line_length, sizeof(int));
		j = 0;
		while (j < data->line_length)
		{
			if (is_valid_value(array, data->matrix[j][i]))
			{
				printf("success\n");
				sleep(3);
				printf("\n\nJust kidding XD\n");
				printf("Validity issues in column verification.\n");
				printf("Column: %i\n", i + 1);
				return (1);
			}
			j++;
		}
		i++;
		free(array);
	}
	return (0);
}

static int check_map_validity_columns(t_data *data)
{
	int i, j;
	int *array;

	i = 0;
	j = 0;
	while (i < data->line_length)
	{
		array = calloc(data->line_length, sizeof(int));
		j = 0;
		while (j < data->line_length)
		{
			if (is_valid_value(array, data->matrix[i][j]))
			{
				printf("success\n");
				sleep(3);
				printf("\n\nJust kidding XD\n");
				printf("Validity issues in row verification.\n");
				printf("Row: %i\n", i + 1);
				return (1);
			}
			j++;
		}
		i++;
		free(array);
	}
	return (0);
}

static int	check_top_to_bot(t_data *data)
{
	int	i = 0;
	int	j = 0;
	int	counter = 0;
	int	curr_size = 0;

	while (j < data->line_length)
	{
		counter = 0;
		curr_size = 0;
		i = 0;
		while (i < data->line_length)
		{
			if (curr_size < data->matrix[i][j])
			{
				counter++;
				curr_size = data->matrix[i][j];
			}
			i++;
		}
		if (counter != (data->top_row[j] - 48))
		{
			printf("success\n");
			sleep(3);
			printf("\n\nJust kidding XD\n");
			printf("There was a problem in validating from top to bottom.\n");
			printf("Check column: %i", j);
			return (1);
		}
		j++;
	}
	return (0);
}

static int	check_bot_to_top(t_data *data)
{
	int i = data->line_length - 1;
	int j = 0;
	int counter = 0;
	int curr_size = 0;

	while (j < data->line_length)
	{
		counter = 0;
		curr_size = 0;
		i = data->line_length - 1;
		while (i + 1 > 0)
		{
			if (curr_size < data->matrix[i][j])
			{
				counter++;
				curr_size = data->matrix[i][j];
			}
			i--;
		}
		if (counter != (data->bottom_row[j] - 48))
		{
			printf("success\n");
			sleep(3);
			printf("\n\nJust kidding XD\n");
			printf("There was a problem in validating from bottom to top.\n");
			printf("Check column: %i", j);
			return (1);
		}
		j++;
	}
	return (0);
}

static int	check_left_to_right(t_data *data)
{
	int i = 0;
	int j = 0;
	int counter = 0;
	int curr_size = 0;

	while (i < data->line_length)
	{
		counter = 0;
		curr_size = 0;
		j = 0;
		while (j < data->line_length)
		{
			if (curr_size < data->matrix[i][j])
			{
				counter++;
				curr_size = data->matrix[i][j];
			}
			j++;
		}
		if (counter != (data->left_column[i] - 48))
		{
			printf("success\n");
			sleep(3);
			printf("\n\nJust kidding XD\n");
			printf("There was a problem in validating from left to right.\n");
			printf("Check row: %i", i);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_right_to_left(t_data *data)
{
	int i = 0;
	int j = data->line_length - 1;
	int counter = 0;
	int curr_size = 0;

	while (i < data->line_length)
	{
		counter = 0;
		curr_size = 0;
		j = data->line_length - 1;
		while (j + 1 > 0)
		{
			if (curr_size < data->matrix[i][j])
			{
				counter++;
				curr_size = data->matrix[i][j];
			}
			j--;
		}
		if (counter != (data->right_column[i] - 48))
		{
			printf("success\n");
			sleep(3);
			printf("\n\nJust kidding XD\n");
			printf("There was a problem in validating from right to left.\n");
			printf("Check row: %i", i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	the_check(t_data *data)
{

	if (check_map_validity_columns(data) || \
	check_map_validity_rows(data) || \
	check_top_to_bot(data) || \
	check_bot_to_top(data) || \
	check_left_to_right(data) || \
	check_right_to_left(data))
	{
		printf("RIP\n");
		return (1);
	}
	return (0);
}
