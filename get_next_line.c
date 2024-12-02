/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:43:14 by lleichtn          #+#    #+#             */
/*   Updated: 2024/11/30 16:00:15 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Function that use static var to do a pseudo recursivity and read doc
char	*get_next_line(int fd)
{
	static t_list *stash; // Zone de stockage entre les lectures
	char *buffer;         // Buffer temporaire
	char *line;
	ssize_t bytes_read;
	// step1 : protec check params
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// step2 : allocat pf buffer temp
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	// step3 : read data until \n or end
	while (!ft_strchr(ltos(stash), '\n') && (bytes_read = read(fd, buffer,
				BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0'; // Null-terminate le buffer
		gnl_lstadd_back(&stash, ft_lstnew(ft_strdup(buffer)));
	}
	free(buffer);
	// step4 : manage fails
	if (!stash || !ltos(stash)[0])
	{
		free_lst(&stash);
		return (NULL);
	}
	// step5 : extract la ligne jusqu a \n
	line = ltos(stash);
	// step6 : stash up to date a jour
	stash = ft_lstnew(ft_strdup(ft_strchr(line, '\n') + 1));
	// step7 : return line
	return (line);
}