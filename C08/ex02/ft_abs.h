#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(value) ((value + (value >> 31) ^ (value >> 31)))

#endif
