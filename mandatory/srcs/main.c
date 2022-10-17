/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:11:19 by aamajane          #+#    #+#             */
/*   Updated: 2022/10/17 16:48:52 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
 * Entry poinf of our program :
 *
 * -> checker() : Parsing methods that may determine if the program will
 *  continue to execution or display an error.
 *
 * -> Create_game() : Game loop containing execution of the program,
 *  raycasting and mlx events.
*/

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		exit(puterror("Cub3D takes only one argument"));
	checker(&data.elm, av[1]);
	create_game(&data);
	return (0);
}

/*
 * Display an error on stderr.
*/

int	puterror(char *str)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	return (EXIT_FAILURE);
}

/*
 * Dealocate mallocated memory.
*/

void	free_double_pointer(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
