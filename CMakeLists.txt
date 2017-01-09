################################################################################
project( "Rapidcheck-csv" C CXX )

cmake_minimum_required( VERSION 2.8.3 )

set( CMAKE_ECLIPSE_VERSION 3.8 )
set( _ECLIPSE_VERSION 3.8 )


add_definitions( -O2 -unroll-loops -Wall -pedantic -mmmx -msse -msse2 -msse3 -s -pipe -Wno-sign-compare -march=native )


################################################################################

find_package( Boost REQUIRED )

################################################################################

include_directories(
    ${Boost_INCLUDE_DIR}
)

################################################################################


add_executable( main
    src/main.cpp
    src/parse_csv.cpp
)

add_subdirectory( rapidcheck )

target_link_libraries( main rapidcheck )

################################################################################
