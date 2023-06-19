/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:40:17 by shuppert          #+#    #+#             */
/*   Updated: 2023/06/19 18:21:57 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

typedef struct node_t
{
	char			*data;
	struct node_t	*next;
}					t_node;

int					add_last_node(t_node **head, char *data, int size);
int					checkForNewLine(char *buffer, t_node **head);
char				*copyLine(t_node **head, int size);
char				*extractFromBuffer(char *buffer, int size);
int					free_list(t_node *head);
char				*ft_strcpy(char *dest, char *src);
int					getLengthOfLine(t_node **head);
char				*get_next_line(int fd);

# endif
#endif