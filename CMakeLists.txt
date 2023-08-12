cmake_minimum_required(VERSION 3.12)
project(SmartGraph VERSION 1.0.0)

# Define your library name
set(LIBRARY_NAME smartgraph)

# Define your library sources
file(GLOB_RECURSE LIBRARY_SOURCES src/*.cpp)

# Create the static library
add_library(${LIBRARY_NAME} SHARED ${LIBRARY_SOURCES})

# Set include directories for your library
target_include_directories(${LIBRARY_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Install targets
install(TARGETS ${LIBRARY_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

# Install header files
install(DIRECTORY include/ DESTINATION include)

add_executable(TestUnorientedGraph test/test_unoriented_graph.cpp)
target_link_libraries(TestUnorientedGraph ${LIBRARY_NAME})

add_executable(TestDijkstra test/test_dijkstra.cpp)
target_link_libraries(TestDijkstra ${LIBRARY_NAME})