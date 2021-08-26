#ifndef FT_LIST_OUT_H
# define FT_LIST_OUT_H

typedef struct s_out_list
{
	char				*str;
	struct s_out_list	*next;
}	t_out_list;
t_out_list	*ft_out_create_elem(char *data);
void		ft_out_add_beg(t_out_list **begin_list, char *data);
void		ft_out_list_print(t_out_list *begin_list);

#endif
