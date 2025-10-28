
file(GLOB_RECURSE ENGINE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
)

add_library(Lumen SHARED ${ENGINE_SOURCES})


target_include_directories(Lumen PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(Lumen PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/$<CONFIG>"
)

target_compile_definitions(Lumen PRIVATE
    $<$<CONFIG:Debug>:LM_DEBUG>
    $<$<CONFIG:Release>:LM_RELEASE>
    $<$<CONFIG:Dist>:LM_DIST>
)

if(WIN32)
    target_compile_definitions(Lumen PRIVATE LM_BUILD_DLL)
endif()

target_include_directories(Lumen
    PRIVATE
        ${CMAKE_SOURCE_DIR}/vendor/spdlog/include/
        ${CMAKE_SOURCE_DIR}Lumen/src/ 
)