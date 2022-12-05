cmake_minimum_required(VERSION 3.1)
project(basic_cpp_with_deps CXX)
add_executable(main main.cpp)

# set(CMAKE_CXX_COMPILER_ID "clang++")


find_package(fmt CONFIG REQUIRED)
target_link_libraries(main PRIVATE fmt::fmt)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400) # The commit hash for 1.9.0. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

target_link_libraries(main PRIVATE cpr::cpr)

# find_package(cpr REQUIRED)
# target_link_libraries(main PRIVATE cpr::cpr)

# add_executable(get get.cpp)


# # Or use the header-only version
# find_package(fmt CONFIG REQUIRED)
# target_link_libraries(main PRIVATE fmt::fmt-header-only)

# # cpr provides CMake targets:

# # this is heuristically generated, and may not be correct
# find_package(cpr CONFIG REQUIRED)
# target_link_libraries(main PRIVATE cpr::cpr)

# set(CMAKE_CXX_COMPILER_ID "/opt/homebrew/opt/llvm/bin/clang++")
# include(FetchContent)
# FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
#                          GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400) # The commit hash for 1.9.0. Replace with the latest from: https://github.com/libcpr/cpr/releases
# FetchContent_MakeAvailable(cpr)
# target_link_libraries(main PRIVATE cpr::cpr)
# target_link_libraries(get PRIVATE cpr::cpr)

# find_package(cpr REQUIRED)
# add_executable(your_target_name your_target_name.cpp)
# target_link_libraries(your_target_name PRIVATE cpr::cpr)
# git clone https://github.com/libcpr/cpr.git
# cd cpr && mkdir build && cd build
# cmake .. -DCPR_USE_SYSTEM_CURL=ON
# cmake --build .
# sudo cmake --install .

# add_executable(get get.cpp)