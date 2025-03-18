cmake_minimum_required(VERSION 3.30.2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(ktulu)

#if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#  add_compile_options(-Winline -fdump-tree-optimized)
#endif()

option(ENABLE_TEST "Enable test mode" OFF) 

if(ENABLE_TEST) 
  add_definitions(-DTEST)
endif()


set(FullOutputDir "$({CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})")

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
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
    ${PROJECT_SOURCE_DIR}/include/syntax_analyzer
    ${PROJECT_SOURCE_DIR}/include/ast_gen
    ${PROJECT_SOURCE_DIR}/include/logger
)


