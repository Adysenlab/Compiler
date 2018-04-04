
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB HH_FILES *.hh)
file(GLOB SRC_FILES *.cc)
file(GLOB HXX_FILES *.hxx)

find_package(BISON)
find_package(FLEX)

bison_target(Parser grammer.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cc)
flex_target(Scanner lexicon.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cc)

add_flex_bison_dependency(Scanner Parser)

add_library(parse
            STATIC
            ${FLEX_Scanner_OUTPUTS}
            ${BISON_Parser_OUTPUTS}
            ${HH_FILES}
            ${SRC_FILES}
            ${HXX_FILES}
)

############################################################
# Create a Doxygen documentation
############################################################


if (CMAKE_BUILD_TYPE MATCHES "^[Rr]elease")
    # first we can indicate the documentation build as an option and set it to ON by default
    option(BUILD_DOC "Build documentation" ON)

    # check if Doxygen is installed
    find_package(Doxygen
                REQUIRED dot
                OPTIONAL_COMPONENTS mscgen dia)
    if (DOXYGEN_FOUND)
        # set input and output files
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/../Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
        
        # request to configure the file
        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
        message("Doxygen will build HTML sources when generated")

        # note the option ALL which allows to build the docs together with the application
        add_custom_target( doc ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
    else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
    endif (DOXYGEN_FOUND)
endif()

############################################################
# Access boost libraries
############################################################
set(Boost_INCLUDE_DIR "/opt/lib/include" CACHE PATH " Boost header file directory ")
set(Boost_LIBRARY_DIR "/opt/lib/lib" CACHE PATH " boost libraries directory ")
# find a boost install with the libraries filesystem and system
find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)

# check if boost was found
if(Boost_FOUND)
    message ("boost found")
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()

# Add an executable
# add_executable(imported_targets main.cpp)

# link against the boost libraries
#target_link_libraries( imported_targets PRIVATE  Boost::filesystem)

############################################################
# Access LLVM Support system
############################################################
# Add the binary and sources to the executable code
add_executable(
  parser
  main.cc
)

target_link_libraries(parser parse)

install(TARGETS parser
    RUNTIME DESTINATION bin
    )
# Library
# Note: may not work on windows
install (TARGETS parse
    ARCHIVE DESTINATION lib)