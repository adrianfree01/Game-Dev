cmake_minimum_required(VERSION 4.5.1)
project(GameDev LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_subdirectory(engine)
add_subdirectory(sandbox)

