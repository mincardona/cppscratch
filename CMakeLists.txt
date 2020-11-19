cmake_minimum_required(VERSION 3.13.0 FATAL_ERROR)

# main project
project(mji-cppscratch VERSION 0.1.0 LANGUAGES CXX)

include(CTest)

# library
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(cppscratch INTERFACE)

# headers
set(LibIncludeDirRel "include/")
set(LibHeadersRel "mji/math.hpp" "mji/algorithm.hpp" "mji/memory.hpp" "mji/xplat.hpp")
set(LibHeadersAbs "${LibHeadersRel}")
list(TRANSFORM LibHeadersAbs PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/${LibIncludeDirRel}")
target_include_directories(cppscratch INTERFACE "${LibIncludeDirRel}")

# sources
set(LibSourceDirRel "src/")
set(LibSourcesRel "")
set(LibSourcesAbs "${LibSourcesRel}")
list(TRANSFORM LibSourcesAbs PREPEND "${LibSourceDirRel}")
target_sources(cppscratch INTERFACE "${LibHeadersAbs}" "${LibSourcesAbs}")

# tests
add_executable(${PROJECT_NAME}-tests "${CMAKE_CURRENT_SOURCE_DIR}/tests/main.cpp")
target_compile_options(${PROJECT_NAME}-tests PRIVATE
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic>)
target_link_libraries(${PROJECT_NAME}-tests PRIVATE cppscratch)
add_test(NAME mji::cppscratch::tests
         CONFIGURATIONS DEBUG
         COMMAND ${PROJECT_NAME}-tests)
