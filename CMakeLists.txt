cmake_minimum_required(VERSION 3.12)
project(SmartGraph VERSION 1.0.0)

# Define your library name
set(LIBRARY_NAME SmartGraph)

# Define your library sources
file(GLOB_RECURSE LIBRARY_SOURCES src/*.cpp)

# Create the static library
add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES})

# Set include directories for your library
target_include_directories(${LIBRARY_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Install targets
install(TARGETS ${LIBRARY_NAME}
    ARCHIVE DESTINATION lib
)

# Install header files
install(DIRECTORY include/ DESTINATION include)

# Create an export file for other projects to import your library
install(EXPORT ${LIBRARY_NAME}Targets
    FILE ${LIBRARY_NAME}Targets.cmake
    NAMESPACE ${LIBRARY_NAME}::
    DESTINATION lib/cmake/${LIBRARY_NAME}
)

# Include CMakePackageConfigHelpers to generate version and config files
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

# Generate the config file
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}Config.cmake
    INSTALL_DESTINATION lib/cmake/${LIBRARY_NAME}
)

# Install the config and version files
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}ConfigVersion.cmake
    DESTINATION lib/cmake/${LIBRARY_NAME}
)