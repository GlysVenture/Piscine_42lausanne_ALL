#include "check_value.h"
#include "dict.h"
#include "dict_list.h"
#include "error_msg.h"
#include "ft_list_out.h"
#include "ft_number_letter.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int			arg_fail;
	char		*selected_dict;
	t_dict_list	*dict;
	t_out_list	*list;
	char		*number;

	arg_fail = check_argc(argc, argv);
	if (arg_fail)
		return (error_msg(arg_fail));
	selected_dict = dict_selector(argc, argv[1]);
	if (!check_dict(selected_dict))
		return (error_msg(DICT_ERROR));
	dict = build_dict(selected_dict);
	if (!dict)
		return (0);
	number = number_selector(argc, argv);
	list = ft_get_list(dict, number);
	ft_out_list_print(list);
	free_dict(dict);
	free(selected_dict);
	return (0);
}
