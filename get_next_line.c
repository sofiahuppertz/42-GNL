/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:39:41 by shuppert          #+#    #+#             */
/*   Updated: 2023/06/15 19:05:40 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*newLine;
	static char	BUFF[BUFFER_SIZE];
	t_node		**lines;
	static int	flagFile;
	int			flag_line;
	int			bytesCount;

	//PRIOR CHECKING
	if (fd == NULL || BUFFER_SIZE <= 0 || flagFile == 2)
	{
		return (NULL);
	}
	//Check the BUFF + read the function.
	flag_line = 0;
	lines = NULL;
	if (BUFF[0] != '\0') //if there is something in the buffer.
	{
		if (checkForNewLine(BUFF, lines)) //if the buffer has a full line.
			flag_line = 1;
		else
		{
			add_last_node(lines, BUFF);
			initialize_buffer(BUFF, BUFFER_SIZE);
		}
	}
	if (BUFF[0] == '\0')
	{
		while (flag_line != 1 && flagFile != 2)
		{
			if (!(read(fd, BUFF, BUFFER_SIZE)))
			{
				flagFile = 2;
			}
			if (checkForNewLine(BUFF, lines))
			{
				flag_line = 1;
			}
		}
	}
	bytesCount = getLengthOfLine(lines);
	newLine = copyLine(lines, bytesCount);
	free_list(lines);
	return (newLine);
}

int	initialize_buffer(char *buffer, int size)
//optimize by eliminating this function
{
	int i;

	if (!buffer || size <= 0)
	{
		return (1);
	}
	i = 0;
	while (i < size)
	{
		buffer[i] = '\0';
		i++;
	}
	return (0);
}

int	free_list(t_node **head)
{
	t_node *current;
	char *temp;

	if (!head)
	{
		return (1);
	}
	current = *head;
	while (current->next != NULL)
	{
		temp = current->data;
		free(temp);
		current = current->next;
	}
	*head = NULL;
	return (0);
}

