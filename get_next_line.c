/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:39:41 by shuppert          #+#    #+#             */
/*   Updated: 2023/06/22 19:04:24 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*newline;
	static char	_buff[BUFFER_SIZE];
	t_node		*lines;
	int			flag_line;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		return (NULL);
	}
	flag_line = 0;
	lines = NULL;
	if (_buff[0])
	{
		if (check_for_newline(_buff, &lines))
			flag_line = 1;
	}
	while (flag_line != 1)
	{
		if (!(read(fd, _buff, BUFFER_SIZE)))
		{
			flag_line = 1;
			if (!lines)
			{
				return (NULL);
			}
		}
		if (check_for_newline(_buff, &lines))
		{
			flag_line = 1;
		}
	}
	count = get_line_length(&lines);
	if (count < 0)
	{
		return (NULL);
	}
	newline = copy_line(&lines, count);
	free_list(lines);
	return (newline);
}

int	free_list(t_node *head)
{
	t_node	*current;
	char	*temp;

	while (head != NULL)
	{
		current = head;
		temp = current->data;
		head = head->next;
		free(temp);
		free(current);
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	char *return_ptr;
	if (dest == NULL)
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