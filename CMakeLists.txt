cmake_minimum_required(VERSION 3.13)

project(aoc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

function(add_day YEAR DAY)
    set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${YEAR}/${DAY})
    set(BIN_DIR ${CMAKE_CURRENT_BINARY_DIR}/${YEAR}/${DAY})
    
    # Manually select target output directory
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

    foreach(PART RANGE 1 2)
        if(EXISTS ${SRC_DIR}/part${PART}.cpp)
            file(MAKE_DIRECTORY "${BIN_DIR}")
            add_executable(year${YEAR}_day${DAY}_part${PART} ${SRC_DIR}/part${PART}.cpp)
        endif()
    endforeach()
    if(EXISTS ${SRC_DIR}/input.txt)
        file(CREATE_LINK ${SRC_DIR}/input.txt ${BIN_DIR}/input.txt SYMBOLIC)
    endif()
endfunction()


add_library(aoc_stdin STATIC aoc_stdin.cpp)
add_compile_options(-Wall -Wextra -Wshadow -Wconversion)
link_libraries(-Wl,--whole-archive aoc_stdin -Wl,--no-whole-archive)

foreach(YEAR RANGE 2025 2025)
    foreach(DAY RANGE 1 25)
        add_day(${YEAR} ${DAY})
    endforeach()
endforeach()
