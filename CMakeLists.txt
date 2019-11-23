cmake_minimum_required(VERSION 3.14)
project(42_Push_swap C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -g")

add_executable(42_Push_swap push_swap.c validation.c GetNextLine/get_next_line.c quicksort.c ft_list.c operation.c operation2.c operation3.c algorithm.c special_case.c special_case2.c array.c lastcheck.c)
add_executable(42_checker checker.c quicksort.c GetNextLine/get_next_line.c operation.c operation2.c operation3.c ft_list.c validation.c array.c lastcheck.c)
add_library(libft STATIC GetNextLine/libft/ft_memset.c GetNextLine/libft/ft_bzero.c GetNextLine/libft/ft_memcpy.c GetNextLine/libft/ft_memccpy.c GetNextLine/libft/ft_memmove.c
        GetNextLine/libft/ft_memchr.c GetNextLine/libft/ft_memcmp.c GetNextLine/libft/ft_strlen.c GetNextLine/libft/ft_strdup.c GetNextLine/libft/ft_strcpy.c GetNextLine/libft/ft_strncpy.c
        GetNextLine/libft/ft_strcat.c GetNextLine/libft/ft_strncat.c GetNextLine/libft/ft_strlcat.c GetNextLine/libft/ft_strchr.c GetNextLine/libft/ft_strrchr.c GetNextLine/libft/ft_strstr.c
        GetNextLine/libft/ft_strnstr.c GetNextLine/libft/ft_strcmp.c GetNextLine/libft/ft_strncmp.c GetNextLine/libft/ft_atoi.c GetNextLine/libft/ft_isalpha.c GetNextLine/libft/ft_isdigit.c
        GetNextLine/libft/ft_isalnum.c GetNextLine/libft/ft_isascii.c GetNextLine/libft/ft_isprint.c GetNextLine/libft/ft_toupper.c GetNextLine/libft/ft_tolower.c
        GetNextLine/libft/ft_memalloc.c GetNextLine/libft/ft_memdel.c GetNextLine/libft/ft_strnew.c GetNextLine/libft/ft_strdel.c GetNextLine/libft/ft_strclr.c GetNextLine/libft/ft_striter.c
        GetNextLine/libft/ft_striteri.c GetNextLine/libft/ft_strmap.c GetNextLine/libft/ft_strmapi.c GetNextLine/libft/ft_strequ.c GetNextLine/libft/ft_strnequ.c GetNextLine/libft/ft_strsub.c
        GetNextLine/libft/ft_strjoin.c GetNextLine/libft/ft_strtrim.c GetNextLine/libft/ft_strsplit.c GetNextLine/libft/ft_itoa.c GetNextLine/libft/ft_putchar.c GetNextLine/libft/ft_putstr.c
        GetNextLine/libft/ft_putendl.c GetNextLine/libft/ft_putnbr.c GetNextLine/libft/ft_putchar_fd.c GetNextLine/libft/ft_putstr_fd.c GetNextLine/libft/ft_putendl_fd.c
        GetNextLine/libft/ft_putnbr_fd.c GetNextLine/libft/ft_isspace.c GetNextLine/libft/ft_strset.c GetNextLine/libft/ft_strjoinfree.c GetNextLine/libft/ft_subfr.c)

include_directories(GetNextLine)
include_directories(GetNextLine/libft/includes)

find_library(LIBFT libft cmake-build-debug)
target_link_libraries(42_Push_swap LINK_PUBLIC ${LIBFT})
target_link_libraries(42_checker LINK_PUBLIC ${LIBFT})