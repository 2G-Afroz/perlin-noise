# Required Version and Project name
cmake_minimum_required(VERSION 3.2)
project(perlin-noise VERSION 1.0)
			
# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
			
# Adding libray fiels using file(GLOB ...)
file(
	GLOB
	RAYLIB_L
	"${CMAKE_SOURCE_DIR}/lib/*.a"
)
			
# Add source files using file(GLOB ...)
file(
	GLOB
	SOURCES 
	"${CMAKE_SOURCE_DIR}/src/*.cpp" 
	"${CMAKE_SOURCE_DIR}/utils/*.cpp" 
	"${CMAKE_SOURCE_DIR}/main.cpp"
)
			
# Include headers from /usr/local/include (raylib.h)
include_directories("/usr/local/include")
			
# Copy assets directory to build directory
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
			
# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})
			
target_link_libraries(
	${PROJECT_NAME} PRIVATE
	"${RAYLIB_L}"
	"-framework Cocoa"
	"-framework IOKit"
)
