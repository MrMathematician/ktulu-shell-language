cmake_minimum_required(VERSION 3.30.2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(seash)

#if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#  add_compile_options(-Winline -fdump-tree-optimized)
#endif()

set(FullOutputDir "$({CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})")

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(${PROJECT_NAME}
    ../src/main.cpp
    ../src/lexer/adders.cpp
)

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/lexer
    ${PROJECT_SOURCE_DIR}/include/parser
    ${PROJECT_SOURCE_DIR}/include/logger
)


