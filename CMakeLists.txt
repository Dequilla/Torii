cmake_minimum_required(VERSION 3.1)

# Definitions (PATHS, NAMES etc)
set(PROJ_NAME WebCPP)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Source files
file(GLOB_RECURSE SOURCES 
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "${PROJECT_SOURCE_DIR}/*.c"
) 

message("Dir: ${PROJECT_SOURCE_DIR}")
message("Src: ${SOURCES}")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Setup project
project(${PROJ_NAME} VERSION 1.0)

# add the executable
add_executable(${PROJ_NAME} ${SOURCES})
target_include_directories(${PROJ_NAME} PUBLIC ${INC_DIR})

# Make it output to a standard location
set_target_properties( ${PROJ_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)

if(UNIX)
    add_definitions(-D__UNIX__)
elseif(WIN32)
    add_definitions(-D__WIN32__)
endif()