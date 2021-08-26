#include "check_dict_syntax.h"
#include "dict.h"
#include "dict_list.h"
#include "ft_string.h"
#include <fcntl.h>

char	*dict_selector(int argc, char *custom_dict)
{
	if (argc == 2)
		return (ft_strdup(DEFAULT_DICT));
	else
		return (ft_strdup(custom_dict));
}

int	buffer_init(char *buffer, int size)
{
	while (--size >= 0)
		buffer[size] = 0;
	return (0);
}

int	read_cut_dict(char *buffer)
{
	int		i;
	char	*line;

	if (ft_strlen(buffer) < 3)
		return (0);
	i = -1;
	while (buffer[++i])
	{
		line = read_line(&buffer[i]);
		if (ft_strlen(line))
			if (!check_dict_syntax(line))
				return (0);
		i += ft_strlen(line);
		free(line);
	}
	return (1);
}

int	check_dict(char *dict)
{
	int		file;
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	int		total_bytes;

	file = open(dict, O_RDONLY);
	if (file < 0)
		return (0);
	total_bytes = buffer_init(buffer, sizeof(buffer));
	while (1)
	{
		bytes_read = read(file, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (0);
		if (!bytes_read)
			break ;
		total_bytes += bytes_read;
	}
	if (close(file) < 0 || total_bytes > BUFFER_SIZE || !read_cut_dict(buffer))
		return (0);
	return (1);
}

//FREE DICTIONNAIRE //////////////////////////////////
void	free_dict(t_dict_list *begin_dict)
{
	t_dict_list		*temp;

	while (begin_dict)
	{
		temp = begin_dict->next;
		free(begin_dict->value);
		free(begin_dict->key);
		free(begin_dict);
		begin_dict = temp;
	}
}
