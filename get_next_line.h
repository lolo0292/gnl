/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:49:36 by lleichtn          #+#    #+#             */
/*   Updated: 2024/11/30 15:59:00 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* DEFINES                                                                    */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* ************************************************************************** */
/* INCLUDES                                                                   */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

/* ************************************************************************** */
/* STRUCTURES                                                                 */
/* ************************************************************************** */
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

/* ************************************************************************** */
/* PROTO                                                                      */
/* ************************************************************************** */
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
static void			free_lst(t_list **lst);
char				*ltos(t_list *lst);
char				*ltos1(t_list *lst, size_t len);
size_t				lenght(t_list *lst);

/* ************************************************************************** */
/* DEBUG                                                                      */
/* ************************************************************************** */

#endif