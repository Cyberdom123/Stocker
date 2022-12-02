cmake_minimum_required(VERSION 3.1)

project(Stocker
VERSION 0.01
LANGUAGES CXX
)

#set reguired version of cpp
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(modules)

#search forr all .cpp .h files in modules dir
file(GLOB SOURCES "./modules/*.cpp" "./modules/*.h")

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)
