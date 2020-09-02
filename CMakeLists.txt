cmake_minimum_required(VERSION 3.16)
project(Pathfinder C)

set(CMAKE_C_STANDARD 11)

file(GLOB Pathfinder_SRC
        "libmx/inc/*.h"
        "libmx/src/*.c"
        "inc/*.h"
        "src/*.c"
        )

add_executable(Pathfinder ${Pathfinder_SRC})
