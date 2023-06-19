/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:39:41 by shuppert          #+#    #+#             */
/*   Updated: 2023/06/19 18:21:43 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*newLine;
	static char	BUFF[BUFFER_SIZE];
	t_node		*lines;
	static int	flagFile;
	int			flag_line;
	int			bytesCount;

	//PRIOR CHECKING
	if (!fd || BUFFER_SIZE <= 0 || flagFile == 2)
	{
		return (NULL);
	}
	//Check the BUFF + read the function.
	bytesCount = 0;
	flag_line = 0;
	lines = NULL;
	if (BUFF[0]) //if there is something in the buffer.
	{
		if (checkForNewLine(BUFF, &lines)) //if the buffer has a full line.
			flag_line = 1;
	}
	while (flag_line != 1 && flagFile != 2)
	{
		if (!(read(fd, BUFF, BUFFER_SIZE)))
		{
			flagFile = 2;
		}
		if (checkForNewLine(BUFF, &lines))
		{
			flag_line = 1;
		}
	}
	bytesCount = getLengthOfLine(&lines);
	newLine = copyLine(&lines, bytesCount);
	free_list(lines);
	return (newLine);
}

int	free_list(t_node *head)
{
	t_node *current;
	char *temp;

	while (head != NULL)
	{
		current = head;
		temp = current->data;
		head = head->next;
		free(temp);
		free(current);
	}
	return 0;
}

char *ft_strcpy(char *dest, char *src)
{
	char *return_ptr;
	if(dest == NULL)
	{
		return (NULL);
	}
	return_ptr = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (return_ptr);
}