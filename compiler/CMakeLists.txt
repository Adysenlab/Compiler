
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