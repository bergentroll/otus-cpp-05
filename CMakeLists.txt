cmake_minimum_required(VERSION 3.12.4)

if($ENV{TRAVIS_BUILD_NUMBER})
  set(VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
  set(VERSION 0.0.0)
endif()
project(editor_model VERSION ${VERSION})

set(CMAKE_CXX_STANDARD 17)

### Dependencies ##############################################################

set(SRC_PATH "src/")
set(TEST_PATH "test/")
include_directories("inc/")

find_package(Doxygen COMPONENTS dot)

### Main targets ##############################################################

add_executable(tintenschaft ${SRC_PATH}/main.cpp)

### Documentation #############################################################

if(DOXYGEN_FOUND)
  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    @ONLY)
  add_custom_target(
    html
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Creating HTML documentation with Doxygen" VERBATIM)
endif()

### Packing ###################################################################

install(TARGETS tintenschaft RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_CONTACT bergentroll@insiberia.net)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)
