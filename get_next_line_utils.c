#include "get_next_line.h"



int get_line_length(t_node *lines)
{
    int i = 0;
    int len = 0;

    if (!lines)
        return (-1);
    while (lines)
    {
        if (lines->data[i] == '\0')
        {
            lines = lines->next;
            i = -1;
        } 
        else if (lines->data[i] == '\n')
        {
            len += 1;
            break;
        }
        i += 1;
        len += 1;
    }
    return (len);
}

char *copy_line(t_node *lines, int len)
{
    char *result = NULL;
    int i = 0;
    int j = 0;

    if (!lines) return NULL;
    result = malloc(sizeof(char) * (len + 1));
    if (!result) return NULL;
    while (i < len + 1)
        result[i++] = '\0';
    while (lines)
    {
        i = 0;
        while (lines->data[i])
            result[j++] = lines->data[i++];
        lines = lines->next;
    }
    return (result);
}

void add_last_node(t_node **head, char **string)
{
    t_node *ptr;
    t_node *new_node;

    if (!head || !string)
        return;
    new_node = malloc(sizeof(t_node));
    if (!new_node) return;
    new_node->data = *string;
    new_node ->next = NULL;
    if (*head == NULL)
        *head = new_node;
    else 
    {
        ptr = *head;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = new_node;
    }
}

void free_list(t_node *head)
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
	return;
}
