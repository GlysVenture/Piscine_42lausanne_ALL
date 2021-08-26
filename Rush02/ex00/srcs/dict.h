#ifndef DICT_H
# define DICT_H

# define MAX_DICT_FILE_NAME_LENGTH 200
# define DEFAULT_DICT "dict/numbers.dict"
# define BUFFER_SIZE 8192
# include "dict_list.h"

/* ************************************************************************** */
/* Parameters argc is the one unchanged from the system call		  		  */
/* custom_dict is always argv[1] !											  */
/* ************************************************************************** */
char	*dict_selector(int argc, char *custom_dict);

/* ************************************************************************** */
/* dict is the filename of selected dictionary (either default or custom)	  */
/* ************************************************************************** */
int		check_dict(char *dict);
int		buffer_init(char *buffer, int size);
void	free_dict(t_dict_list *begin_dict);

#endif
