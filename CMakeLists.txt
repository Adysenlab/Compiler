#Minimum version of CMake to build this project
cmake_minimum_required(VERSION 2.6)

# Declaration et nommage du projet
project(parser)
set(PROGRAM_NAME ${PROJECT-NAME})
set(CXX "g++")



# The version number shown by the parser software that matters.
set (PARSE_VERSION_MAJOR "0")
set (PARSE_VERSION_MINOR "001")
set (PARSE_VERSION_PATCH "0")
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/VersionConfig.h.in"
  "${PROJECT_BINARY_DIR}/VersionConfig.h"
)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -W -Werror -pedantic -g")
set(CMAKE_CXX_FLAGS "-O3 -Wall -W -pedantic -std=c++11")

#Defines subdirectory
add_subdirectory(compiler/)


#the versioning of the release tools that the system is to provide 
set(CPACK_PACKAGE_VERSION_MAJOR ${PARSE_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PARSE_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PARSE_VERSION_PATCH})
set(LIB_VERSION_STRING ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH})
set_target_properties(${PROGRAM_NAME} PROPERTIES VERSION ${LIB_VERSION_STRING})
set (CPACK_RESOURCE_FILE_LICENSE  
     "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_CONTACT "Support on toy-language <adysenlab@gmail.com>")


set(CPACK_GENERATOR "DEB")
include (CPack)



