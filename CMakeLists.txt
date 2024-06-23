cmake_minimum_required(VERSION 3.7...3.29)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(picorogue VERSION 0.1.0
                  DESCRIPTION "A small roguelike game"
                  LANGUAGES CXX)

find_package(fmt CONFIG REQUIRED)
find_package(raylib CONFIG REQUIRED)

add_executable(picorogue src/main.cpp)

target_compile_features(picorogue PUBLIC c_std_11)
target_compile_features(picorogue PUBLIC cxx_std_20)

target_link_libraries(picorogue PRIVATE fmt::fmt raylib)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror -fsanitize=undefined -fsanitize=address")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -fsanitize=undefined -fsanitize=address")
    target_link_options(picorogue BEFORE PUBLIC -fsanitize=undefined PUBLIC -fsanitize=address)
endif()
