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
	static char	buffer[BUFFER_SIZE];
	char		*result = NULL;
	t_node		*lines = NULL;
	int			flag = 0;
	int			len = 0;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	flag = 0;
	lines = NULL;
	if (buffer[0] && check_for_newline(buffer, &lines))
		flag = 1;
	while (flag != 1)
	{
		if (!(read(fd, buffer, BUFFER_SIZE)))
		{
			flag = 1;
			if (!lines)
				return (NULL);
		}
		if (check_for_newline(buffer, &lines))
			flag = 1;
	}
	len = get_line_length(lines);
	if (len < 0)
	{
		return (NULL);
	}
	result = copy_line(lines, len);
	free_list(lines);
	return (result);
}

int check_for_newline(char *buffer, t_node **head)
{
    char *line = NULL;
    int index = 0;
    int result = 0;

    if (!buffer)
        return (1);
    while (index < BUFFER_SIZE && buffer[index] != '\0')
    {
        if (buffer[index] == '\n')
        {
            index += 1;
            result = 1;
            break;
        }
        index += 1;
    }
    line = extract_from_buffer(buffer, index);
    add_last_node(head, &line);
    return (result);
}

char *extract_from_buffer(char *buffer, int len)
{
    char *result;
    char temp;
    int i = 0;
    int j = 0;

    if (!buffer || len <= 0)
        return NULL;
    result = (char *)malloc(sizeof(char) * (len + 1));
    if (!result) return NULL;
    while (i < len)
    {
        result[i] = buffer[i];
        i += 1;
    }
    result[i] = '\0';
    while (i < BUFFER_SIZE && buffer[i] != '\0')
    {
        temp = buffer[i++];
        buffer[j++] = temp;
    }
    while (j < BUFFER_SIZE)
        buffer[j++] = '\0';
    return (result);
}