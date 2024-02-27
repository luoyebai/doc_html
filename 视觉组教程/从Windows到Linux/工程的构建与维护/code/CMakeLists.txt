# ====================================####
# ====set project basic properties====####
# ====================================####
cmake_minimum_required(VERSION 3.8)
project(main)

# c++17
set(CMAKE_CXX_STANDARD 17)
# no compiler extension
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0") 

# ####=====================####
# ####====set src files====####
# ####=====================####
file(GLOB src_files src/*.c src/*.cpp)
include_directories(include)
add_executable(${PROJECT_NAME} ${src_files})

# ========================####
# ====additional links====####
# ========================####
# target_link_libraries(${PROJECT_NAME} xxx)

# ==================####
# ====build test====####
# ==================####


# ================####
# ==== install====####
# ================####
