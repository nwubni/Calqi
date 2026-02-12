cmake_minimum_required(VERSION 3.10)
project(Calqi VERSION 1.0.1 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all source files from src/ and subdirectories
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create executable
add_executable(calqi ${SOURCES})

# Add include directories so headers can be found
target_include_directories(calqi PRIVATE src)

# Link libraries (readline and math)
target_link_libraries(calqi readline m)

# Installation rules
install(TARGETS calqi DESTINATION bin)

install(FILES docs/calqi.1 DESTINATION share/man/man1)

# Optional: Install documentation
if(EXISTS "${CMAKE_SOURCE_DIR}/README.md")
    install(FILES README.md DESTINATION share/doc/calqi)
endif()

# CPack configuration for creating .deb package
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "calqi")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_FILE_NAME "calqi-v1-01")
set(CPACK_PACKAGE_CONTACT "nwubni@gmail.com")  # CHANGE THIS
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Nakuru Wubni <nwubni@gmail.com>")  # CHANGE THIS
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Scientific calculator for terminal")
set(CPACK_PACKAGE_DESCRIPTION "A fast, terminal-based scientific calculator with support for mathematical functions, precedence handling, and interactive mode with history.")
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libreadline8")

# Determine architecture
if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64")
    set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|arm64")
    set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "arm64")
else()
    set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "all")
endif()

include(CPack)