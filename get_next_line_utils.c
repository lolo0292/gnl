/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:43:10 by lleichtn          #+#    #+#             */
/*   Updated: 2024/11/30 16:01:25 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// init var content and next
t_list	*ft_lstnew(void *content)
{
	t_list	*r;

	r = malloc(sizeof(t_list));
	if (!r)
		return (NULL);
	r->content = content;
	r->next = NULL;
	return (r);
}
// add new at the end of the lst

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*z;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	z = ft_lstlast(*lst);
	z->next = new;
}

// free mem of past elem
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
// free and clear mem with del
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
// return the size of s
size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}
// copie de chaine de char en allouant de la mem dynamique
char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
// Search for c in S
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	else
		return (NULL);
}
// // comvert linked list in a strg
// char	*ltos(t_list *lst)
// {
// 	size_t len;   // store lengh of all strings in th list
// 	t_list *temp; // ptr to iterate in the list
// 	char *str;    // pointer to the final str
// 	size_t i;     // iterate thgh the result str
// 	size_t j;     // ptr to iterade thgh each node
// 	len = 0;
// 	temp = lst;
// 	i = 0;
// 	while (temp) // calculate total lengh of str
// 	{
// 		len += ft_strlen(temp->content);
// 		temp = temp->next;
// 	}
// 	str = malloc((len + 1) * sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	temp = lst; // reset to the beginning of the lst
// 	while (temp) // copy the content of each node in str
// 	{
// 		j = 0;
// 		while (temp->content[j])
// 		{
// 			str[i] = temp->content[j];
// 			i++;
// 			j++;
// 		}
// 		temp = temp->next; //move to the next node
// 	}
// 	str[i] = 0;
// 	return (str);
// }

// free cont of linked lst
static void	free_lst(t_list **lst)
{
	gnl_lstclear(lst, free);
}
size_t	lenght(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		len += ft_strlen(lst->content);
		lst = lst->next;
	}
	return (len);
}
char	*ltos1(t_list *lst, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!str)
		return (NULL);
	while (lst)
	{
		j = 0;
		while (lst->content[j])
		{
			str[i] = lst->content[j];
			i++;
			j++;
		}
		lst = lst->next;
	}
	str[i] = '\0';
	return (str);
}
// comvert linked list in a strg
char	*ltos(t_list *lst)
{
	size_t	len;

	len = length(lst);
	return (ltos1(lst, len));
}
