/* ************************************************************************** */
/*																			  */
/*														:::	  ::::::::   	  */
/*   main.c											 :+:	  :+:	:+:  	  */
/*													+:+ +:+		 +:+		  */
/*   By: jonascim <jonascim@student.42.fr>		  +#+  +:+	   +#+			  */
/*												+#+#+#+#+#+   +#+		      */
/*   Created: 2023/07/08 15:40:57 by jonascim		  #+#	#+#				  */
/*   Updated: 2023/07/08 17:42:24 by jonascim		 ###   ########.fr	      */
/*																			  */
/* ************************************************************************** */

#include "../includes/rush01_tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_data	data;
	// char	ch;
	// int		i, j;

	if (argc != 2)
	{
		printf("There has to be 1 argument.\n");
		printf("You can achieve this by putting all the arguments into a string.\n");
		return (1);
	}
	// (void) argc;
	ft_data_struct_init(&data);
	char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int c = 0;
    char size[100];

    while ((read = getline(&line, &len, stdin)) != -1) 
    {
        data.line_length++;
        // Every read from getline indicates a new line
        for (int i = 0; i < read; i++)
        {
            if (line[i] > '0' && line[i] <= '9')
            {
                size[c] = line[i];
                c++;
            }
			else if (line[i] != ' ' && line[i] != '\n')
			{
				printf("There are stuff in your matrix that does not belong there.\n");
				printf("That could be either a character or a 0.\n");
				return(1);
			}
        }
    }
	if (line)
			free(line);

	if (c < 16 ||  c != data.line_length * data.line_length)
	{
		printf("Matrix is not complete.\n");
		return (1);
	}
	printf("Size of your matrix: %dx%d \n", data.line_length, data.line_length);
	printf("Your matrix:\n");
	//memory allocation for matrix
	ft_matrix_allocation(&data);

	//rewind the stdin to read the lines again
	rewind(stdin);
	ft_matrix_assign(&data, size);

	//Print matrix
	ft_print_matrix(&data);

	//Allocation for clues rows and colums
	clues_allocation_assign(&data, argv);
	ft_print_clues(&data);

	if (the_check(&data))
	{
		int fd;
		fd = open("output", O_RDONLY);
		if (fd != -1)
			unlink("output");	
		return (1);
	}
	else
		printf("Successful! Good job!\n");

	//output it into a file for FDF
	create_file_for_fdf(&data);
	//free allocated memory
	free_all(&data);
	return (0);
}
