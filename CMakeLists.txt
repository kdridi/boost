cmake_minimum_required(VERSION 2.8.9)

project(boost)

set (PKG_CONFIG_EXECUTABLE /usr/local/bin/pkg-config)
set (EXECUTABLE_OUTPUT_PATH bin/)
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(Boost 1.50.0)
if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
endif()

file(GLOB_RECURSE source_files
	${CMAKE_SOURCE_DIR}/src/*
)

add_executable(puzzly
	${source_files}
)