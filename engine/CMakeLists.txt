include(FetchContent)

FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG 3.5.1)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE) 

FetchContent_Declare(cglm GIT_REPOSITORY https://github.com/recp/cglm GIT_TAG v0.9.7)
set(CGLM_SHARED OFF CACHE BOOL "" FORCE)
set(CGLM_STATIC ON CACHE BOOL "" FORCE)

FetchContent_Declare(glad GIT_REPOSITORY https://github.com/Dav1dde/glad GIT_TAG v2.0.8 SOURCE_SUBDIR cmake)

FetchContent_MakeAvailable(glfw cglm glad)
glad_add_library(glad_gl_core_33 REPRODUCIBLE API gl:core=3.3)

add_library(engine STATIC)
target_include_directories(engine
    PRIVATE
        src/include
)

target_link_libraries(engine
    PRIVATE
        glfw
        cglm
        glad_gl_core_33
)

target_sources(engine
    PRIVATE
        "src/platform/window.c"
        "src/render/render.c"
        "src/core/engine.c"
    PUBLIC
        FILE_SET HEADERS # Quick little shortcut, if FILE_SET name = TYPE, you can leave out TYPE
        BASE_DIRS
            include
)

target_compile_options(engine
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)