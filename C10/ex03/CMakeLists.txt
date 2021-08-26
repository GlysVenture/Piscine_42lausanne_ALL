cmake_minimum_required(VERSION 3.3)
project(ex03)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")
set(SOURCE_FILES ft_hexdump.c ft_line.c ft_putnbr_base.c ft_string.c)
add_executable(ex03 ${SOURCE_FILES})

