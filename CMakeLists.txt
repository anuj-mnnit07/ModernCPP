cmake_minimum_required(VERSION 3.9.0)
project(moderncpp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)
include(CTest)
enable_testing()

# add_executable(moderncpp src/126_lamda_with_destructor.cpp)
add_executable(moderncpp
    boqian/1_user_defined_literals.cpp
    boqian/6_variadic_template.cpp
    jamesturner/126_lambda_with_destructor.cpp
)
target_link_libraries(moderncpp PRIVATE Catch2::Catch2WithMain)
