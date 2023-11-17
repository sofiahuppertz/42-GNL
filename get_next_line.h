/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:40:17 by shuppert          #+#    #+#             */
/*   Updated: 2023/06/22 18:57:25 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
//# include "../Libft/headers/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

typedef struct node_t
{
	char			*data;
	struct node_t	*next;
}					t_node;

void 				add_last_node(t_node **head, char **string);
void				free_list(t_node *head);
int 				check_for_newline(char *buffer, t_node **head);
int 				get_line_length(t_node *lines);
int					get_next_line(int fd, char **line);
char 				*copy_line(t_node *lines, int len);
char 				*extract_from_buffer(char *buffer, int len);

# endif
#endif