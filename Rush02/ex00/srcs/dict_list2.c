#include "check_dict_syntax.h"
#include "dict.h"
#include "dict_list.h"
#include "ft_string.h"
#include <stdlib.h>
#include <fcntl.h>

int	get_value_size(char *line)
{
	int		i;
	int		j;

	i = 0;
	while (line[i] != ':')
		i++;
	i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	j = i;
	while (line[i])
		i++;
	i--;
	while (line[i] == ' ' || line[i] == '\t')
		i--;
	return (i - j + 1);
}

t_dict_list	*build_dict(char *dict)
{
	int			file;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	t_dict_list	*begin_dict;

	file = open(dict, O_RDONLY);
	if (file < 0)
		return (0);
	buffer_init(buffer, sizeof(buffer));
	if (read(file, buffer, BUFFER_SIZE) < 0)
		return (0);
	if (close(file) < 0)
		return (0);
	begin_dict = NULL;
	i = -1;
	while (buffer[++i])
	{
		line = read_line(&buffer[i]);
		if (ft_strlen(line))
			ft_dict_add_end(&begin_dict, get_key(line), get_value(line));
		i += ft_strlen(line);
		free(line);
	}
	return (begin_dict);
}
