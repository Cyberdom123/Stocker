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

file(MAKE_DIRECTORY ../build)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/build" ${CMAKE_MODULE_PATH})

#configure gtkmm package
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-4.0)

link_directories(
    ${GTKMM_LIBRARY_DIRS})

include_directories(
    ${GTKMM_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)

target_link_libraries(${PROJECT_NAME}
${GTKMM_LIBRARIES}
sqlite3)