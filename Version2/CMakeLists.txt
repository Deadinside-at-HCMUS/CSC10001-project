cmake_minimum_required(VERSION 3.21)
project(Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project
        main.cpp menu.h menu.cpp
        book.cpp book.h user.h user.cpp
        ticket.cpp ticket.h day.h
        logo.cpp logo.h
        user.txt book.txt ticket.txt
        user-edited.txt book-edited.txt ticket-edited.txt)
