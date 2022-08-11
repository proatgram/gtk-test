include(FindPkgConfig)
cmake_minimum_required(VERSION 3.2)

# set(CMAKE_TOOLCHAIN_FILE "/media/thetimbrick/4d2d47b0-3ef2-4c5a-8721-f1970dd6ff77/host/share/buildroot/toolchainfile.cmake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(TestGTK+ VERSION 0.1
DESCRIPTION "Test for GTK+ applications."
LANGUAGES CXX)

pkg_check_modules(GTKMM3 REQUIRED gtkmm-3.0)
pkg_check_modules(GDKMM3 REQUIRED gdkmm-3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

file(GLOB_RECURSE gtk_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE gtk_HEADERS "${CMAKE_SOURCE_DIR}/include/*.h}" "${CMAKE_SOURCE_DIR}/include/*.hpp")

add_executable(gtk ${gtk_SOURCES} ${gtk_HEADERS})

include_directories(AFTER SYSTEM ${GTKMM3_INCLUDE_DIRS} ${GDKMM3_INCLUDE_DIRS})

target_link_libraries(gtk ${GTKMM3_LINK_LIBRARIES} ${GDKMM3_LINK_LIBRARIES})

target_include_directories(gtk PUBLIC ${CMAKE_SOURCE_DIR}/include)
