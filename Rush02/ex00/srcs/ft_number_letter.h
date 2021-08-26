#ifndef FT_NUMBER_LETTER_H
# define FT_NUMBER_LETTER_H

# include "ft_list_out.h"
# include "dict_list.h"
void		ft_add_strings(t_out_list **l, t_dict_list *d, char *numb);
char		*ft_search_numb(t_dict_list *begin_dict, char numb, int info);
char		*ft_get_findable(char numb, int info);
void		ft_add_str(t_out_list **l, t_dict_list *d, char *numb, int *v);
t_out_list	*ft_get_list(t_dict_list *begin_dict, char *numb);
char		*ft_store_string(char *str);
char		*ft_neg_tofind(char numb, int info);

#endif
