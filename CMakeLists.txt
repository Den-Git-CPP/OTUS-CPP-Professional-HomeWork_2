cmake_minimum_required(VERSION 3.15)

project(IPFilter VERSION 0.0.1)

configure_file(version.h.in version.h)

add_executable(IPFilter_cli 
main_IPFilter.cpp 
IPElem.cpp 
IPFilter.cpp)

set_target_properties(IPFilter_cli 
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(IPFilter_cli
    PRIVATE 
    "${CMAKE_BINARY_DIR}"
)

if (MSVC)
    target_compile_options(IPFilter_cli 
        PRIVATE
        /EHsc /W4 /WX
    )
 
else ()
    target_compile_options(IPFilter_cli 
        PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
 
endif()

file(COPY ip_filter.tsv DESTINATION  ${CMAKE_BINARY_DIR})

