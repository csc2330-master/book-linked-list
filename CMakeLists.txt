cmake_minimum_required(VERSION 3.17)
project(book_linked_list)

set(CMAKE_CXX_STANDARD 14)

add_executable(book_linked_list test.cpp book.cpp book.h list.cpp list.h)