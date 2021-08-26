#ifndef DICT_LIST_H
# define DICT_LIST_H

typedef struct s_dict_list
{
	char				*key;
	char				*value;
	struct s_dict_list	*next;
}	t_dict_list;

t_dict_list	*ft_dict_create_elem(char *key, char *value);
void		ft_dict_add_end(t_dict_list **begin_dict, char *key, char *value);
char		*search_dict(t_dict_list *begin_dict, char *number);
char		*get_key(char *line);
char		*get_value(char *line);
int			get_value_size(char *line);
t_dict_list	*build_dict(char *dict);

#endif
