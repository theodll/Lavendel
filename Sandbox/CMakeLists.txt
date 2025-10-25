
file(GLOB_RECURSE SANDBOX_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

add_executable(Sandbox ${SANDBOX_SOURCES})


target_include_directories(Sandbox PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/Lumen/src
    ${CMAKE_SOURCE_DIR}/Lumen/include
)

target_link_libraries(Sandbox PRIVATE Lumen)

set_target_properties(Sandbox PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>"
)

target_include_directories(Sandbox
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/ 
)