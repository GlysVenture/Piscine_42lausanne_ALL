#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define EXECUTABLE_NAME "rush-02"

# define INVALID_ARG_COUNT 1
# define INVALID_INT_INPUT 2
# define CANNOT_CONVERT_INT 4
# define DICT_ERROR	8

/* ************************************************************************** */
/* Allowed msg are : INVALID_ARG_COUNT, INVALID_INT_INPUT,					  */
/* 					 CANNOT_CONVERT_INT, DICT_ERROR							  */
/* ************************************************************************** */
int	error_msg(char msg);

#endif
