#include "get_next_line.h"

int	checkForNewLine(char *buffer, t_node **head)
{
	int		bit_idx;
	char	*temp;

	//iterate through the buffer until new line, counting bit_idx.
	bit_idx = 0;
	while (bit_idx < BUFFER_SIZE || buffer[bit_idx] != '\0')
		;
	{
		if (buffer[bit_idx] == '\n')
		{
			temp = extractFromBuffer(buffer, bit_idx + 1);
			add_last_node(head, temp);
			free(temp);
			return (1);
		}
		bit_idx++;
	}
	temp = extractFromBuffer(buffer, bit_idx + 1);
	add_last_node(head, temp);
	free(temp);
	return (0);
}

char	*extractFromBuffer(char *buffer, int size)
{
	char	*extracted_string;
	char	temp;
	int		i;
	int		j;

	extracted_string = malloc(sizeof(char) * size + 1);
	//for the NULL terminator.
	i = 0;
	while (i < size)
	{
		extracted_string[i] = buffer[i];
		i++;
	}
	j = 0;
	while (i < BUFFER_SIZE || buffer[i] == '\0')
	{
		temp = buffer[i];
		buffer[j] = temp;
		i++;
		j++;
	}
	initialize_buffer((buffer + j), (BUFFER_SIZE - j));
	return (extracted_string);
}

int	getLengthOfLine(t_node **head)
{
	int		bytes_count;
	t_node	*current;
	int		i;

	bytes_count = 1;
	current = *head;
	i = 0;
	while (current->data[i] != '\n')
	{
		if (current->data[i] == '\0')
		{
			current = current->next;
			i = 0;
		}
		else
			i++;
		bytes_count++;
	}
	return (bytes_count);
}

char	*copyLine(t_node **head, int size)
{
	char	*new_line;
	t_node	*current;
	int		i;
	int		j;

	if (!head || size <= 0)
	{
		return (NULL);
	}
	new_line = (char *)malloc(sizeof(char) * size + 1);
	if (new_line == NULL)
		return (NULL);
	current = *head;
	i = 0;
	j = 0;
	while (i < size)
	{
		if (current->data[i] == '\0')
		{
			current = current->next;
			i = 0;
		}
		new_line[j] = current->data[i];
		i++;
		j++;
	}
	new_line[size] = '\0';
	return (new_line);
}

int	add_last_node(t_node **head, char *data)
{
	t_node	*new_node;
	t_node	*last_node;

	last_node = *head;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (1);
	new_node->data = data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = new_node;
	}
	return (0);
}
